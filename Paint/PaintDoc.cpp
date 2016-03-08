
// PaintDoc.cpp : ���������� ������ CPaintDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "Paint.h"
#endif

#include "PaintDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPaintDoc

IMPLEMENT_DYNCREATE(CPaintDoc, CDocument)

BEGIN_MESSAGE_MAP(CPaintDoc, CDocument)
	ON_COMMAND(ID_COLOR_LINE, &CPaintDoc::OnColorLine)
	ON_COMMAND(ID_HEIGHT_LINE, &CPaintDoc::OnHeightLine)
END_MESSAGE_MAP()


// ��������/����������� CPaintDoc

CPaintDoc::CPaintDoc() : extensive(1), color(RGB(0, 0, 0))
{
	// TODO: �������� ��� ��� ������������ ������ ������������

}

CPaintDoc::~CPaintDoc()
{
}

BOOL CPaintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ������ ����� ������ �����
	m_ListLine = new CList<Line, Line&>();

	return TRUE;
}

// ������������ CPaintDoc

void CPaintDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_ListLine->GetCount() << " ";

		// �������� ������� ��������
		auto current = m_ListLine->GetTailPosition();

		for (; current != NULL; m_ListLine->RemoveTail(), current = m_ListLine->GetTailPosition())
		{
			m_ListLine->GetAt(current).Serialize(ar);
		}
	}
	else
	{
		int count;

		ar >> count;

		m_ListLine->RemoveAll();

		for (int i = 0; i < count; i++)
		{
			Line tmp;
			tmp.Serialize(ar);

			m_ListLine->AddHead(tmp);
		}
	}
}

// ����������� CPaintDoc

#ifdef _DEBUG
void CPaintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPaintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ������� CPaintDoc


void CPaintDoc::OnColorLine()
{
	CColorDialog dlg;

	dlg.DoModal();

	color = dlg.GetColor();
}


void CPaintDoc::OnHeightLine()
{
	CExtensive dlg;
	
	if (dlg.DoModal() == IDOK)
	{
		extensive = dlg.m_extensive;
	}
}
