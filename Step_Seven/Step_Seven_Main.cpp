#include <afxwin.h>
#include <afxext.h>
#include "resource.h"

// �������������� ��� ������
#define IDC_MYBUTTON 100

// ����������� ��� ���� ��������������
#define IDC_MYEDIT 102

class CMyButton : public CButton
{
public:
	afx_msg void OnLButtonDblClk(UINT, CPoint);
	afx_msg void OnRButtonDblClk(UINT, CPoint);
private:

	// ���������� ����� ���������
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

// ����� ���������
BEGIN_MESSAGE_MAP(CMyButton, CButton)
	// ��������� �� ����� ������ ����
	ON_WM_LBUTTONDBLCLK()

	// ��������� �� ������ ������ ����
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
	// ��������� �� ������ �������
	CStatic* MyStatic;

	// ��������� �� ������ ������
	CMyButton* MyButton;

	// ��������� �� ������ ���� ��������������
	CEdit*	 MyEdit;

	// ����� ������ ���������
	CStatusBar m_wndStatusBar;

	// ����� ����
	CMenu m_wndMenu;

	// �������������� ����� ���������
	DECLARE_MESSAGE_MAP();
};

// ����� ���������
BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)
	// ��������� ��� ������� ����� ������ ����
	ON_WM_LBUTTONDBLCLK()

	// ��������� ��� ������� ������ ������ ����
	ON_WM_RBUTTONDBLCLK()

	// ������� �� ������� ������� ����������
	ON_WM_KEYDOWN()

	// ������� �������� ����
	ON_WM_CREATE()

	// ��������� �� ������� ����
	ON_COMMAND(ID_FILE_EXIT, MenuExit)
END_MESSAGE_MAP()

int CMainWnd::OnCreate(LPCREATESTRUCT lpCreateScruct)
{
	if (CFrameWnd::OnCreate(lpCreateScruct) == -1)
		return -1;
	else {
		m_wndStatusBar.Create(this);

		// ��������� ���� �� ������ �������
		m_wndMenu.LoadMenuW(IDR_MENU);

		// ������������� ���� �� �����
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
	// �������� ���� ���������
	Create(NULL, L"Step_Seven", WS_OVERLAPPEDWINDOW, rectDefault,
		NULL, NULL);

	// ������ ������ �������
	MyStatic = new CStatic();
	if (MyStatic != NULL)
		MyStatic->Create(L"MyStatic", WS_CHILD | WS_VISIBLE |
			SS_CENTER, CRect(10, 10, 100, 50), this);

	// ������ ������ ������
	MyButton = new CMyButton();
	if (MyButton != NULL)
		MyButton->Create(L"MyButton", WS_CHILD | WS_VISIBLE |
			SS_CENTER, CRect(120, 10, 220, 50), this, IDC_MYBUTTON);

	// ������ ������ ���� ��������������
	MyEdit = new CEdit();
	if (MyEdit != NULL)
		MyEdit->Create(WS_CHILD | WS_VISIBLE | WS_BORDER,
			CRect(240, 10, 340, 50), this, IDC_MYEDIT);
}

void CMainWnd::MenuExit()
{
	// ���������� ����
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