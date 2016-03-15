
// PaintView.cpp : реализация класса CPaintView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Paint.h"
#endif

#include "PaintDoc.h"
#include "PaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CView)

BEGIN_MESSAGE_MAP(CPaintView, CView)
	ON_COMMAND(ID_Brush, &CPaintView::OnBrush)
	ON_COMMAND(ID_Clear, &CPaintView::OnClear)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// создание/уничтожение CPaintView

CPaintView::CPaintView() : isPencil()
{
}

CPaintView::~CPaintView()
{
}

BOOL CPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CPaintView

void CPaintView::PaintBrush()
{
	auto *mList = GetDocument()->m_ListLine;

	auto current_position = mList->GetHeadPosition();

	while (current_position != NULL)
	{
		// Жирность линии
		int extensive = mList->GetAt(current_position).extensive;

		// Цвет линии
		COLORREF color = mList->GetAt(current_position).color;

		// Создаём временный объект линии
		Line tmp(mList->GetAt(current_position).x_begin, 
				 mList->GetAt(current_position).y_begin, 
				 mList->GetAt(current_position).x_end, 
				 mList->GetAt(current_position).y_end, 
				 color, extensive);

		// Создаём средство рисования
		CClientDC dc(this);

		// Создаём нужную кисть
		CPen newPen(PS_SOLID, extensive, color);

		// Установить новое перо текущим
		dc.SelectObject(&newPen);

		// Провести линию от предыдущей точки до текущей
		dc.MoveTo(mList->GetAt(current_position).x_begin, mList->GetAt(current_position).y_begin); // поместить графический курсор
		dc.LineTo(mList->GetAt(current_position).x_end, mList->GetAt(current_position).y_end); // рисовать до текущей

		current_position = mList->Find(mList->GetNext(current_position));
	}
}

void CPaintView::OnDraw(CDC* /*pDC*/)
{
	CPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


// диагностика CPaintView

#ifdef _DEBUG
void CPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintDoc* CPaintView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintDoc)));
	return (CPaintDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CPaintView

void CPaintView::OnBrush()
{
	isPencil = TRUE;

	// Ставим галочку что выделен пункт меню карандаш
	AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_Brush, MF_CHECKED);
	// Снимаем галочку с пункта ластик
	AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_Clear, MF_UNCHECKED);
}


void CPaintView::OnClear()
{
	isPencil = FALSE;

	// Снимаем галочку что выделен пункт меню карандаш
	AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_Brush, MF_UNCHECKED);
	// Ставим галочку с пункта ластик
	AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_Clear, MF_CHECKED);
}


void CPaintView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isPencil == TRUE)
	{

		// Проверка на нажатие левой клавишы
		if ((nFlags & MK_LBUTTON) != MK_LBUTTON)
			return;

		// Жирность линии
		int extensive = GetDocument()->extensive;

		// Цвет линии
		COLORREF color = GetDocument()->color;

		// Создаём временный объект линии
		Line tmp(previous_x, previous_y, point.x, point.y, color, extensive);

		// Создаём средство рисования
		CClientDC dc(this);

		// Создаём нужную кисть
		CPen newPen(PS_SOLID, extensive, color);

		// Установить новое перо текущим
		dc.SelectObject(&newPen);

		// Провести линию от предыдущей точки до текущей
		dc.MoveTo(previous_x, previous_y); // поместить графический курсор
		dc.LineTo(point.x, point.y); // рисовать до текущей

		// Страховка
		previous_x = point.x;
		previous_y = point.y;

		// Добавляем объект линии в список
		GetDocument()->GetListLine()->AddHead(tmp);
	}
	else
	{
		// Проверка на нажатие левой клавишы
		if ((nFlags & MK_LBUTTON) != MK_LBUTTON)
			return;

		// Жирность линии
		int extensive = 3 * GetDocument()->extensive;

		// Цвет линии
		COLORREF color = RGB(255, 255, 255);

		// Создаём временный объект линии
		Line tmp(previous_x, previous_y, point.x, point.y, color, extensive);

		// Создаём средство рисования
		CClientDC dc(this);

		// Создаём нужную кисть
		CPen newPen(PS_SOLID, extensive, color);

		// Установить новое перо текущим
		dc.SelectObject(&newPen);

		// Провести линию от предыдущей точки до текущей
		dc.MoveTo(previous_x, previous_y); // поместить графический курсор
		dc.LineTo(point.x, point.y); // рисовать до текущей

		// Страховка
		previous_x = point.x;
		previous_y = point.y;

		// Добавляем объект линии в список
		GetDocument()->GetListLine()->AddHead(tmp);
	}
	CView::OnMouseMove(nFlags, point);
}


void CPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// Записываем координаты нажатия
	previous_x = point.x;
	previous_y = point.y;

	CView::OnLButtonDown(nFlags, point);
}

void CPaintView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	this->PaintBrush();
}
