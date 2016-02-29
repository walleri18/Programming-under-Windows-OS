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
	void MenuSwitch();
	afx_msg void OnPaint();
	~CMainWnd();
private:
	// Какое меню активировано (TRUE = IDR_MENU, FALSE = IDR_MENU_RUS)
	BOOL blMenu;

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

	// Переключением между меню
	ON_COMMAND(ID_FILE_SWITCH, MenuSwitch)

	// Перерисовка экрана
	ON_WM_PAINT()
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
	// Создаём класс объекта диалогового окна
	CDialog about(IDD_DIALOG);

	if (about.DoModal() == IDOK)
		MessageBox(L"Ok");

	else
		MessageBox(L"Cancel");
}

void CMainWnd::OnLButtonDblClk(UINT, CPoint)
{
	MessageBox(L" Left Button Click ");
}

CMainWnd::CMainWnd() : blMenu(FALSE)
{
	// Создание окна программы
	Create(NULL, L"Step_One", WS_OVERLAPPEDWINDOW, rectDefault,
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

void CMainWnd::MenuSwitch()
{
	m_wndMenu.DestroyMenu();
	switch (blMenu)
	{
	case TRUE:
		m_wndMenu.LoadMenuW(IDR_MENU);
		break;
	case FALSE:
		m_wndMenu.LoadMenuW(IDR_MENU_RUS);
		break;
	}

	// Меняем переменную на противоположную, так как мы выбрали другое меню
	blMenu = !blMenu;

	// Устанавливаем меню во фрейм
	SetMenu(&m_wndMenu);
}

void CMainWnd::MenuExit()
{
	// Уничтожаем окно
	DestroyWindow();
}

void CMainWnd::OnPaint()
{
	// Получение контекста устройства, то где рисовать
	CPaintDC dc(this);

	// Вывод текста с определённых координат
	dc.TextOutW(200, 200, L"Hello MFC Programm");
	
	dc.TextOutW(200, 216, L"Автор: Туров Виталий");

	// Откуда начинать рисовать линию
	dc.MoveTo(600, 300);

	// До куда вести линию от точки начала и от куда вести дальше
	dc.LineTo(600, 55);

	// Понятно
	dc.LineTo(0, 55);

	dc.LineTo(0, 300);

	dc.LineTo(600, 300);
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