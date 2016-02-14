
// The-menu-and-toolbarView.cpp : реализаци€ класса CThemenuandtoolbarView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
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
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CThemenuandtoolbarView

CThemenuandtoolbarView::CThemenuandtoolbarView()
{
	// TODO: добавьте код создани€

}

CThemenuandtoolbarView::~CThemenuandtoolbarView()
{
}

BOOL CThemenuandtoolbarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CThemenuandtoolbarView

void CThemenuandtoolbarView::OnDraw(CDC* /*pDC*/)
{
	CThemenuandtoolbarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
}


// печать CThemenuandtoolbarView

BOOL CThemenuandtoolbarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CThemenuandtoolbarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CThemenuandtoolbarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CThemenuandtoolbarView

#ifdef _DEBUG
void CThemenuandtoolbarView::AssertValid() const
{
	CView::AssertValid();
}

void CThemenuandtoolbarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThemenuandtoolbarDoc* CThemenuandtoolbarView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThemenuandtoolbarDoc)));
	return (CThemenuandtoolbarDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CThemenuandtoolbarView
