// ConfigMgr.cpp: implementation of the CConfigMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JLkit.h"
#include "ConfigMgr.h"

#ifdef _DEBUG
    #define new DEBUG_NEW
#endif


IMPLEMENT_SINGLETON(CConfigMgr)

//���캯��
CConfigMgr::CConfigMgr()
{
}

CConfigMgr::~CConfigMgr()
{

}

BOOL CConfigMgr::LoadConfig(const TCHAR szConfigPath[])
{

    VERIFY(PathFileExists(szConfigPath) == TRUE);

    if(LoadFile(szConfigPath) < 0)
    {
        AfxMessageBox(_T("���������ļ�ʧ��"));
        return FALSE;
    }


    try
    {
        //����ֵ
        m_Update = GetLongValue(_T("����"), _T("����"), true);
        m_KeepPw = GetLongValue(_T("����"), _T("��ס����"), 0);
        m_szFileName = GetValue(_T("����"), _T("�ʺ��ļ�"), _T(""));
        m_szAccountName =  GetValue(_T("����"),  _T("�û���"), _T(""));
        m_szAccountPw = GetValue(_T("����"), _T("����"), _T(""));
        m_szGameConfig = GetValue(_T("����"), _T("��Ϸ����"), _T(""));
        m_szGameScript = GetValue(_T("����"), _T("��Ϸ�ű�"), _T(""));

        //ȡ����Ϸ·��
        CRegKey reg;
        TCHAR szValue[MAX_PATH];

#ifdef JLTW
        TCHAR temp1[] = _T("SOFTWARE\\Wow6432Node\\NCTaiwan");
        TCHAR temp2[] = _T("TWBNS22");
#else
        TCHAR temp1[] = _T("SOFTWARE\\Wow6432Node\\plaync\\BNS_KOR");
        TCHAR temp2[] = _T("BaseDir");
#endif

        if(reg.Open(HKEY_LOCAL_MACHINE, temp1) == ERROR_SUCCESS)
        {
            DWORD sizeValue = MAX_PATH;
            if(reg.QueryValue(szValue, temp2, &sizeValue) == ERROR_SUCCESS)
            {
                _tcscat(szValue, _T("\\bin\\Client.exe"));
            }
        }

        const TCHAR* pszGamePathValue = GetValue(_T("����"), _T("��Ϸ·��"), szValue);
        if(pszGamePathValue[0] == '\0')
        {
            m_szGamePath = szValue;
        }
        else
        {
            m_szGamePath = pszGamePathValue;
        }

    }
    catch(...)
    {

        return FALSE;
    }

    return TRUE;
}


void CConfigMgr::SaveConfig(const TCHAR szConfigPath[])
{
    //��������
    SetLongValue(_T("����"), _T("��ס����"), m_KeepPw);
    SetLongValue(_T("����"), _T("����"), m_Update);
    SetValue(_T("����"), _T("�ʺ��ļ�"), m_szFileName.c_str());
    SetValue(_T("����"), _T("�û���"), m_szAccountName.c_str());
    SetValue(_T("����"), _T("����"), m_szAccountPw.c_str());
    SetValue(_T("����"), _T("��Ϸ·��"), m_szGamePath.c_str());
    SetValue(_T("����"), _T("��Ϸ����"), m_szGameConfig.c_str());
    SetValue(_T("����"), _T("��Ϸ�ű�"), m_szGameScript.c_str());

    if(szConfigPath[0] != _T('\0'))
        SaveFile(szConfigPath);
}