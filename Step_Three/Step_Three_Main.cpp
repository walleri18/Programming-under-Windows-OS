#include <afxwin.h>

// �������������� ��� ������
#define IDC_MYBUTTON 100

// ����������� ��� ���� ��������������
#define IDC_MYEDIT 102

class CMainWnd : public CFrameWnd
{
public:
	CMainWnd();

	afx_msg void OnLButtonDblClk(UINT, CPoint);
	afx_msg void OnRButtonDblClk(UINT, CPoint);
	afx_msg void OnKeyDown(UINT, UINT, UINT);

	~CMainWnd();
private:
	// ��������� �� ������ �������
	CStatic* MyStatic;

	// ��������� �� ������ ������
	CButton* MyButton;

	// ��������� �� ������ ���� ��������������
	CEdit*	 MyEdit;

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
END_MESSAGE_MAP()

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
	Create(NULL, L"Step_Three", WS_OVERLAPPEDWINDOW, rectDefault,
		NULL, NULL);

	// ������ ������ �������
	MyStatic = new CStatic();
	if (MyStatic != NULL)
		MyStatic->Create(L"MyStatic", WS_CHILD | WS_VISIBLE |
			SS_CENTER, CRect(10, 10, 100, 50), this);

	// ������ ������ ������
	MyButton = new CButton();
	if (MyButton != NULL)
		MyButton->Create(L"MyButton", WS_CHILD | WS_VISIBLE |
			SS_CENTER, CRect(120, 10, 220, 50), this, IDC_MYBUTTON);

	// ������ ������ ���� ��������������
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