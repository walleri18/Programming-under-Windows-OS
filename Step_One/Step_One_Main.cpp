#include <afxwin.h>

class CMainWnd : public CFrameWnd
{
public:
	CMainWnd();
};

CMainWnd::CMainWnd()
{
	// Создание окна программы
	Create(NULL, L"Step_One", WS_OVERLAPPEDWINDOW, rectDefault,
		NULL, NULL);
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