
// SDI_First_Project_Two_VersionDoc.cpp : ���������� ������ CSDI_First_Project_Two_VersionDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
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


// ��������/����������� CSDI_First_Project_Two_VersionDoc

CSDI_First_Project_Two_VersionDoc::CSDI_First_Project_Two_VersionDoc()
{
	// TODO: �������� ��� ��� ������������ ������ ������������

}

CSDI_First_Project_Two_VersionDoc::~CSDI_First_Project_Two_VersionDoc()
{
}

BOOL CSDI_First_Project_Two_VersionDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)

	return TRUE;
}




// ������������ CSDI_First_Project_Two_VersionDoc

void CSDI_First_Project_Two_VersionDoc::Serialize(CArchive& ar)
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
void CSDI_First_Project_Two_VersionDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CSDI_First_Project_Two_VersionDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
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

// ����������� CSDI_First_Project_Two_VersionDoc

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


// ������� CSDI_First_Project_Two_VersionDoc
