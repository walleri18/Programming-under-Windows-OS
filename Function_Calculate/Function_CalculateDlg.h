
// Function_CalculateDlg.h : ���� ���������
//

#pragma once
// ���������� ���� CFunction_CalculateDlg
class CFunction_CalculateDlg : public CDialogEx
{
// ��������
public:
	CFunction_CalculateDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FUNCTION_CALCULATE_DIALOG };
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
	enum Number_Function {
		ACOS, ASIN, ATAN, ATAN2, CEIL, COS, COSH, EXP, FABS, FLOOR, FMOD, LOG, LOG10, POW, SIN, SINH, SQRT, TAN, TANH, ERRORs
	};
	// ����� ��� Combo List
	BOOL m_ComboList;
	// ����� ��� Edit control
	BOOL m_EditControl;
	// ������ �� ������ RadioComboList
	afx_msg void OnBnClickedRadioComboList();
	// ������ �� ������ RadioEditControl
	afx_msg void OnBnClickedEditControl();
	// ��� �������
	CString m_NameFunctionEditControl;
	// ��������� ������� � ������� ComboList
	CString m_ComboListSelection;
	// ��� ������� ��� ������
	CString m_Name_Function;
	// ���������� ��� ������� ���������
	double m_ONE_ARGUMENT;
	// ���������� ��� ������� ���������
	double m_TWO_ARGUMENT;
	// ������ �� ������ "������� �������"
	afx_msg void OnBnClickedBtnSelectFunction();
	// ����� �������
	Number_Function m_Number_Function_Selected;
	// � ����� ���������� ��� � �����
	BOOL One_Argument;
	// ������ �� ������ "���������"
	afx_msg void OnBnClickedBtnResult();
	// ���������� ����������
	CString m_Result_Show;
	afx_msg void OnBnClickedBtnSaveFile();
	afx_msg void OnBnClickedBtnReset();
};
