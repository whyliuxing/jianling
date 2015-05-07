#if !defined(AFX_STATUSBOX_H__F8E49461_D835_4A1B_8F8A_EF8803AFE3AB__INCLUDED_)
#define AFX_STATUSBOX_H__F8E49461_D835_4A1B_8F8A_EF8803AFE3AB__INCLUDED_


/////////////////////////////////////////////////////////////////////////////
// CStatusBox dialog

class CStatusBox : public CDialog
{
// Construction
public:
    CStatusBox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CStatusBox)
    enum { IDD = IDD_STATUSBOX };
    //}}AFX_DATA


    void SetMsg(TCHAR szMsg[]);
// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CStatusBox)
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
    virtual BOOL OnInitDialog();
    //}}AFX_VIRTUAL

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(CStatusBox)
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSBOX_H__F8E49461_D835_4A1B_8F8A_EF8803AFE3AB__INCLUDED_)
