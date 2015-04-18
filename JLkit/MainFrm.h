#if !defined _MAINFRM_H_
#define _MAINFRM_H_


class CMainFrame : public CFrameWnd
{
public:
    CMainFrame();
    virtual ~CMainFrame();
    DECLARE_DYNCREATE(CMainFrame)


    void InitComBox();

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMainFrame)
protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL

public:
    CComboBox m_cbConfig;
    CComboBox m_cbScript;

protected:  // control bar embedded members
    CStatusBar  m_wndStatusBar;
    CToolBar m_wndToolBar;
    // Generated message map functions
protected:
    //{{AFX_MSG(CMainFrame)
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnClose();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

#endif
