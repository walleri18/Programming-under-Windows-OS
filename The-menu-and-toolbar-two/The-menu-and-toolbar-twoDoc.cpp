
// The-menu-and-toolbar-twoDoc.cpp : ���������� ������ CThemenuandtoolbartwoDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
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


// ��������/����������� CThemenuandtoolbartwoDoc

CThemenuandtoolbartwoDoc::CThemenuandtoolbartwoDoc()
{
	// TODO: �������� ��� ��� ������������ ������ ������������

}

CThemenuandtoolbartwoDoc::~CThemenuandtoolbartwoDoc()
{
}

BOOL CThemenuandtoolbartwoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)

	return TRUE;
}




// ������������ CThemenuandtoolbartwoDoc

void CThemenuandtoolbartwoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
	}
	else
	{
		// TODO: �������� ��� ��������
	}
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void CThemenuandtoolbartwoDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
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

// ��������� ������������ ������
void CThemenuandtoolbartwoDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
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

// ����������� CThemenuandtoolbartwoDoc

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


// ������� CThemenuandtoolbartwoDoc
