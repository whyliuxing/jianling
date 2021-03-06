// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__C3EF42C6_EAB7_4057_ACC3_F632B199F2AF__INCLUDED_)
#define AFX_STDAFX_H__C3EF42C6_EAB7_4057_ACC3_F632B199F2AF__INCLUDED_


#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#define _WIN32_WINNT 0x601
#define WINVER	0x601


//关闭调试长度警告
#pragma warning(disable: 4786)



#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxcview.h>
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>
#include <afxdb.h>
#include <afxmt.h>
#include <atlconv.h>


#include <string>
#include <list>
#include <vector>
#include <map>

#include <DbgHelp.h>
#pragma comment(lib, "dbghelp")


#include "..\common\common.h"
#include "..\common\protocol.h"
#include "..\common\Lock.h"

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__C3EF42C6_EAB7_4057_ACC3_F632B199F2AF__INCLUDED_)
