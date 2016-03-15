
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

	m_ListLine->RemoveAll();
	
	delete m_ListLine;

	// ������ ����� ������ �����
	m_ListLine = new CList<Line, Line&>();

	return TRUE;
}

// ������������ CPaintDoc

void CPaintDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		auto current_position = m_ListLine->GetHeadPosition();

		while (current_position != NULL)
		{
			m_ListLine->GetAt(current_position).Serialize(ar);

			current_position = m_ListLine->Find(m_ListLine->GetNext(current_position));
		}

		//m_ListLine->Serialize(ar);
	}
	else
	{
		while (!ar.IsBufferEmpty())
		{
			Line tmp;

			tmp.Serialize(ar);

			m_ListLine->AddHead(tmp);
		}

		//m_ListLine->Serialize(ar);
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