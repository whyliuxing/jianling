#include "stdafx.h"
#include "JLwg.h"
#include "TaskScript.h"
#include "GamecallEx.h"
#include "GameConfig.h"
#include "GameLog.h"



//程序实例唯一
CJLwgApp theApp;


//静态变量
WNDPROC CJLwgApp::wpOrigGameProc = NULL;
CJLDlg* CJLwgApp::m_pWgDlg = NULL;
HWND CJLwgApp::m_hGameWnd = NULL;




CJLwgApp::CJLwgApp()
{
    m_hPipe = INVALID_HANDLE_VALUE;
}

CJLwgApp::~CJLwgApp()
{
}


//钩游戏的消息窗口
LRESULT CALLBACK CJLwgApp::GameMsgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if(CJLwgApp::m_pWgDlg == NULL)
    {
        return CallWindowProc(wpOrigGameProc, hwnd, uMsg, wParam, lParam);
    }


    //调出外挂
    switch(uMsg)
    {

        case WM_KEYDOWN:
        {

            if(wParam == VK_INSERT)
            {
                int result = MessageBox(hwnd, _T("你按下了 VK_INSERT 按键.\n确认执行任务?"), NULL, MB_OKCANCEL);
                if(result == IDOK)
                {
                    m_pWgDlg->OnGotask();
                }

            }
            else if(wParam == VK_DELETE)
            {
                m_pWgDlg->OnStopTask();
            }

            else if(wParam == VK_END)
            {
                int style = GetWindowLong(hwnd, GWL_STYLE);
                ::SetWindowLong(hwnd, GWL_STYLE, style | WS_CLIPCHILDREN);


                if(m_pWgDlg->IsWindowVisible())
                {
                    m_pWgDlg->ShowWindow(SW_HIDE);
                }
                else
                {
                    m_pWgDlg->ShowWindow(SW_SHOWNA);
                }

            }
            break;
        }



        case WM_CUSTOM_GCALL:
        {
            //获取游戏外挂功能
            GamecallEx* pcall = GamecallEx::GetInstance();

            //此处实现游戏call的调用
            return pcall->call((DWORD)wParam, (LPVOID*)lParam);
        }

    }

    return CallWindowProc(wpOrigGameProc, hwnd, uMsg, wParam, lParam);
}


DWORD CALLBACK CJLwgApp::WgThread(LPVOID pParam)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState())

    if(!AfxSocketInit())
    {
        LOGER(_T("套接字初始化失败"));
        ExitProcess(0);
        return FALSE;
    }

    if(!theApp.WaitGameCreate(20))
    {
        LOGER(_T("等待游戏窗口超时"));
        ExitProcess(0);
        return FALSE;
    }
    else
    {
        LOGER(_T("游戏窗口创建"));
    }


    LOGER(_T("初始化加速"));
    GameSpend* pGameSpender = GameSpend::GetInstance();
    if(!pGameSpender->Init())
    {
        ExitProcess(0);
        return FALSE;
    }


    LOGER(_T("加载配置"));
    GameConfig* pConfig = GameConfig::GetInstance();
    pConfig->LoadConfig();


    //初始化
    GamecallEx* pCall = GamecallEx::GetInstance();

//     LOGER(_T("初始化外挂功能"));
//     if(!pCall->Init())
//     {
//         ExitProcess(0);
//         return FALSE;
//     }


    //改游戏窗口处理过程
    wpOrigGameProc = (WNDPROC)::SetWindowLong(m_hGameWnd, GWL_WNDPROC, (LONG)GameMsgProc);

    //通信数据
    PIPEDATA& data = theApp.m_stData;
    ::SetWindowText(m_hGameWnd, data.szAccount);


    SENDLOG(_T("对话框启动了"));

    //创建外挂对话框
    m_pWgDlg = new CJLDlg;
    m_pWgDlg->DoModal();

    FreeLibraryAndExitThread(theApp.m_hInstance, 0);
    return 0;
}



//判断游戏窗口是否创建
HWND CJLwgApp::isGameWndCreated(DWORD dwPid)
{
    HWND hGameWnd = FindWindowEx(NULL, NULL, _T("LaunchUnrealUWindowsClient"), NULL);

    if(hGameWnd == NULL) return NULL;

    //判断游戏窗口创建完成
    for(;;)
    {
        DWORD dwWndOfPid;
        GetWindowThreadProcessId(hGameWnd, &dwWndOfPid);

        //找到
        if(dwPid == dwWndOfPid)
        {
            m_hGameWnd = hGameWnd;
            return hGameWnd;
        }

        hGameWnd = FindWindowEx(NULL, hGameWnd, _T("LaunchUnrealUWindowsClient"), NULL);
        if(hGameWnd == NULL) return NULL;
    }
}



BOOL CJLwgApp::WaitGameCreate(int inMaxTime)
{

    //判断当前游戏的窗口是否创建
    for(int i = 0; i < inMaxTime; i++)
    {
        if(isGameWndCreated(GetCurrentProcessId()) != NULL) return TRUE;
        Sleep(1000);
    }

    return FALSE;
}

BOOL CJLwgApp::InitInstance()
{

    //设置区域
    setlocale(LC_ALL, "chs");

    //1, 获取通信数据
    TCHAR szPipe[MAX_PATH];
    wsprintf(szPipe, _T("\\\\.\\Pipe\\JLwg_%d"), GetCurrentProcessId());
    if(!::WaitNamedPipe(szPipe, NMPWAIT_USE_DEFAULT_WAIT))
    {
        TRACE(_T("can't find pipe!"));
        return FALSE;
    }

    // 打开管道
    m_hPipe = CreateFile(szPipe, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL) ;
    if(m_hPipe == INVALID_HANDLE_VALUE)
    {
        TRACE(_T("can't open console pipe!")) ;
        ExitProcess(0);
        return FALSE;
    }

    //读取数据
    DWORD dwBytesReaded = 0;
    if(!ReadFile(m_hPipe, &m_stData, sizeof(PIPEDATA), &dwBytesReaded, NULL))
    {
        TRACE(_T("can't read pipe data!"));
        ExitProcess(0);
        return FALSE;
    }

    //设置成不等待模式
    DWORD dwMode = PIPE_NOWAIT | PIPE_READMODE_MESSAGE;
    SetNamedPipeHandleState(m_hPipe, &dwMode, NULL, NULL);


    //2, 初始化日志
    TCHAR szLogPath[MAX_PATH];
    GetModuleFileName(AfxGetInstanceHandle(), szLogPath, MAX_PATH);
    PathRemoveFileSpec(szLogPath);
    PathAppend(szLogPath, _T("日志"));
    if(!PathFileExists(szLogPath))
    {
        //创建日志目录
        _tmkdir(szLogPath);
    }

    PathAppend(szLogPath, m_stData.szAccount);
    _tcscat(szLogPath, _T(".txt"));


    GameLog* pLog = GameLog::GetInstance();
    if(!pLog->open(szLogPath))
    {
        TRACE(_T("can't open log file!"));
        ExitProcess(0);
        return FALSE;
    }

    //至此日志能
    LOGER(_T("#外挂启动"));

    //外挂线程
    HANDLE hwgThread = ::CreateThread(NULL, 0, WgThread, this, 0, 0);
    if(hwgThread == NULL)
    {
        LOGER(_T("主线程创建失败"));
        ExitProcess(0);
        return FALSE;
    }

    CloseHandle(hwgThread);
    return TRUE;
}


void CJLwgApp::SendStatus(TCHAR szText[])
{
    PIPESTATUS status;
    status.dwPid = m_stData.dwPid;
    status.dwItem = m_stData.dwItem;
    _tcsncpy(status.szStatus, szText, _tcslen(szText) + 1);

    DWORD dwWriten;
    WriteFile(m_hPipe, &status, sizeof(PIPESTATUS), &dwWriten, NULL);
}


int CJLwgApp::ExitInstance()
{
    LOGER(_T("外挂正常退出"));
    SENDLOG(_T("外挂被卸载了"));

    if(m_hPipe != INVALID_HANDLE_VALUE)
    {
        CloseHandle(m_hPipe);
    }


    if(wpOrigGameProc)
    {
        ::SetWindowLong(m_hGameWnd, GWL_WNDPROC, (LONG)wpOrigGameProc);
    }

    if(m_pWgDlg)
    {
        if(::IsWindow(m_pWgDlg->m_hWnd))
        {
            m_pWgDlg->EndDialog(IDOK);
        }

        delete m_pWgDlg;
    }


    //保存配置
    GameConfig* pConfig = GameConfig::GetInstance();
    pConfig->SaveConfig();


    return CWinApp::ExitInstance();
}
