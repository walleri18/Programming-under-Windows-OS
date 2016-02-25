
// Function_CalculateDlg.h : файл заголовка
//

#pragma once
// диалоговое окно CFunction_CalculateDlg
class CFunction_CalculateDlg : public CDialogEx
{
// Создание
public:
	CFunction_CalculateDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FUNCTION_CALCULATE_DIALOG };
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
	enum Number_Function {
		ACOS, ASIN, ATAN, ATAN2, CEIL, COS, COSH, EXP, FABS, FLOOR, FMOD, LOG, LOG10, POW, SIN, SINH, SQRT, TAN, TANH, ERRORs
	};
	// Выбор для Combo List
	BOOL m_ComboList;
	// Выбор для Edit control
	BOOL m_EditControl;
	// Щелчёк по пункту RadioComboList
	afx_msg void OnBnClickedRadioComboList();
	// Щелчёк по пункту RadioEditControl
	afx_msg void OnBnClickedEditControl();
	// Имя функции
	CString m_NameFunctionEditControl;
	// Выбранная функция с помощью ComboList
	CString m_ComboListSelection;
	// Имя функции для вывода
	CString m_Name_Function;
	// Переменная для первого аргумента
	double m_ONE_ARGUMENT;
	// Переменная для второго аргумента
	double m_TWO_ARGUMENT;
	// Щелчёк по кнопке "Выбрать функцию"
	afx_msg void OnBnClickedBtnSelectFunction();
	// Номер функции
	Number_Function m_Number_Function_Selected;
	// С одним аргументом или с двумя
	BOOL One_Argument;
	// Щелчёк по кнопке "Вычислить"
	afx_msg void OnBnClickedBtnResult();
	// Содержимое результата
	CString m_Result_Show;
	afx_msg void OnBnClickedBtnSaveFile();
	afx_msg void OnBnClickedBtnReset();
};
