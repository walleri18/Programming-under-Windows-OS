
// SDI_First_Project_Two_VersionDoc.cpp : реализация класса CSDI_First_Project_Two_VersionDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SDI_First_Project_Two_Version.h"
#endif

#include "SDI_First_Project_Two_VersionDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSDI_First_Project_Two_VersionDoc

IMPLEMENT_DYNCREATE(CSDI_First_Project_Two_VersionDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDI_First_Project_Two_VersionDoc, CDocument)
END_MESSAGE_MAP()


// создание/уничтожение CSDI_First_Project_Two_VersionDoc

CSDI_First_Project_Two_VersionDoc::CSDI_First_Project_Two_VersionDoc()
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CSDI_First_Project_Two_VersionDoc::~CSDI_First_Project_Two_VersionDoc()
{
}

BOOL CSDI_First_Project_Two_VersionDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// сериализация CSDI_First_Project_Two_VersionDoc

void CSDI_First_Project_Two_VersionDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CSDI_First_Project_Two_VersionDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CSDI_First_Project_Two_VersionDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CSDI_First_Project_Two_VersionDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// диагностика CSDI_First_Project_Two_VersionDoc

#ifdef _DEBUG
void CSDI_First_Project_Two_VersionDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDI_First_Project_Two_VersionDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды CSDI_First_Project_Two_VersionDoc
