
// Function_CalculateDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Function_Calculate.h"
#include "Function_CalculateDlg.h"
#include "afxdialogex.h"
#include "LibraryFunctions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CFunction_CalculateDlg



CFunction_CalculateDlg::CFunction_CalculateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FUNCTION_CALCULATE_DIALOG, pParent)
	, m_ComboList(FALSE)
	, m_EditControl(TRUE)
	, m_NameFunctionEditControl(_T(""))
	, m_ComboListSelection(_T(""))
	, m_ONE_ARGUMENT(0)
	, m_TWO_ARGUMENT(0)
	, m_Number_Function_Selected(-1)
	, One_Argument(FALSE)
	, m_Result_Show(_T("Результаты:"))
	, m_Name_Function(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFunction_CalculateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_COMBO_LIST, m_ComboList);
	DDX_Radio(pDX, IDC_EDIT_CONTROL, m_EditControl);
	DDX_Text(pDX, IDC_EDIT_NAME_FUNCTION, m_NameFunctionEditControl);
	DDX_CBString(pDX, IDC_COMBO_SELECTION_FUNCTION, m_ComboListSelection);
	DDX_Text(pDX, IDC_EDIT_ONE_ARGUMENT, m_ONE_ARGUMENT);
	DDX_Text(pDX, IDC_EDIT_TWO_ARGUMENT, m_TWO_ARGUMENT);
	DDX_Text(pDX, IDC_RESULT_BORD, m_Result_Show);
}

BEGIN_MESSAGE_MAP(CFunction_CalculateDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_COMBO_LIST, &CFunction_CalculateDlg::OnBnClickedRadioComboList)
	ON_BN_CLICKED(IDC_EDIT_CONTROL, &CFunction_CalculateDlg::OnBnClickedEditControl)
	ON_BN_CLICKED(IDC_BTN_SELECT_FUNCTION, &CFunction_CalculateDlg::OnBnClickedBtnSelectFunction)
	ON_BN_CLICKED(IDC_BTN_RESULT, &CFunction_CalculateDlg::OnBnClickedBtnResult)
	ON_BN_CLICKED(IDC_BTN_SAVE_FILE, &CFunction_CalculateDlg::OnBnClickedBtnSaveFile)
	ON_BN_CLICKED(IDC_BTN_RESET, &CFunction_CalculateDlg::OnBnClickedBtnReset)
END_MESSAGE_MAP()


// обработчики сообщений CFunction_CalculateDlg

BOOL CFunction_CalculateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	OnBnClickedRadioComboList();
	

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CFunction_CalculateDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CFunction_CalculateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CFunction_CalculateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFunction_CalculateDlg::OnBnClickedRadioComboList()
{
	UpdateData(TRUE);

	m_ComboList = FALSE;
	m_EditControl = TRUE;

	GetDlgItem(IDC_EDIT_NAME_FUNCTION)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_SELECTION_FUNCTION)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO_SELECTION_FUNCTION)->SetFocus();
	GetDlgItem(IDC_STATIC_TEXT_LIST_FUNCTION)->ShowWindow(FALSE);

	UpdateData(FALSE);
}


void CFunction_CalculateDlg::OnBnClickedEditControl()
{
	UpdateData(TRUE);

	m_ComboList = TRUE;
	m_EditControl = FALSE;

	GetDlgItem(IDC_EDIT_NAME_FUNCTION)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO_SELECTION_FUNCTION)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_TEXT_LIST_FUNCTION)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_NAME_FUNCTION)->SetFocus();

	UpdateData(FALSE);
}


void CFunction_CalculateDlg::OnBnClickedBtnSelectFunction()
{
	UpdateData(TRUE);

	CString nameFunction;

	if (m_ComboList == FALSE)
		nameFunction = m_ComboListSelection;

	else if (m_EditControl == FALSE) {
		nameFunction = m_NameFunctionEditControl;
	}

	if (nameFunction == L"ACOS")
		m_Number_Function_Selected = 0;

	else if (nameFunction == L"ASIN")
		m_Number_Function_Selected = 1;

	else if (nameFunction == L"ATAN")
		m_Number_Function_Selected = 2;

	else if (nameFunction == L"ATAN2")
		m_Number_Function_Selected = 3;

	else if (nameFunction == L"CEIL")
		m_Number_Function_Selected = 4;

	else if (nameFunction == L"COS")
		m_Number_Function_Selected = 5;

	else if (nameFunction == L"COSH")
		m_Number_Function_Selected = 6;

	else if (nameFunction == L"EXP")
		m_Number_Function_Selected = 7;

	else if (nameFunction == L"FABS")
		m_Number_Function_Selected = 8;

	else if (nameFunction == L"FLOOR")
		m_Number_Function_Selected = 9;

	else if (nameFunction == L"FMOD")
		m_Number_Function_Selected = 10;

	else if (nameFunction == L"LOG")
		m_Number_Function_Selected = 11;

	else if (nameFunction == L"LOG10")
		m_Number_Function_Selected = 12;

	else if (nameFunction == L"POW")
		m_Number_Function_Selected = 13;

	else if (nameFunction == L"SIN")
		m_Number_Function_Selected = 14;

	else if (nameFunction == L"SINH")
		m_Number_Function_Selected = 15;

	else if (nameFunction == L"SQRT")
		m_Number_Function_Selected = 16;

	else if (nameFunction == L"TAN")
		m_Number_Function_Selected = 17;

	else if (nameFunction == L"TANH")
		m_Number_Function_Selected = 18;

	else
		m_Number_Function_Selected = -1;

	BOOL error = ((m_Number_Function_Selected <= -1) || (m_Number_Function_Selected >= 19)) ? TRUE : FALSE;

	if (error == TRUE)
		MessageBox(L"Ошибка!!!\nФункция введена неверно!!!", L"Ошибка ввода функции", MB_OK | MB_ICONERROR);
	else {
		if ((m_Number_Function_Selected == 3) || (m_Number_Function_Selected == 10) || (m_Number_Function_Selected == 13))
			One_Argument = FALSE;

		else
			One_Argument = TRUE;


		if (One_Argument == TRUE) {
			GetDlgItem(IDC_STATIC_TEXT_ONE_ARGUMENT)->SetWindowText(L"Введите аргумент функции " + m_ComboListSelection + L":");
			GetDlgItem(IDC_STATIC_TEXT_ONE_ARGUMENT)->ShowWindow(SW_SHOW);

			GetDlgItem(IDC_EDIT_ONE_ARGUMENT)->ShowWindow(SW_SHOW);
		}
		else if (One_Argument == FALSE) {
			GetDlgItem(IDC_STATIC_TEXT_ONE_ARGUMENT)->SetWindowText(L"Введите первый аргумент функции:");
			GetDlgItem(IDC_STATIC_TEXT_ONE_ARGUMENT)->ShowWindow(SW_SHOW);

			GetDlgItem(IDC_STATIC_TEXT_TWO_ARGUMENT)->SetWindowText(L"Введите второй аргумент функции:");
			GetDlgItem(IDC_STATIC_TEXT_TWO_ARGUMENT)->ShowWindow(SW_SHOW);

			GetDlgItem(IDC_EDIT_ONE_ARGUMENT)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT_TWO_ARGUMENT)->ShowWindow(SW_SHOW);
		}

		GetDlgItem(IDC_BTN_RESULT)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_BTN_SELECT_FUNCTION)->EnableWindow(FALSE);

		GetDlgItem(IDC_RADIO_COMBO_LIST)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_CONTROL)->EnableWindow(FALSE);

		GetDlgItem(IDC_STATIC_TEXT_LIST_FUNCTION)->ShowWindow(FALSE);
		GetDlgItem(IDC_COMBO_SELECTION_FUNCTION)->EnableWindow(FALSE);

		m_Name_Function = nameFunction;
	}
	
}

void CFunction_CalculateDlg::OnBnClickedBtnResult()
{
	// Переменная выбора функции
	int functionSelection = m_Number_Function_Selected;

	CalculateFunction *fun(NULL);

	switch (functionSelection)
	{
	case ACOS:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case ASIN:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case ATAN:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case ATAN2:
		fun = new FunctionWithTwoArguments(function[functionSelection].releaseFunction2);
		break;
	case CEIL:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case COS:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case COSH:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case EXP:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case FABS:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case FLOOR:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case FMOD:
		fun = new FunctionWithTwoArguments(function[functionSelection].releaseFunction2);
		break;
	case LOG:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case LOG10:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case POW:
		fun = new FunctionWithTwoArguments(function[functionSelection].releaseFunction2);
		break;
	case SIN:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case SINH:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case SQRT:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case TAN:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	case TANH:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1);
		break;
	}

	// Установка аргументов
	fun->setArgument(m_ONE_ARGUMENT, m_TWO_ARGUMENT);

	if (One_Argument == TRUE) {

		m_Result_Show.Format(L"Результаты:\n%s(%g) = %g", m_Name_Function, m_ONE_ARGUMENT, fun->calculation());

	}

	else if (One_Argument == FALSE) {

		m_Result_Show.Format(L"Результаты:\n%s(%g, %g) = %g", m_Name_Function, m_ONE_ARGUMENT, m_TWO_ARGUMENT, fun->calculation());

	}
	GetDlgItem(IDC_RESULT_BORD)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_RESET)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_SAVE_FILE)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_RESULT)->EnableWindow(FALSE);
}


void CFunction_CalculateDlg::OnBnClickedBtnSaveFile()
{
	CFile file;

	if (!file.Open(L"Result.txt", CFile::modeCreate | CFile::modeWrite)) {
		MessageBox(L"Ошибка открытия файла Result.txt", L"Ошибка открытия файлы", MB_OK | MB_ICONERROR);
		OnOK();
	}

	file.Write(m_Result_Show, m_Result_Show.GetLength()*2);

	file.Close();


	GetDlgItem(IDC_BTN_SAVE_FILE)->EnableWindow(FALSE);
}


void CFunction_CalculateDlg::OnBnClickedBtnReset()
{
	m_ComboList = FALSE;
	m_EditControl = TRUE;
	m_NameFunctionEditControl = L"";
	m_ComboListSelection = L"";
	m_ONE_ARGUMENT = 0;
	m_TWO_ARGUMENT = 0;
	m_Number_Function_Selected = -1;
	One_Argument = FALSE;
	m_Result_Show = L"Результаты:";
	m_Name_Function = L"";

	OnBnClickedRadioComboList();

	GetDlgItem(IDC_BTN_SELECT_FUNCTION)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_SELECT_FUNCTION)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_EDIT_ONE_ARGUMENT)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_TWO_ARGUMENT)->ShowWindow(FALSE);

	GetDlgItem(IDC_STATIC_TEXT_ONE_ARGUMENT)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_TEXT_TWO_ARGUMENT)->ShowWindow(FALSE);
}
