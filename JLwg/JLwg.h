#ifndef _JLWG_H_
#define _JLWG_H_

#ifndef __AFXWIN_H__
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

#include "LuaScript.h"

class CJLDlg;
class CJLwgApp: public CWinApp
{
public:
    CJLwgApp();
    ~CJLwgApp();


    //外挂线程
    static DWORD CALLBACK WgThread(LPVOID pParam);
    static LRESULT CALLBACK GameMsgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    //等待游戏窗口创建
    BOOL WaitGameCreate(int inMaxTime);
    void UnLoad();

    //通信
    PIPEDATA m_stData;
    HANDLE m_hPipe;
    void SendStatus(TCHAR szText[]);

    
    //调试时关掉
    BOOL InitPipe();
    BOOL InitLog();
    
    //脚本
    LuaScript m_lua;

    static HWND m_hGameWnd;

private:
    static WNDPROC wpOrigGameProc;
    static CJLDlg* m_pWgDlg;



// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CJLwgApp)
    virtual BOOL InitInstance();
    virtual int ExitInstance();
    //}}AFX_VIRTUAL

};

extern CJLwgApp theApp;

#define SENDLOG theApp.SendStatus

#endif