
// The-menu-and-toolbar-twoDoc.cpp : реализация класса CThemenuandtoolbartwoDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "The-menu-and-toolbar-two.h"
#endif

#include "The-menu-and-toolbar-twoDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CThemenuandtoolbartwoDoc

IMPLEMENT_DYNCREATE(CThemenuandtoolbartwoDoc, CDocument)

BEGIN_MESSAGE_MAP(CThemenuandtoolbartwoDoc, CDocument)
END_MESSAGE_MAP()


// создание/уничтожение CThemenuandtoolbartwoDoc

CThemenuandtoolbartwoDoc::CThemenuandtoolbartwoDoc()
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CThemenuandtoolbartwoDoc::~CThemenuandtoolbartwoDoc()
{
}

BOOL CThemenuandtoolbartwoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// сериализация CThemenuandtoolbartwoDoc

void CThemenuandtoolbartwoDoc::Serialize(CArchive& ar)
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
void CThemenuandtoolbartwoDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CThemenuandtoolbartwoDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CThemenuandtoolbartwoDoc::SetSearchContent(const CString& value)
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

// диагностика CThemenuandtoolbartwoDoc

#ifdef _DEBUG
void CThemenuandtoolbartwoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CThemenuandtoolbartwoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды CThemenuandtoolbartwoDoc
