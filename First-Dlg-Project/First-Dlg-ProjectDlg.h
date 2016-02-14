
// First-Dlg-ProjectDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CFirstDlgProjectDlg
class CFirstDlgProjectDlg : public CDialogEx
{
// Создание
public:
	CFirstDlgProjectDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIRSTDLGPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	// Количество часов
	long m_Hours;
	// Количество минут
	long m_Minutes;
	// Количество секунд
	long m_Seconds;
	// Преобразовать в секунды
	BOOL m_Trend_TOSECOND;
	// Обратное преобразование
	BOOL m_Trend_INVERSION;
	afx_msg void OnBnClickedRadioTosecond();
	afx_msg void OnBnClickedRadioInvers();
	afx_msg void OnBnClickedBtnProgress();
	// Количество секунд при переводе
	UINT m_Count_Seconds;
};
