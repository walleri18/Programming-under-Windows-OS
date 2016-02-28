#include <afxwin.h>

class CMainWnd : public CFrameWnd
{
public:
	CMainWnd();
};

CMainWnd::CMainWnd()
{
	// �������� ���� ���������
	Create(NULL, L"Step_One", WS_OVERLAPPEDWINDOW, rectDefault,
		NULL, NULL);
}

class CMyApp : public CWinApp
{
public:
	CMyApp();
	BOOL InitInstance();// ����������� �������������
};

CMyApp::CMyApp() {}

BOOL CMyApp::InitInstance()
{
	// ������ ����� ����
	m_pMainWnd = new CMainWnd();

	// ��������� �� ������������
	ASSERT(m_pMainWnd);

	// ���������� ���� �� ������
	m_pMainWnd->ShowWindow(SW_SHOW);

	// ��������� ����
	m_pMainWnd->UpdateWindow();

	// ���������� ������������� ���������, � ��� ��� ���� ������� �������
	return TRUE;
}

// ���������� ��� ������� ����������
CMyApp theApp;