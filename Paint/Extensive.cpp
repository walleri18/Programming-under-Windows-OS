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
	, m_width(1)
	, m_Text_Show(_T("1 px"))
{
	
}

CExtensive::~CExtensive()
{
}

void CExtensive::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER_PIXEL, m_width);
	DDV_MinMaxInt(pDX, m_width, 1, 10);
	DDX_Text(pDX, IDC_SHOW_PIXCEL, m_Text_Show);
	DDX_Control(pDX, IDC_SLIDER_PIXEL, m_Control_slider);
}


BEGIN_MESSAGE_MAP(CExtensive, CDialog)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_PIXEL, &CExtensive::OnNMCustomdrawSliderPixel)
END_MESSAGE_MAP()


// обработчики сообщений CExtensive

void CExtensive::OnNMCustomdrawSliderPixel(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений

	m_Control_slider.SetRange(1, 10);

	UpdateData();

	m_Text_Show.Format(L"%d px", m_width);

	UpdateData(FALSE);

	*pResult = 0;
}