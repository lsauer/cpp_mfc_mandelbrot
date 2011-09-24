// mandelbrotView.cpp : implementation of the CMandelbrotView class
//

#include "stdafx.h"
#include "mandelbrot.h"

#include "mandelbrotDoc.h"
#include "mandelbrotView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView

IMPLEMENT_DYNCREATE(CMandelbrotView, CView)

BEGIN_MESSAGE_MAP(CMandelbrotView, CView)
	//{{AFX_MSG_MAP(CMandelbrotView)
	ON_COMMAND(ID_FARBIG, OnFarbig)
	ON_COMMAND(ID_SCHWARZWEISS, OnSchwarzweiss)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView construction/destruction

CMandelbrotView::CMandelbrotView()
{
	// TODO: add construction code here

}

CMandelbrotView::~CMandelbrotView()
{
}

BOOL CMandelbrotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView drawing

void CMandelbrotView::OnDraw(CDC* pDC)
{
	// Zugriff auf das Dokument erlangen
	CMandelbrotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

	// Erzeuge Stift und speichere den bisher aktuellen
	CPen plotPen(PS_SOLID,1, RGB(0,0,0));
	CPen *pOldPen = pDC->SelectObject(&plotPen);

	// initialisiere temporäre Variablen
	long double dx, dy, x, y;
	int anzahl_gitterpunkte, iterationswert, aufloesung;
	int farbvorberechnung = (255 / pDoc->getMaxIter());
	POINT bildposition;
	CRect clientRect;
	GetClientRect(clientRect);

	// ermittle die zu verwendene Auflösung
	aufloesung = (clientRect.Width() > clientRect.Height()) ? clientRect.Width() 
															: clientRect.Height();

	// Anzahl der zu berechnenden Punkte ist Auflösung + 1
	anzahl_gitterpunkte = aufloesung+1;

	// berechne Wertebereich eines Pixels
	dx = (pDoc->getXEndPosition()-pDoc->getXStartPosition()) / long double(aufloesung);
	dy = (pDoc->getYEndPosition()-pDoc->getYStartPosition()) / long double(aufloesung);

	// setze die Y-Werte auf START
	y = pDoc->getYStartPosition();
	bildposition.y = 1;

	// bearbeite alle Zeilen
	while (bildposition.y <= anzahl_gitterpunkte)
	{
		// setze die X-Werte auf START
		x = pDoc->getXStartPosition();
		bildposition.x = 1;
  
	  // bearbeite jeden Pixel der Zeile
      while (bildposition.x <= anzahl_gitterpunkte)
	  {
		  // berechne den Iterationswert
          iterationswert = mandel_iterC(x,y,pDoc->getMaxIter());

		  // wurde die Iterationsgrenze überschritten?
          if (iterationswert >= pDoc->getMaxIter()) 
		  {
			  // ja, zeichne einen schwarzen Punkt
			  pDC->SetPixel(bildposition, RGB(0,0,0));
		  }
		  else
		  {
			  // befinden wir uns im Farbmodus?
			  if (pDoc->inColorMode())
			  {
				  // ja, zeichne einen passenden farbigen Punkt
					int farbe = 255 - (farbvorberechnung * iterationswert);
					pDC->SetPixel(bildposition, RGB(255,farbe,farbe));
			  }
		  }

		  // rücke zum nächsten Pixel vor
          x += dx;
          bildposition.x += 1;
      }

	  // rücke zur nächsten Zeile vor
      y += dy;
      bildposition.y += 1;
	}	

	// setze den Stift auf den Ausgangsstift zurück
	pDC->SelectObject(&pOldPen);
}

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView printing

BOOL CMandelbrotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMandelbrotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMandelbrotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView diagnostics

#ifdef _DEBUG
void CMandelbrotView::AssertValid() const
{
	CView::AssertValid();
}

void CMandelbrotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMandelbrotDoc* CMandelbrotView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMandelbrotDoc)));
	return (CMandelbrotDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView message handlers
// --------------------------------------------------------------------------------------------------------
// CDrawItView::mandel_iterC
// --------------------------------------------------------------------------------------------------------
// Parameter : 	double x, y = Position in der Gauss'schen Ebene
//				int maxiter = die maximale Anzahl von durchzuführenden Iterationen
// --------------------------------------------------------------------------------------------------------
// mandel_iterC() führt die eigentliche Mandelbrotberechnung durch und gibt die Anzahl der 
// durchgeführten Iterationen zurück
// --------------------------------------------------------------------------------------------------------
// Rückgabewert : int i = Anzahl der Iterationsschritte
// --------------------------------------------------------------------------------------------------------

int CMandelbrotView::mandel_iterC (double x, double y, int maxiter)
{
	// initialisiere temporäre Variablen
	double sx, sy, zx, zy;
	int i;

	zx = x;
	zy = y;
	sx = zx * zx;
	sy = zy * zy;
	i = 0;

	// führe Iterationen durch
	while ((i <= maxiter) && (sx+sy<=4.0))
	{
		zy = (zx+zx)*zy + y;
		zx = sx - sy + x;
		sx = zx * zx;
		sy = zy * zy;
		i = i+1;
	}	

	// Gebe Anzahl der Iterationsschritte zurück
	return (i);
}

void CMandelbrotView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	// initialisiere temporäre Variablen
	CRect clientRect;
	int aufloesung;

	// das folgende nur ausführen, wenn nicht gedruckt werden soll
	if (!pDC->IsPrinting())
	{
		// Rechteck des Client-Bereichs speichern
		GetClientRect(clientRect);

		// Skalierung der Abbildung auf anisotrophisch stellen
		pDC->SetMapMode(MM_ANISOTROPIC);
		
		// Auflösung berechnen
		aufloesung = (clientRect.Width() > clientRect.Height()) ? clientRect.Width() 
																: clientRect.Height();

		// Lege Größe der Zeichenfläche fest
		pDC->SetWindowExt(aufloesung, aufloesung);

		// Lege Ursprungskoordinate 0,0 fest
		pDC->SetWindowOrg(0,0);

		// In welchem Bereich soll die Abbildung vorgenommen werden?
		pDC->SetViewportExt(clientRect.Width(),
							clientRect.Height());

		// Ursprungskoordinate festlegen
		pDC->SetViewportOrg(0,0);
	}

	// Standardfunktion aufrufen
	CView::OnPrepareDC(pDC, pInfo);
}

void CMandelbrotView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CRect clientRect = pInfo->m_rectDraw;
	int aufloesung;

	pDC->SetMapMode(MM_ANISOTROPIC);
		
	
	aufloesung = (clientRect.Width() > clientRect.Height()) ? clientRect.Width() 
																: clientRect.Height();
	pDC->SetWindowExt(aufloesung, aufloesung);
	pDC->SetWindowOrg(0,0);
	pDC->SetViewportExt(clientRect.Width(),
							clientRect.Height());
	pDC->SetViewportOrg(0,0);

	CView::OnPrint(pDC, pInfo);
}


void CMandelbrotView::OnFarbig() 
{
	// TODO: Add your command handler code here
	// Zugriff auf das Dokument erlangen
	CMandelbrotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Farbmodus einschalten und ggf. die Ansicht aktualisieren
	if (pDoc->setColorMode(1)) pDoc->UpdateAllViews(NULL);
}

void CMandelbrotView::OnSchwarzweiss() 
{
	// TODO: Add your command handler code here
	// Zugriff auf das Dokument erlangen
	CMandelbrotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Farbmodus ausschalten und ggf. die Ansicht aktualisieren
	if (pDoc->setColorMode(0)) pDoc->UpdateAllViews(NULL);
	
}

void CMandelbrotView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CMainFrame * pFrame  = ( CMainFrame * ) AfxGetApp() -> m_pMainWnd ; 
	m_pStatusBar         = ( CStatusBar * ) & ( pFrame -> m_wndStatusBar ) ; 

}

void CMandelbrotView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	// initialisiere temporäre Variablen
	CString text; 
	int index; 

	// erlange Zugriff auf Indicator
	index = m_pStatusBar -> CommandToIndex(ID_INDICATOR_XPOS);

	// formatiere Text
	text.Format("X : %4d",point.x);

	// schreibe Text in Statuszeile
	m_pStatusBar->SetPaneText(index,text);   

	index = m_pStatusBar -> CommandToIndex(ID_INDICATOR_YPOS);
	text.Format ("Y : %4d",point.y); 
	m_pStatusBar->SetPaneText(index,text);  

	// Zugriff auf das Dokument erlangen
	CMandelbrotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	double mandelPosX, mandelPosY;

	CRect clientRect;
	GetClientRect(clientRect);

	int clientWidth     = clientRect.Width();
	int clientHeight    = clientRect.Height();

	double selectionWidth  = pDoc->getXEndPosition() - pDoc->getXStartPosition();
	double selectionHeight = pDoc->getYEndPosition() - pDoc->getYStartPosition();

	double pixelWidth   = selectionWidth / clientWidth;
	double pixelHeight  = selectionHeight / clientHeight;

	mandelPosX = point.x * pixelWidth + pDoc->getXStartPosition();
	mandelPosY = point.y * pixelHeight + pDoc->getYStartPosition();

	index = m_pStatusBar -> CommandToIndex(ID_INDICATOR_XPOSMANDEL);
	text.Format ("MX : %4.6f",mandelPosX); 
	m_pStatusBar->SetPaneText(index,text);

	index = m_pStatusBar -> CommandToIndex(ID_INDICATOR_YPOSMANDEL);
	text.Format ("MY : %4.6f",mandelPosY); 
	m_pStatusBar->SetPaneText(index,text);
	
	
	CView::OnMouseMove(nFlags, point);
}
