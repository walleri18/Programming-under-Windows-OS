
// SDI_First_Project_Two_VersionView.cpp : реализаци€ класса CSDI_First_Project_Two_VersionView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SDI_First_Project_Two_Version.h"
#endif

#include "SDI_First_Project_Two_VersionDoc.h"
#include "SDI_First_Project_Two_VersionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDI_First_Project_Two_VersionView

IMPLEMENT_DYNCREATE(CSDI_First_Project_Two_VersionView, CView)

BEGIN_MESSAGE_MAP(CSDI_First_Project_Two_VersionView, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CSDI_First_Project_Two_VersionView

CSDI_First_Project_Two_VersionView::CSDI_First_Project_Two_VersionView()
{
	// TODO: добавьте код создани€

}

CSDI_First_Project_Two_VersionView::~CSDI_First_Project_Two_VersionView()
{
}

BOOL CSDI_First_Project_Two_VersionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CSDI_First_Project_Two_VersionView

void CSDI_First_Project_Two_VersionView::OnDraw(CDC* /*pDC*/)
{
	CSDI_First_Project_Two_VersionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
}


// печать CSDI_First_Project_Two_VersionView

BOOL CSDI_First_Project_Two_VersionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSDI_First_Project_Two_VersionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSDI_First_Project_Two_VersionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CSDI_First_Project_Two_VersionView

#ifdef _DEBUG
void CSDI_First_Project_Two_VersionView::AssertValid() const
{
	CView::AssertValid();
}

void CSDI_First_Project_Two_VersionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDI_First_Project_Two_VersionDoc* CSDI_First_Project_Two_VersionView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDI_First_Project_Two_VersionDoc)));
	return (CSDI_First_Project_Two_VersionDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CSDI_First_Project_Two_VersionView
