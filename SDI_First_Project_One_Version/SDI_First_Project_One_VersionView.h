
// SDI_First_Project_One_VersionView.h : ��������� ������ CSDI_First_Project_One_VersionView
//

#pragma once


class CSDI_First_Project_One_VersionView : public CView
{
protected: // ������� ������ �� ������������
	CSDI_First_Project_One_VersionView();
	DECLARE_DYNCREATE(CSDI_First_Project_One_VersionView)

// ��������
public:
	CSDI_First_Project_One_VersionDoc* GetDocument() const;

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
	virtual ~CSDI_First_Project_One_VersionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � SDI_First_Project_One_VersionView.cpp
inline CSDI_First_Project_One_VersionDoc* CSDI_First_Project_One_VersionView::GetDocument() const
   { return reinterpret_cast<CSDI_First_Project_One_VersionDoc*>(m_pDocument); }
#endif

