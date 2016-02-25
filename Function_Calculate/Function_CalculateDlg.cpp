
// Function_CalculateDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Function_Calculate.h"
#include "Function_CalculateDlg.h"
#include "afxdialogex.h"

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
	, m_Number_Function_Selected(ERRORs)
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
		m_Number_Function_Selected = ACOS;

	else if (nameFunction == L"ASIN")
		m_Number_Function_Selected = ASIN;

	else if (nameFunction == L"ATAN")
		m_Number_Function_Selected = ATAN;

	else if (nameFunction == L"ATAN2")
		m_Number_Function_Selected = ATAN2;

	else if (nameFunction == L"CEIL")
		m_Number_Function_Selected = CEIL;

	else if (nameFunction == L"COS")
		m_Number_Function_Selected = COS;

	else if (nameFunction == L"COSH")
		m_Number_Function_Selected = COSH;

	else if (nameFunction == L"EXP")
		m_Number_Function_Selected = EXP;

	else if (nameFunction == L"FABS")
		m_Number_Function_Selected = FABS;

	else if (nameFunction == L"FLOOR")
		m_Number_Function_Selected = FLOOR;

	else if (nameFunction == L"FMOD")
		m_Number_Function_Selected = FMOD;

	else if (nameFunction == L"LOG")
		m_Number_Function_Selected = LOG;

	else if (nameFunction == L"LOG10")
		m_Number_Function_Selected = LOG10;

	else if (nameFunction == L"POW")
		m_Number_Function_Selected = POW;

	else if (nameFunction == L"SIN")
		m_Number_Function_Selected = SIN;

	else if (nameFunction == L"SINH")
		m_Number_Function_Selected = SINH;

	else if (nameFunction == L"SQRT")
		m_Number_Function_Selected = SQRT;

	else if (nameFunction == L"TAN")
		m_Number_Function_Selected = TAN;

	else if (nameFunction == L"TANH")
		m_Number_Function_Selected = TANH;

	else
		m_Number_Function_Selected = ERRORs;

	if (m_Number_Function_Selected == ERRORs)
		MessageBox(L"Ошибка!!!\nФункция введена неверно!!!", L"Ошибка ввода функции", MB_OK | MB_ICONERROR);
	else {
		if ((m_Number_Function_Selected == ATAN2) || (m_Number_Function_Selected == FMOD) || (m_Number_Function_Selected == POW))
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
	UpdateData(TRUE);

	switch (m_Number_Function_Selected)
	{
	case ACOS:
	case ASIN:
	case ATAN:
	case ATAN2:
	case COS:
	case COSH:
	case SIN:
	case SINH:
	case TAN:
	case TANH:
		m_ONE_ARGUMENT = (m_ONE_ARGUMENT * 3.14) / 180;
		m_TWO_ARGUMENT = (m_TWO_ARGUMENT * 3.14) / 180;
	}

	// Переменная выбора функции
	Number_Function functionSelection = m_Number_Function_Selected;

	double result(0);

	switch (functionSelection)
	{
	case ACOS:
		result = acos(m_ONE_ARGUMENT);
		break;
	case ASIN:
		result = asin(m_ONE_ARGUMENT);
		break;
	case ATAN:
		result = atan(m_ONE_ARGUMENT);
		break;
	case ATAN2:
		result = atan2(m_ONE_ARGUMENT, m_TWO_ARGUMENT);
		break;
	case CEIL:
		result = ceil(m_ONE_ARGUMENT);
		break;
	case COS:
		result = cos(m_ONE_ARGUMENT);
		break;
	case COSH:
		result = cosh(m_ONE_ARGUMENT);
		break;
	case EXP:
		result = exp(m_ONE_ARGUMENT);
		break;
	case FABS:
		result = fabs(m_ONE_ARGUMENT);
		break;
	case FLOOR:
		result = floor(m_ONE_ARGUMENT);
		break;
	case FMOD:
		result = fmod(m_ONE_ARGUMENT, m_TWO_ARGUMENT);
		break;
	case LOG:
		result = log(m_ONE_ARGUMENT);
		break;
	case LOG10:
		result = log10(m_ONE_ARGUMENT);
		break;
	case POW:
		result = pow(m_ONE_ARGUMENT, m_TWO_ARGUMENT);
		break;
	case SIN:
		result = sin(m_ONE_ARGUMENT);
		break;
	case SINH:
		result = sinh(m_ONE_ARGUMENT);
		break;
	case SQRT:
		result = sqrt(m_ONE_ARGUMENT);
		break;
	case TAN:
		result = tan(m_ONE_ARGUMENT);
		break;
	case TANH:
		result = tanh(m_ONE_ARGUMENT);
		break;
	}

	switch (m_Number_Function_Selected)
	{
	case ACOS:
	case ASIN:
	case ATAN:
	case ATAN2:
	case COS:
	case COSH:
	case SIN:
	case SINH:
	case TAN:
	case TANH:
		result = (result * 180) / 3.14;
	}

	if (One_Argument == TRUE) {

		m_Result_Show.Format(L"Результаты:\n%s(%g) = %g", m_Name_Function, m_ONE_ARGUMENT, result);

	}

	else if (One_Argument == FALSE) {

		m_Result_Show.Format(L"Результаты:\n%s(%g, %g) = %g", m_Name_Function, m_ONE_ARGUMENT, m_TWO_ARGUMENT, result);

	}
	else {
		m_Result_Show = L"Результаты:\nФункция не выбрана";
	}
	
	// Окно показа результата
	GetDlgItem(IDC_RESULT_BORD)->ShowWindow(SW_SHOW);

	// Блокировка кнопки вычислить
	GetDlgItem(IDC_BTN_RESULT)->EnableWindow(FALSE);

	// Кнопки "Начать программу заново" и "Сохранить результаты в файл"
	GetDlgItem(IDC_BTN_RESET)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_SAVE_FILE)->ShowWindow(SW_SHOW);

	// Окно показа списка функций
	GetDlgItem(IDC_STATIC_TEXT_LIST_FUNCTION)->ShowWindow(FALSE);

	UpdateData(FALSE);
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

	// Кнопка сохранения в файл
	GetDlgItem(IDC_BTN_SAVE_FILE)->EnableWindow(FALSE);
}


void CFunction_CalculateDlg::OnBnClickedBtnReset()
{
	UpdateData(TRUE);

	if (MessageBox(L"Вы уверены, что хотите начать программу заново?", L"Начать программу заново",
		MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	// Настройки по-умолчанию
	m_ComboList = FALSE;
	m_EditControl = TRUE;
	m_NameFunctionEditControl = L"";
	m_ComboListSelection = L"";
	m_ONE_ARGUMENT = 0;
	m_TWO_ARGUMENT = 0;
	m_Number_Function_Selected = ERRORs;
	One_Argument = FALSE;
	m_Result_Show = L"Результаты:";
	m_Name_Function = L"";

	// Выбор по-умолчанию за комбо-лист
	OnBnClickedRadioComboList();

	// Кнопка выбора функции
	GetDlgItem(IDC_BTN_SELECT_FUNCTION)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_SELECT_FUNCTION)->ShowWindow(SW_SHOW);

	// Поля редактирования для аргументов
	GetDlgItem(IDC_EDIT_ONE_ARGUMENT)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_TWO_ARGUMENT)->ShowWindow(FALSE);

	// Окна с текстом для полей редактирования
	GetDlgItem(IDC_STATIC_TEXT_ONE_ARGUMENT)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_TEXT_TWO_ARGUMENT)->ShowWindow(FALSE);

	// Окно показа результата
	GetDlgItem(IDC_RESULT_BORD)->ShowWindow(FALSE);

	// Кнопки "Вычислить", "Сохранить результаты в файл", "Начать программу заново"
	GetDlgItem(IDC_BTN_RESET)->ShowWindow(FALSE);
	GetDlgItem(IDC_BTN_SAVE_FILE)->ShowWindow(FALSE);
	GetDlgItem(IDC_BTN_RESULT)->ShowWindow(FALSE);

	GetDlgItem(IDC_BTN_RESET)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_SAVE_FILE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_RESULT)->EnableWindow(TRUE);

	// Выбор стиля ввода функции
	GetDlgItem(IDC_GROUP_VIBOR)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_COMBO_LIST)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_CONTROL)->EnableWindow(TRUE);

	UpdateData(FALSE);
}
