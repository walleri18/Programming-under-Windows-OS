
// The-menu-and-toolbar-twoView.h : ��������� ������ CThemenuandtoolbartwoView
//

#pragma once


class CThemenuandtoolbartwoView : public CView
{
protected: // ������� ������ �� ������������
	CThemenuandtoolbartwoView();
	DECLARE_DYNCREATE(CThemenuandtoolbartwoView)

// ��������
public:
	CThemenuandtoolbartwoDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CThemenuandtoolbartwoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � The-menu-and-toolbar-twoView.cpp
inline CThemenuandtoolbartwoDoc* CThemenuandtoolbartwoView::GetDocument() const
   { return reinterpret_cast<CThemenuandtoolbartwoDoc*>(m_pDocument); }
#endif

