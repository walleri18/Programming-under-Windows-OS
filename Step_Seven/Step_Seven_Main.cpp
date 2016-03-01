#include <afxwin.h>
#include <afxext.h>
#include "resource.h"

// Индентификатор для кнопки
#define IDC_MYBUTTON 100

// Индификатор для поля редактирования
#define IDC_MYEDIT 102

class CMyButton : public CButton
{
public:
	afx_msg void OnLButtonDblClk(UINT, CPoint);
	afx_msg void OnRButtonDblClk(UINT, CPoint);
private:

	// Декларация карты сообщений
	DECLARE_MESSAGE_MAP();
};

void CMyButton::OnLButtonDblClk(UINT, CPoint)
{
	MoveWindow(120, 50, 100, 40);
}

void CMyButton::OnRButtonDblClk(UINT, CPoint)
{
	MoveWindow(120, 10, 100, 40);
}

// Карта сообщений
BEGIN_MESSAGE_MAP(CMyButton, CButton)
	// Сообщение на левую кнопку мыши
	ON_WM_LBUTTONDBLCLK()

	// Сообщение на правую кнопку мыши
	ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()

class CMainWnd : public CFrameWnd
{
public:
	CMainWnd();

	afx_msg void OnLButtonDblClk(UINT, CPoint);
	afx_msg void OnRButtonDblClk(UINT, CPoint);
	afx_msg void OnKeyDown(UINT, UINT, UINT);
	int OnCreate(LPCREATESTRUCT lpCreateSctruct);
	void MenuExit();
	~CMainWnd();
private:
	// Указатель на объект надписи
	CStatic* MyStatic;

	// Указатель на объект кнопки
	CMyButton* MyButton;

	// Указатель на объект поля редактирования
	CEdit*	 MyEdit;

	// Класс панели состояния
	CStatusBar m_wndStatusBar;

	// Класс меню
	CMenu m_wndMenu;

	// Декларирование карты сообщений
	DECLARE_MESSAGE_MAP();
};

// Карта сообщений
BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)
	// Сообщение при нажатии левой кнопки мыши
	ON_WM_LBUTTONDBLCLK()

	// Сообщение при нажатии правой кнопки мыши
	ON_WM_RBUTTONDBLCLK()

	// Реакция на нажатие клавиши клавиатуры
	ON_WM_KEYDOWN()

	// Событие создания окна
	ON_WM_CREATE()

	// Обработка на нажатие меню
	ON_COMMAND(ID_FILE_EXIT, MenuExit)
END_MESSAGE_MAP()

int CMainWnd::OnCreate(LPCREATESTRUCT lpCreateScruct)
{
	if (CFrameWnd::OnCreate(lpCreateScruct) == -1)
		return -1;
	else {
		m_wndStatusBar.Create(this);

		// Загружаем меню из файлоы ресурса
		m_wndMenu.LoadMenuW(IDR_MENU);

		// Устанавливаем меню во фрейм
		SetMenu(&m_wndMenu);

		return 0;
	}
}

void CMainWnd::OnKeyDown(UINT, UINT, UINT)
{
	MessageBox(L" Key Button Down ");
}

void CMainWnd::OnRButtonDblClk(UINT, CPoint)
{
	MessageBox(L" Rigth Button Click ");
}

void CMainWnd::OnLButtonDblClk(UINT, CPoint)
{
	MessageBox(L" Left Button Click ");
}

CMainWnd::CMainWnd()
{
	// Создание окна программы
	Create(NULL, L"Step_Seven", WS_OVERLAPPEDWINDOW, rectDefault,
		NULL, NULL);

	// Создаём объект надписи
	MyStatic = new CStatic();
	if (MyStatic != NULL)
		MyStatic->Create(L"MyStatic", WS_CHILD | WS_VISIBLE |
			SS_CENTER, CRect(10, 10, 100, 50), this);

	// Создаём объект кнопки
	MyButton = new CMyButton();
	if (MyButton != NULL)
		MyButton->Create(L"MyButton", WS_CHILD | WS_VISIBLE |
			SS_CENTER, CRect(120, 10, 220, 50), this, IDC_MYBUTTON);

	// Создаём объект поля редактирования
	MyEdit = new CEdit();
	if (MyEdit != NULL)
		MyEdit->Create(WS_CHILD | WS_VISIBLE | WS_BORDER,
			CRect(240, 10, 340, 50), this, IDC_MYEDIT);
}

void CMainWnd::MenuExit()
{
	// Уничтожаем окно
	DestroyWindow();
}

CMainWnd::~CMainWnd()
{
	if (MyStatic)
		delete MyStatic;

	if (MyButton)
		delete MyButton;

	if (MyEdit)
		delete MyEdit;
}

class CMyApp : public CWinApp
{
public:
	CMyApp();
	BOOL InitInstance();// стандартная инициализация
};

CMyApp::CMyApp() {}

BOOL CMyApp::InitInstance()
{
	// Создаём класс окна
	m_pMainWnd = new CMainWnd();

	// Проверяем на правильность
	ASSERT(m_pMainWnd);

	// Показываем окно на экране
	m_pMainWnd->ShowWindow(SW_SHOW);

	// Обновляем окно
	m_pMainWnd->UpdateWindow();

	// Возвращаем положительный результат, о том что окно успешно создано
	return TRUE;
}

// Переменная для запуска приложения
CMyApp theApp;