
// The-menu-and-toolbarView.cpp : ���������� ������ CThemenuandtoolbarView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "The-menu-and-toolbar.h"
#endif

#include "The-menu-and-toolbarDoc.h"
#include "The-menu-and-toolbarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThemenuandtoolbarView

IMPLEMENT_DYNCREATE(CThemenuandtoolbarView, CView)

BEGIN_MESSAGE_MAP(CThemenuandtoolbarView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// ��������/����������� CThemenuandtoolbarView

CThemenuandtoolbarView::CThemenuandtoolbarView()
{
	// TODO: �������� ��� ��������

}

CThemenuandtoolbarView::~CThemenuandtoolbarView()
{
}

BOOL CThemenuandtoolbarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CThemenuandtoolbarView

void CThemenuandtoolbarView::OnDraw(CDC* /*pDC*/)
{
	CThemenuandtoolbarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ CThemenuandtoolbarView

BOOL CThemenuandtoolbarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CThemenuandtoolbarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CThemenuandtoolbarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CThemenuandtoolbarView

#ifdef _DEBUG
void CThemenuandtoolbarView::AssertValid() const
{
	CView::AssertValid();
}

void CThemenuandtoolbarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThemenuandtoolbarDoc* CThemenuandtoolbarView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThemenuandtoolbarDoc)));
	return (CThemenuandtoolbarDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CThemenuandtoolbarView
