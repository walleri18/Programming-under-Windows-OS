
// The-menu-and-toolbar-twoView.cpp : ���������� ������ CThemenuandtoolbartwoView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "The-menu-and-toolbar-two.h"
#endif

#include "The-menu-and-toolbar-twoDoc.h"
#include "The-menu-and-toolbar-twoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThemenuandtoolbartwoView

IMPLEMENT_DYNCREATE(CThemenuandtoolbartwoView, CView)

BEGIN_MESSAGE_MAP(CThemenuandtoolbartwoView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// ��������/����������� CThemenuandtoolbartwoView

CThemenuandtoolbartwoView::CThemenuandtoolbartwoView()
{
	// TODO: �������� ��� ��������

}

CThemenuandtoolbartwoView::~CThemenuandtoolbartwoView()
{
}

BOOL CThemenuandtoolbartwoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CThemenuandtoolbartwoView

void CThemenuandtoolbartwoView::OnDraw(CDC* /*pDC*/)
{
	CThemenuandtoolbartwoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ CThemenuandtoolbartwoView

BOOL CThemenuandtoolbartwoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CThemenuandtoolbartwoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CThemenuandtoolbartwoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CThemenuandtoolbartwoView

#ifdef _DEBUG
void CThemenuandtoolbartwoView::AssertValid() const
{
	CView::AssertValid();
}

void CThemenuandtoolbartwoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThemenuandtoolbartwoDoc* CThemenuandtoolbartwoView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThemenuandtoolbartwoDoc)));
	return (CThemenuandtoolbartwoDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CThemenuandtoolbartwoView
