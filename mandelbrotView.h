// mandelbrotView.h : interface of the CMandelbrotView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANDELBROTVIEW_H__D8EAEA2E_3C84_11D3_8C90_00C0A84035A6__INCLUDED_)
#define AFX_MANDELBROTVIEW_H__D8EAEA2E_3C84_11D3_8C90_00C0A84035A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMandelbrotView : public CView
{
private:
	mandel_iterC(double x, double y, int maxiter);
	CStatusBar * m_pStatusBar;
protected: // create from serialization only
	CMandelbrotView();
	DECLARE_DYNCREATE(CMandelbrotView)

// Attributes
public:
	CMandelbrotDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMandelbrotView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMandelbrotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMandelbrotView)
	afx_msg void OnFarbig();
	afx_msg void OnSchwarzweiss();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mandelbrotView.cpp
inline CMandelbrotDoc* CMandelbrotView::GetDocument()
   { return (CMandelbrotDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANDELBROTVIEW_H__D8EAEA2E_3C84_11D3_8C90_00C0A84035A6__INCLUDED_)
