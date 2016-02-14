
// The-menu-and-toolbarView.h : ��������� ������ CThemenuandtoolbarView
//

#pragma once


class CThemenuandtoolbarView : public CView
{
protected: // ������� ������ �� ������������
	CThemenuandtoolbarView();
	DECLARE_DYNCREATE(CThemenuandtoolbarView)

// ��������
public:
	CThemenuandtoolbarDoc* GetDocument() const;

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
	virtual ~CThemenuandtoolbarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � The-menu-and-toolbarView.cpp
inline CThemenuandtoolbarDoc* CThemenuandtoolbarView::GetDocument() const
   { return reinterpret_cast<CThemenuandtoolbarDoc*>(m_pDocument); }
#endif

