
// PaintView.h : интерфейс класса CPaintView
//

#pragma once


class CPaintView : public CView
{
protected: // создать только из сериализации
	CPaintView();
	DECLARE_DYNCREATE(CPaintView)

// Атрибуты
public:
	CPaintDoc* GetDocument() const;

	// Выбор карандаша или ластика. (карандаш = TRUE, ластик = FALSE)
	BOOL isPencil;

	// Предыдущие координаты мышки
	int previous_x;
	int previous_y;

	// Первый раз ли запускается проект
	BOOL isFirst;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Реализация
public:
	virtual ~CPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBrush();
	afx_msg void OnClear();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // отладочная версия в PaintView.cpp
inline CPaintDoc* CPaintView::GetDocument() const
   { return reinterpret_cast<CPaintDoc*>(m_pDocument); }
#endif

