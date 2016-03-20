
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

	friend BOOL operator == (Line a, Line b)
	{
		if (a.color == b.color)
			if (a.extensive == b.extensive)
				if (a.x_begin == b.x_begin)
					if (a.x_end == b.x_end)
						if (a.y_begin == b.y_begin)
							if (a.y_end == b.y_end)
								return TRUE;
		return FALSE;
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

	// Проверка нажатия левой клавиши мыши
	BOOL isLeftButtonMouse;

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
