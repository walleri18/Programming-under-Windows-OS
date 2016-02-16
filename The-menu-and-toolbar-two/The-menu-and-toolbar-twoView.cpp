
// The-menu-and-toolbar-twoView.cpp : реализаци€ класса CThemenuandtoolbartwoView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
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
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CThemenuandtoolbartwoView

CThemenuandtoolbartwoView::CThemenuandtoolbartwoView()
{
	// TODO: добавьте код создани€

}

CThemenuandtoolbartwoView::~CThemenuandtoolbartwoView()
{
}

BOOL CThemenuandtoolbartwoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CThemenuandtoolbartwoView

void CThemenuandtoolbartwoView::OnDraw(CDC* /*pDC*/)
{
	CThemenuandtoolbartwoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
}


// печать CThemenuandtoolbartwoView

BOOL CThemenuandtoolbartwoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CThemenuandtoolbartwoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CThemenuandtoolbartwoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CThemenuandtoolbartwoView

#ifdef _DEBUG
void CThemenuandtoolbartwoView::AssertValid() const
{
	CView::AssertValid();
}

void CThemenuandtoolbartwoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThemenuandtoolbartwoDoc* CThemenuandtoolbartwoView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThemenuandtoolbartwoDoc)));
	return (CThemenuandtoolbartwoDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CThemenuandtoolbartwoView
