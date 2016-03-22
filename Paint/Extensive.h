#pragma once
#include "afxcmn.h"


// диалоговое окно CExtensive

class CExtensive : public CDialog
{
	DECLARE_DYNAMIC(CExtensive)

public:
	CExtensive(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CExtensive();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXTENSIVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// Размер линии
	int m_width;
	// Текст в ячейке
	CString m_Text_Show;
	afx_msg void OnNMCustomdrawSliderPixel(NMHDR *pNMHDR, LRESULT *pResult);
	// Контроль за слайдером
	CSliderCtrl m_Control_slider;
};
