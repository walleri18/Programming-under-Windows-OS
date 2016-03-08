
// PaintDoc.h : интерфейс класса CPaintDoc
//


#pragma once
#include "Extensive.h"
// Структура линий для рисования карандащом. (короче координаты начала и конца, цвет, жирность)
struct Line
{
	// Координаты начала и конец
	int x_begin, x_end;
	int y_begin, y_end;

	// Жирность линии
	int extensive;

	// Цвет линии
	COLORREF color;

	// Конструктор с параметрами
	Line(int x_begin, int y_begin, int x_end, int y_end, COLORREF color, int extensive) :
		x_begin(x_begin), y_begin(y_begin), x_end(x_end), color(color), extensive(extensive) {}
	
	//Конструктор без параметров
	Line() {}

	void Serialize(CArchive& ar)
	{
		if (ar.IsStoring())
		{
			ar << x_begin << " " << x_end << " " << y_begin << " " << y_end << " " << color << " " << extensive << " ";
		}

		else
		{
			ar >> x_begin >> x_end >> y_begin >> y_end >> color >> extensive;
		}
	}
};

class CPaintDoc : public CDocument
{
protected: // создать только из сериализации
	CPaintDoc();
	DECLARE_DYNCREATE(CPaintDoc)

// Атрибуты
public:
	// Список маленьких линий для рисования в виде карандаша
	CList<Line, Line&>	*m_ListLine;
	
	// Жирность линии
	int extensive;

	// Цвет линии
	COLORREF color;

	// Позиция головы списка
	POSITION header;

// Операции
public:
	// Геттер списка
	CList<Line, Line&>* GetListLine() const
	{
		return m_ListLine;
	}

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Реализация
public:
	virtual ~CPaintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnColorLine();
	afx_msg void OnHeightLine();
};
