
// First-Dlg-ProjectDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CFirstDlgProjectDlg
class CFirstDlgProjectDlg : public CDialogEx
{
// ��������
public:
	CFirstDlgProjectDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIRSTDLGPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	// ���������� �����
	long m_Hours;
	// ���������� �����
	long m_Minutes;
	// ���������� ������
	long m_Seconds;
	// ������������� � �������
	BOOL m_Trend_TOSECOND;
	// �������� ��������������
	BOOL m_Trend_INVERSION;
	afx_msg void OnBnClickedRadioTosecond();
	afx_msg void OnBnClickedRadioInvers();
	afx_msg void OnBnClickedBtnProgress();
	// ���������� ������ ��� ��������
	UINT m_Count_Seconds;
};
