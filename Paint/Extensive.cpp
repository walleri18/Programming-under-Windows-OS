// Extensive.cpp: файл реализации
//

#include "stdafx.h"
#include "Paint.h"
#include "Extensive.h"
#include "afxdialogex.h"


// диалоговое окно CExtensive

IMPLEMENT_DYNAMIC(CExtensive, CDialog)

CExtensive::CExtensive(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_EXTENSIVE, pParent)
	, m_extensive(1)
{

}

CExtensive::~CExtensive()
{
}

void CExtensive::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_EXTENSIVE, m_extensive);
	DDV_MinMaxInt(pDX, m_extensive, 1, 10);
}


BEGIN_MESSAGE_MAP(CExtensive, CDialog)
END_MESSAGE_MAP()


// обработчики сообщений CExtensive
