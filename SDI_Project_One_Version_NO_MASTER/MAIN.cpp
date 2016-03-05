#include <afxwin.h>         // основные и стандартные компоненты MFC
#include <afxext.h>         // расширения MFC

#include "resource.h"

// Класс фрейма (окна)
class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CMenu			  m_wndMenu;

	DECLARE_MESSAGE_MAP()

	afx_msg void OnDeleteAble();
	afx_msg void OnVibor();
	afx_msg void OnLime();
	afx_msg void OnLove();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_DELETE_ABLE, &CMainFrame::OnDeleteAble)
	ON_COMMAND(ID_VIBOR, &CMainFrame::OnVibor)
	ON_COMMAND(ID_LIME, &CMainFrame::OnLime)
	ON_COMMAND(ID_LOVE, &CMainFrame::OnLove)
	ON_WM_MOVE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// Индикаторы строки состояния
static UINT indicators[] =
{
	IDS_STRING_THREE,
	IDS_STRING_TWO,
	IDS_STRING_ONE
};

CMainFrame::CMainFrame() : CFrameWnd()
{
	// Создание окна программы
	Create(NULL, L"SDI_Project", WS_OVERLAPPEDWINDOW, rectDefault,
		NULL, NULL);
}

// Создание окна
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// Предок
	CFrameWnd::OnCreate(lpCreateStruct);

	// Загружем и устанавливаем иконку
	SetIcon(AfxGetApp()->LoadIcon(IDI_MAINFRAIM), TRUE);

	// Создаём Панель инструментов и загружаем её из ресурсов
	m_wndToolBar.Create(this);
	m_wndToolBar.LoadToolBar(IDR_TOOLBAR);

	// Создаём панель состояния
	m_wndStatusBar.Create(this);

	// Устанавливаем для панели состояния индикаторы
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	m_wndStatusBar.SetPaneText(2, L"Автор: Туров Виталий");

	// Создаём меню
	m_wndMenu.CreateMenu();
	m_wndMenu.LoadMenu(IDR_MENU);
	SetMenu(&m_wndMenu);

	// Закрепляем панель инструментов
	m_wndToolBar.EnableDocking(CBRS_ALIGN_TOP);
	EnableDocking(CBRS_ALIGN_TOP);
	DockControlBar(&m_wndToolBar, AFX_IDW_DOCKBAR_TOP);

	return 0;
}

// Класс приложения
class CApp : public CWinApp
{
public:
	CApp();
	virtual BOOL InitInstance();

};

CApp::CApp() : CWinApp() {}

BOOL CApp::InitInstance()
{
	// Родитель
	CWinApp::InitInstance();

	// Создаём окно
	m_pMainWnd = new CMainFrame();

	// Делаем его видимым
	m_pMainWnd->ShowWindow(SW_SHOW);

	// Начинаем обработку (обновление, прорисовка и так далее)
	m_pMainWnd->UpdateWindow();

	// Всё нормально
	return TRUE;
}

// Глобальная переменная приложения для использования в WinMain
CApp theApp;

void CMainFrame::OnDeleteAble()
{
	MessageBox(L"Чего-то удаляем))))", L"Ха-ха-ха", MB_OK | MB_ICONINFORMATION);
}

void CMainFrame::OnVibor()
{
	MessageBox(L"Делаем какой-то выбор()", L"Да-да-да", MB_OK | MB_ICONERROR);
}

void CMainFrame::OnLime()
{
	MessageBox(L"Съеш как лайм дружок", L"Мда-мда", MB_OK | MB_ICONEXCLAMATION);
}

void CMainFrame::OnLove()
{
	MessageBox(L"Весна весна, все ею заражаются", L"Да-да-да", MB_OK | MB_ICONQUESTION);
}

void CMainFrame::OnMove(int x, int y)
{
	CFrameWnd::OnMove(x, y);

	CString message;
	message.Format(L"x = %d, y = %d", x, y);

	m_wndStatusBar.SetPaneText(0, message);
}

void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

	CString message;
	message.Format(L"Ширина = %d, Высота = %d", cx, cy);

	m_wndStatusBar.SetPaneText(1, message);
}
