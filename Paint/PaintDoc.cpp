
// PaintDoc.cpp : реализация класса CPaintDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
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


// создание/уничтожение CPaintDoc

CPaintDoc::CPaintDoc() : extensive(1), color(RGB(0, 0, 0)), m_ListLine(NULL)
{
	// TODO: добавьте код для одноразового вызова конструктора

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

	// Создаём новый список линий
	m_ListLine = new CList<Line, Line&>();

	return TRUE;
}

// сериализация CPaintDoc

void CPaintDoc::Serialize(CArchive& ar)
{
	if (m_ListLine)
	{
		m_ListLine->Serialize(ar);

		this->UpdateAllViews(NULL);
	}
}

// диагностика CPaintDoc

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


// команды CPaintDoc


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