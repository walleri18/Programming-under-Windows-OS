#include <afxwin.h>

// Индентификатор для кнопки
#define IDC_MYBUTTON 100

// Индификатор для поля редактирования
#define IDC_MYEDIT 102

class CMainWnd : public CFrameWnd
{
public:
	CMainWnd();
	~CMainWnd();
private:
	// Указатель на объект надписи
	CStatic* MyStatic;

	// Указатель на объект кнопки
	CButton* MyButton;

	// Указатель на объект поля редактирования
	CEdit*	 MyEdit;
};

CMainWnd::CMainWnd()
{
	// Создание окна программы
	Create(NULL, L"Step_Two", WS_OVERLAPPEDWINDOW, rectDefault,
		NULL, NULL);

	// Создаём объект надписи
	MyStatic = new CStatic();
	if (MyStatic != NULL)
		MyStatic->Create(L"MyStatic", WS_CHILD | WS_VISIBLE |
			SS_CENTER, CRect(10, 10, 100, 50), this);

	// Создаём объект кнопки
	MyButton = new CButton();
	if (MyButton != NULL)
		MyButton->Create(L"MyButton", WS_CHILD | WS_VISIBLE |
			SS_CENTER, CRect(120, 10, 220, 50), this, IDC_MYBUTTON);

	// Создаём объект поля редактирования
	MyEdit = new CEdit();
	if (MyEdit != NULL)
		MyEdit->Create(WS_CHILD | WS_VISIBLE | WS_BORDER,
			CRect(240, 10, 340, 50), this, IDC_MYEDIT);
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