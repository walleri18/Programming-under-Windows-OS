
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
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// создание/уничтожение CPaintView

CPaintView::CPaintView() : isPencil(TRUE)
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

void CPaintView::OnDraw(CDC* pDC)
{
	CPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// Узнаём размеры окна
	CRect rect = new CRect;
	GetClientRect(rect);

	// Создаём новый контекст устройства
	CDC p_newDC;
	p_newDC.CreateCompatibleDC(pDC);

	// Создаём изображение совместимое с данным контекстным устройством
	m_Bitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());

	p_newDC.SelectObject(&m_Bitmap);

	auto *mList = GetDocument()->GetListLine();

	auto current_position = mList->GetTailPosition();

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

		// Создаём нужную кисть
		CPen newPen(PS_SOLID, extensive, color);

		// Установить новое перо текущим
		p_newDC.SelectObject(&newPen);

		// Провести линию от предыдущей точки до текущей
		p_newDC.MoveTo(mList->GetAt(current_position).x_begin,
			mList->GetAt(current_position).y_begin); // поместить графический курсор
		p_newDC.LineTo(mList->GetAt(current_position).x_end,
			mList->GetAt(current_position).y_end); // рисовать до текущей

		mList->GetPrev(current_position);
	}

	DisplayBitmap(pDC, &m_Bitmap, 0, 0);

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
	// Проверка на нажатие левой клавишы
	//if ((nFlags | MK_LBUTTON) == MK_LBUTTON)
	if (GetDocument()->isLeftButtonMouse == TRUE)
	{
		if (isPencil == TRUE)
		{
			// Жирность линии
			int extensive = GetDocument()->extensive;

			// Цвет линии
			COLORREF color = GetDocument()->color;

			// Создаём временный объект линии
			Line tmp(previous_x, previous_y, point.x, point.y, color, extensive);

			// Страховка
			previous_x = point.x;
			previous_y = point.y;

			// Добавляем объект линии в список
			GetDocument()->GetListLine()->AddHead(tmp);
		}
		else
		{
			// Жирность линии
			int extensive = 3 * GetDocument()->extensive;

			// Цвет линии
			COLORREF color = RGB(255, 255, 255);

			// Создаём временный объект линии
			Line tmp(previous_x, previous_y, point.x, point.y, color, extensive);

			// Страховка
			previous_x = point.x;
			previous_y = point.y;

			// Добавляем объект линии в список
			GetDocument()->GetListLine()->AddHead(tmp);
		}

		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}

void CPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// Записываем координаты нажатия
	previous_x = point.x;
	previous_y = point.y;

	// Нажата левая клавиша мыши
	GetDocument()->isLeftButtonMouse = TRUE;

	CView::OnLButtonDown(nFlags, point);
}

void CPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// Левая клавиша отпущена
	GetDocument()->isLeftButtonMouse = FALSE;

	CView::OnLButtonUp(nFlags, point);
}
