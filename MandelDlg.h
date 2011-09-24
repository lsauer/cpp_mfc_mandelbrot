#if !defined(AFX_MANDELDLG_H__265A6720_3D3B_11D3_8C90_00C0A84035A6__INCLUDED_)
#define AFX_MANDELDLG_H__265A6720_3D3B_11D3_8C90_00C0A84035A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MandelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMandelDlg dialog

class CMandelDlg : public CDialog
{
// Construction
public:
	CMandelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMandelDlg)
	enum { IDD = IDD_AUSSCHNITT };
	UINT	m_nMaxIter;
	double	m_dXStart;
	double	m_dXEnd;
	double	m_dYStart;
	double	m_dYEnd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMandelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMandelDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANDELDLG_H__265A6720_3D3B_11D3_8C90_00C0A84035A6__INCLUDED_)
