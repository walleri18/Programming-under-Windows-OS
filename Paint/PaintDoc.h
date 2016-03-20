
// PaintDoc.h : ��������� ������ CPaintDoc
//


#pragma once
#include "Extensive.h"
// ��������� ����� ��� ��������� ����������. (������ ���������� ������ � �����, ����, ��������)
struct Line
{
	// ���������� ������ � �����
	int x_begin, x_end;
	int y_begin, y_end;

	// �������� �����
	int extensive;

	// ���� �����
	COLORREF color;

	// ����������� � �����������
	Line(int x_begin, int y_begin, int x_end, int y_end, COLORREF color, int extensive) :
		x_begin(x_begin), y_begin(y_begin), x_end(x_end), color(color), extensive(extensive) {}
	
	//����������� ��� ����������
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
protected: // ������� ������ �� ������������
	CPaintDoc();
	DECLARE_DYNCREATE(CPaintDoc)

// ��������
public:
	// ������ ��������� ����� ��� ��������� � ���� ���������
	CList<Line, Line&>	*m_ListLine;
	
	// �������� �����
	int extensive;

	// ���� �����
	COLORREF color;

	// ������� ������ ������
	POSITION header;

	// �������� ������� ����� ������� ����
	BOOL isLeftButtonMouse;

// ��������
public:
	// ������ ������
	CList<Line, Line&>* GetListLine() const
	{
		return m_ListLine;
	}

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ����������
public:
	virtual ~CPaintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnColorLine();
	afx_msg void OnHeightLine();
};
