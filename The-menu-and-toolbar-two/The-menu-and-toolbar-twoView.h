
// The-menu-and-toolbar-twoView.h : интерфейс класса CThemenuandtoolbartwoView
//

#pragma once


class CThemenuandtoolbartwoView : public CView
{
protected: // создать только из сериализации
	CThemenuandtoolbartwoView();
	DECLARE_DYNCREATE(CThemenuandtoolbartwoView)

// Атрибуты
public:
	CThemenuandtoolbartwoDoc* GetDocument() const;

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
	virtual ~CThemenuandtoolbartwoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в The-menu-and-toolbar-twoView.cpp
inline CThemenuandtoolbartwoDoc* CThemenuandtoolbartwoView::GetDocument() const
   { return reinterpret_cast<CThemenuandtoolbartwoDoc*>(m_pDocument); }
#endif

