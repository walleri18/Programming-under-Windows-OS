
// SDI_First_Project_One_VersionView.h : интерфейс класса CSDI_First_Project_One_VersionView
//

#pragma once


class CSDI_First_Project_One_VersionView : public CView
{
protected: // создать только из сериализации
	CSDI_First_Project_One_VersionView();
	DECLARE_DYNCREATE(CSDI_First_Project_One_VersionView)

// Атрибуты
public:
	CSDI_First_Project_One_VersionDoc* GetDocument() const;

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
	virtual ~CSDI_First_Project_One_VersionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в SDI_First_Project_One_VersionView.cpp
inline CSDI_First_Project_One_VersionDoc* CSDI_First_Project_One_VersionView::GetDocument() const
   { return reinterpret_cast<CSDI_First_Project_One_VersionDoc*>(m_pDocument); }
#endif

