#pragma once
#include "afxcmn.h"


// ���������� ���� CExtensive

class CExtensive : public CDialog
{
	DECLARE_DYNAMIC(CExtensive)

public:
	CExtensive(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CExtensive();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXTENSIVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// ������ �����
	int m_width;
	// ����� � ������
	CString m_Text_Show;
	afx_msg void OnNMCustomdrawSliderPixel(NMHDR *pNMHDR, LRESULT *pResult);
	// �������� �� ���������
	CSliderCtrl m_Control_slider;
};
