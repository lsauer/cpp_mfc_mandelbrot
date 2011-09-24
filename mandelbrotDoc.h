// mandelbrotDoc.h : interface of the CMandelbrotDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANDELBROTDOC_H__D8EAEA2C_3C84_11D3_8C90_00C0A84035A6__INCLUDED_)
#define AFX_MANDELBROTDOC_H__D8EAEA2C_3C84_11D3_8C90_00C0A84035A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMandelbrotDoc : public CDocument
{
private:
	double m_dXStart, m_dXEnd, m_dYStart, m_dYEnd;
	int m_nMaxIter;
	int m_nColorMode;
protected: // create from serialization only
	CMandelbrotDoc();
	DECLARE_DYNCREATE(CMandelbrotDoc)

// Attributes
public:

// Operations
public:
	double getXStartPosition();
	double getXEndPosition();
	double getYStartPosition();
	double getYEndPosition();
	int getMaxIter();
	void setXStartPosition(double value);
	void setYStartPosition(double value);
	void setXEndPosition(double value);
	void setYEndPosition(double value);
	void setMaxIter();

	void resetAllValues();
	bool setColorMode(int mode);
	bool inColorMode();
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMandelbrotDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMandelbrotDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMandelbrotDoc)
	afx_msg void OnAusschnitt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANDELBROTDOC_H__D8EAEA2C_3C84_11D3_8C90_00C0A84035A6__INCLUDED_)
