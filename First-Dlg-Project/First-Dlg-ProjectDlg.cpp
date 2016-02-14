
// First-Dlg-ProjectDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "First-Dlg-Project.h"
#include "First-Dlg-ProjectDlg.h"
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


// диалоговое окно CFirstDlgProjectDlg



CFirstDlgProjectDlg::CFirstDlgProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FIRSTDLGPROJECT_DIALOG, pParent)
	, m_Hours(1)
	, m_Minutes(2)
	, m_Seconds(3)
	, m_Trend_TOSECOND(FALSE)
	, m_Trend_INVERSION(FALSE)
	, m_Count_Seconds(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFirstDlgProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HOURSE, m_Hours);
	DDV_MinMaxLong(pDX, m_Hours, 0, LONG_MAX);
	DDX_Text(pDX, IDC_EDIT_MINUTE, m_Minutes);
	DDV_MinMaxLong(pDX, m_Minutes, 0, 59);
	DDX_Text(pDX, IDC_EDIT_SECONDS, m_Seconds);
	DDV_MinMaxLong(pDX, m_Seconds, 0, 59);
	DDX_Radio(pDX, IDC_RADIO_TOSECOND, m_Trend_TOSECOND);
	DDX_Radio(pDX, IDC_RADIO_INVERS, m_Trend_INVERSION);
	DDX_Text(pDX, IDC_RESULT, m_Count_Seconds);
	DDV_MinMaxUInt(pDX, m_Count_Seconds, 0, LONG_MAX);
}

BEGIN_MESSAGE_MAP(CFirstDlgProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CFirstDlgProjectDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_RADIO_TOSECOND, &CFirstDlgProjectDlg::OnBnClickedRadioTosecond)
	ON_BN_CLICKED(IDC_RADIO_INVERS, &CFirstDlgProjectDlg::OnBnClickedRadioInvers)
	ON_BN_CLICKED(IDC_BTN_PROGRESS, &CFirstDlgProjectDlg::OnBnClickedBtnProgress)
END_MESSAGE_MAP()


// обработчики сообщений CFirstDlgProjectDlg

BOOL CFirstDlgProjectDlg::OnInitDialog()
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
	m_Trend_TOSECOND = FALSE;
	m_Trend_INVERSION = TRUE;
	UpdateData(FALSE);
	GetDlgItem(IDC_RESULT)->EnableWindow(FALSE);
	OnBnClickedRadioInvers();

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CFirstDlgProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFirstDlgProjectDlg::OnPaint()
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
HCURSOR CFirstDlgProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFirstDlgProjectDlg::OnBnClickedExit()
{
	if (MessageBox(L"Вы хотите выйти из приложения?", L"Выход",
		MB_YESNO | MB_ICONQUESTION) == IDYES)
		OnOK();
}

void CFirstDlgProjectDlg::OnBnClickedRadioTosecond()
{
	UpdateData(TRUE);

	m_Trend_TOSECOND = FALSE;
	m_Trend_INVERSION = TRUE;

	GetDlgItem(IDC_RESULT)->EnableWindow(FALSE);

	GetDlgItem(IDC_EDIT_HOURSE)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_MINUTE)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_SECONDS)->EnableWindow(TRUE);

	UpdateData(FALSE);
}

void CFirstDlgProjectDlg::OnBnClickedRadioInvers()
{
	UpdateData(TRUE);

	m_Trend_TOSECOND = TRUE;
	m_Trend_INVERSION = FALSE;

	GetDlgItem(IDC_RESULT)->EnableWindow(TRUE);

	GetDlgItem(IDC_EDIT_HOURSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_MINUTE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SECONDS)->EnableWindow(FALSE);

	UpdateData(FALSE);
}

void CFirstDlgProjectDlg::OnBnClickedBtnProgress()
{
	UpdateData(TRUE);

	if (m_Trend_TOSECOND == FALSE) {

		m_Count_Seconds = m_Hours * 3600 + m_Minutes * 60
			+ m_Seconds;

	}
	else if (m_Trend_INVERSION == FALSE) {

		m_Hours = m_Count_Seconds / 3600;
		m_Minutes = (m_Count_Seconds % 3600) / 60;
		m_Seconds = (m_Count_Seconds % 3600) % 60;

	}

	UpdateData(FALSE);

}
