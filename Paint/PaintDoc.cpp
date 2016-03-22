
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

CPaintDoc::CPaintDoc() : extensive(1), color(RGB(0, 0, 0)), m_ListLine(NULL), isLeftButtonMouse(FALSE)
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

	
	
	if (m_ListLine)
		delete m_ListLine;

	// ������ ����� ������ �����
	m_ListLine = new CList<Line, Line&>();

	return TRUE;
}

// ������������ CPaintDoc

void CPaintDoc::Serialize(CArchive& ar)
{
	if (m_ListLine)
		m_ListLine->Serialize(ar);
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
	dlg.m_cc.Flags |= CC_RGBINIT;
	dlg.m_cc.Flags |= CC_FULLOPEN;

	dlg.m_cc.rgbResult = color;

	dlg.DoModal();

	color = dlg.GetColor();
}


void CPaintDoc::OnHeightLine()
{
	CExtensive dlg;
	dlg.m_width = extensive;
	
	if (dlg.DoModal() == IDOK)
	{
		extensive = dlg.m_width;
	}
}

void CPaintDoc::DeleteContents()
{
	if (m_ListLine)
		m_ListLine->RemoveAll();

	CDocument::DeleteContents();
}
