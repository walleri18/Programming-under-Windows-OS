
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
