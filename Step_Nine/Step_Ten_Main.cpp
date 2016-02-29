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
	void MenuSwitch();
	afx_msg void OnPaint();
	~CMainWnd();
private:
	// ����� ���� ������������ (TRUE = IDR_MENU, FALSE = IDR_MENU_RUS)
	BOOL blMenu;

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

	// ������������� ����� ����
	ON_COMMAND(ID_FILE_SWITCH, MenuSwitch)

	// ����������� ������
	ON_WM_PAINT()
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
	// ������ ����� ������� ����������� ����
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
	// �������� ���� ���������
	Create(NULL, L"Step_One", WS_OVERLAPPEDWINDOW, rectDefault,
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

	// ������ ���������� �� ���������������, ��� ��� �� ������� ������ ����
	blMenu = !blMenu;

	// ������������� ���� �� �����
	SetMenu(&m_wndMenu);
}

void CMainWnd::MenuExit()
{
	// ���������� ����
	DestroyWindow();
}

void CMainWnd::OnPaint()
{
	// ��������� ��������� ����������, �� ��� ��������
	CPaintDC dc(this);

	// ����� ������ � ����������� ���������
	dc.TextOutW(200, 200, L"Hello MFC Programm");
	
	dc.TextOutW(200, 216, L"�����: ����� �������");

	// ������ �������� �������� �����
	dc.MoveTo(600, 300);

	// �� ���� ����� ����� �� ����� ������ � �� ���� ����� ������
	dc.LineTo(600, 55);

	// �������
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