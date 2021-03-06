// JLSrvrView.h : interface of the CJLSrvrView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JLSRVRVIEW_H__B0A33F75_AC46_48D9_8A49_98C434B57456__INCLUDED_)
#define AFX_JLSRVRVIEW_H__B0A33F75_AC46_48D9_8A49_98C434B57456__INCLUDED_

#if _MSC_VER > 1000
    #pragma once
#endif // _MSC_VER > 1000


class CJLSrvrDoc;
class CJLSrvrView : public CListView
{
protected: // create from serialization only
    CJLSrvrView();
    DECLARE_DYNCREATE(CJLSrvrView)

// Attributes
public:
    CJLSrvrDoc* GetDocument(){return (CJLSrvrDoc*)m_pDocument;}

// Operations
public:
    void AutoColumnWidth();
    void DoPopupMenu(int type);

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CJLSrvrView)
public:
    virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
    virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CJLSrvrView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    //{{AFX_MSG(CJLSrvrView)
    afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JLSRVRVIEW_H__B0A33F75_AC46_48D9_8A49_98C434B57456__INCLUDED_)
