// mandelbrotDoc.cpp : implementation of the CMandelbrotDoc class
//

#include "stdafx.h"
#include "mandelbrot.h"

#include "mandelbrotDoc.h"
#include "mandeldlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotDoc

IMPLEMENT_DYNCREATE(CMandelbrotDoc, CDocument)

BEGIN_MESSAGE_MAP(CMandelbrotDoc, CDocument)
	//{{AFX_MSG_MAP(CMandelbrotDoc)
	ON_COMMAND(ID_AUSSCHNITT, OnAusschnitt)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotDoc construction/destruction

CMandelbrotDoc::CMandelbrotDoc()
{
	// TODO: add one-time construction code here
	m_dXStart    = -2;
	m_dXEnd      =  2;
	m_dYStart    = -2;
	m_dYEnd      =  2;
	m_nMaxIter   = 30;
	m_nColorMode = 0;
}

CMandelbrotDoc::~CMandelbrotDoc()
{
}

BOOL CMandelbrotDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMandelbrotDoc serialization

void CMandelbrotDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_dXStart;
		ar << m_dXEnd;
		ar << m_dYStart;
		ar << m_dYEnd;
		ar << m_nMaxIter;
		ar << m_nColorMode;
	}
	else
	{
		// TODO: add loading code here
		ar >> m_dXStart;
		ar >> m_dXEnd;
		ar >> m_dYStart;
		ar >> m_dYEnd;
		ar >> m_nMaxIter;
		ar >> m_nColorMode;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotDoc diagnostics

#ifdef _DEBUG
void CMandelbrotDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMandelbrotDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotDoc commands
void CMandelbrotDoc::setXStartPosition(double value)
{
	m_dXStart = value;
}

void CMandelbrotDoc::setYStartPosition(double value)
{
	m_dYStart = value;
}

void CMandelbrotDoc::setXEndPosition(double value)
{
	m_dXEnd = value;
}

void CMandelbrotDoc::setYEndPosition(double value)
{
	m_dYEnd = value;
}

bool CMandelbrotDoc::setColorMode(int mode)
{
	if (m_nColorMode != mode)
	{
		m_nColorMode = mode;
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

double CMandelbrotDoc::getXEndPosition()
{
	return m_dXEnd;
}

double CMandelbrotDoc::getXStartPosition()
{
	return m_dXStart;
}

double CMandelbrotDoc::getYEndPosition()
{
	return m_dYEnd;
}

double CMandelbrotDoc::getYStartPosition()
{
	return m_dYStart;
}

int CMandelbrotDoc::getMaxIter()
{
	return m_nMaxIter;
}

bool CMandelbrotDoc::inColorMode()
{
	if (m_nColorMode)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

void CMandelbrotDoc::resetAllValues()
{
	m_dXStart	 = -2;
	m_dYStart	 = -2;
	m_dXEnd	     = 2;
	m_dYEnd		 = 2;
	m_nMaxIter	 = 30;
	m_nColorMode = 0;
}

void CMandelbrotDoc::OnAusschnitt() 
{
	// TODO: Add your command handler code here

	// initialisiere Dialog
	CMandelDlg mandelDlg;
	mandelDlg.m_dXStart = m_dXStart;
	mandelDlg.m_dXEnd = m_dXEnd;
	mandelDlg.m_dYStart = m_dYStart;
	mandelDlg.m_dYEnd = m_dYEnd;
	mandelDlg.m_nMaxIter = m_nMaxIter;

	// wurde der Dialog mit OK beendet?
	if (IDOK==mandelDlg.DoModal())
	{
		// sichere die Daten des Dialogs
		m_dXStart = mandelDlg.m_dXStart;
		m_dYStart = mandelDlg.m_dYStart;
		m_dXEnd   = mandelDlg.m_dXEnd;
		m_dYEnd   = mandelDlg.m_dYEnd;
		m_nMaxIter = mandelDlg.m_nMaxIter;

		// aktualisiere die Ansicht
		UpdateAllViews (NULL);

		// markiere das Dokument als verändert
		SetModifiedFlag();
	};
}
