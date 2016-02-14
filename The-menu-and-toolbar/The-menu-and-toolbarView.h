
// The-menu-and-toolbarView.h : интерфейс класса CThemenuandtoolbarView
//

#pragma once


class CThemenuandtoolbarView : public CView
{
protected: // создать только из сериализации
	CThemenuandtoolbarView();
	DECLARE_DYNCREATE(CThemenuandtoolbarView)

// Атрибуты
public:
	CThemenuandtoolbarDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CThemenuandtoolbarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в The-menu-and-toolbarView.cpp
inline CThemenuandtoolbarDoc* CThemenuandtoolbarView::GetDocument() const
   { return reinterpret_cast<CThemenuandtoolbarDoc*>(m_pDocument); }
#endif

