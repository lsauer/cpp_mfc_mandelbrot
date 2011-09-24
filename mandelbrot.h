// mandelbrot.h : main header file for the MANDELBROT application
//

#if !defined(AFX_MANDELBROT_H__D8EAEA24_3C84_11D3_8C90_00C0A84035A6__INCLUDED_)
#define AFX_MANDELBROT_H__D8EAEA24_3C84_11D3_8C90_00C0A84035A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotApp:
// See mandelbrot.cpp for the implementation of this class
//

class CMandelbrotApp : public CWinApp
{
public:
	CMandelbrotApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMandelbrotApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMandelbrotApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANDELBROT_H__D8EAEA24_3C84_11D3_8C90_00C0A84035A6__INCLUDED_)
