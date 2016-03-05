#include <afxwin.h>         // �������� � ����������� ���������� MFC
#include <afxext.h>         // ���������� MFC

#include "resource.h"

// ����� ������ (����)
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

// ���������� ������ ���������
static UINT indicators[] =
{
	IDS_STRING_THREE,
	IDS_STRING_TWO,
	IDS_STRING_ONE
};

CMainFrame::CMainFrame() : CFrameWnd()
{
	// �������� ���� ���������
	Create(NULL, L"SDI_Project", WS_OVERLAPPEDWINDOW, rectDefault,
		NULL, NULL);
}

// �������� ����
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// ������
	CFrameWnd::OnCreate(lpCreateStruct);

	// �������� � ������������� ������
	SetIcon(AfxGetApp()->LoadIcon(IDI_MAINFRAIM), TRUE);

	// ������ ������ ������������ � ��������� � �� ��������
	m_wndToolBar.Create(this);
	m_wndToolBar.LoadToolBar(IDR_TOOLBAR);

	// ������ ������ ���������
	m_wndStatusBar.Create(this);

	// ������������� ��� ������ ��������� ����������
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	m_wndStatusBar.SetPaneText(2, L"�����: ����� �������");

	// ������ ����
	m_wndMenu.CreateMenu();
	m_wndMenu.LoadMenu(IDR_MENU);
	SetMenu(&m_wndMenu);

	// ���������� ������ ������������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_TOP);
	EnableDocking(CBRS_ALIGN_TOP);
	DockControlBar(&m_wndToolBar, AFX_IDW_DOCKBAR_TOP);

	return 0;
}

// ����� ����������
class CApp : public CWinApp
{
public:
	CApp();
	virtual BOOL InitInstance();

};

CApp::CApp() : CWinApp() {}

BOOL CApp::InitInstance()
{
	// ��������
	CWinApp::InitInstance();

	// ������ ����
	m_pMainWnd = new CMainFrame();

	// ������ ��� �������
	m_pMainWnd->ShowWindow(SW_SHOW);

	// �������� ��������� (����������, ���������� � ��� �����)
	m_pMainWnd->UpdateWindow();

	// �� ���������
	return TRUE;
}

// ���������� ���������� ���������� ��� ������������� � WinMain
CApp theApp;

void CMainFrame::OnDeleteAble()
{
	MessageBox(L"����-�� �������))))", L"��-��-��", MB_OK | MB_ICONINFORMATION);
}

void CMainFrame::OnVibor()
{
	MessageBox(L"������ �����-�� �����()", L"��-��-��", MB_OK | MB_ICONERROR);
}

void CMainFrame::OnLime()
{
	MessageBox(L"���� ��� ���� ������", L"���-���", MB_OK | MB_ICONEXCLAMATION);
}

void CMainFrame::OnLove()
{
	MessageBox(L"����� �����, ��� �� ����������", L"��-��-��", MB_OK | MB_ICONQUESTION);
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
	message.Format(L"������ = %d, ������ = %d", cx, cy);

	m_wndStatusBar.SetPaneText(1, message);
}
