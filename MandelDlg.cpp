// MandelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mandelbrot.h"
#include "MandelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMandelDlg dialog


CMandelDlg::CMandelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMandelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMandelDlg)
	m_nMaxIter = 0;
	m_dXStart = 0.0;
	m_dXEnd = 0.0;
	m_dYStart = 0.0;
	m_dYEnd = 0.0;
	//}}AFX_DATA_INIT
}


void CMandelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMandelDlg)
	DDX_Text(pDX, IDC_MAXITER, m_nMaxIter);
	DDV_MinMaxUInt(pDX, m_nMaxIter, 1, 100);
	DDX_Text(pDX, IDC_X1, m_dXStart);
	DDV_MinMaxDouble(pDX, m_dXStart, -10., 10.);
	DDX_Text(pDX, IDC_X2, m_dXEnd);
	DDV_MinMaxDouble(pDX, m_dXEnd, -10., 10.);
	DDX_Text(pDX, IDC_Y1, m_dYStart);
	DDV_MinMaxDouble(pDX, m_dYStart, -10., 10.);
	DDX_Text(pDX, IDC_Y2, m_dYEnd);
	DDV_MinMaxDouble(pDX, m_dYEnd, -10., 10.);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMandelDlg, CDialog)
	//{{AFX_MSG_MAP(CMandelDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMandelDlg message handlers
