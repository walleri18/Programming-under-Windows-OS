
// SDI_First_Project_One_VersionView.cpp : ���������� ������ CSDI_First_Project_One_VersionView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "SDI_First_Project_One_Version.h"
#endif

#include "SDI_First_Project_One_VersionDoc.h"
#include "SDI_First_Project_One_VersionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDI_First_Project_One_VersionView

IMPLEMENT_DYNCREATE(CSDI_First_Project_One_VersionView, CView)

BEGIN_MESSAGE_MAP(CSDI_First_Project_One_VersionView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// ��������/����������� CSDI_First_Project_One_VersionView

CSDI_First_Project_One_VersionView::CSDI_First_Project_One_VersionView()
{
	// TODO: �������� ��� ��������

}

CSDI_First_Project_One_VersionView::~CSDI_First_Project_One_VersionView()
{
}

BOOL CSDI_First_Project_One_VersionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CSDI_First_Project_One_VersionView

void CSDI_First_Project_One_VersionView::OnDraw(CDC* /*pDC*/)
{
	CSDI_First_Project_One_VersionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ CSDI_First_Project_One_VersionView

BOOL CSDI_First_Project_One_VersionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CSDI_First_Project_One_VersionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CSDI_First_Project_One_VersionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CSDI_First_Project_One_VersionView

#ifdef _DEBUG
void CSDI_First_Project_One_VersionView::AssertValid() const
{
	CView::AssertValid();
}

void CSDI_First_Project_One_VersionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDI_First_Project_One_VersionDoc* CSDI_First_Project_One_VersionView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDI_First_Project_One_VersionDoc)));
	return (CSDI_First_Project_One_VersionDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CSDI_First_Project_One_VersionView
