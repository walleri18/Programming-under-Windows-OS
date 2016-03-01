#include <afxwin.h>
#include <afxext.h>
#include "resource.h"

// ����� ����� ������� �2
class CMyDialog : public CDialog
{
public:
	CMyDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL);
	~CMyDialog();

	// �������������
	virtual BOOL OnInitDialog();

	// ������� �� ������ ������ Ok
	virtual void OnOK();

	// ������ ������
	CString GetString();

private:
	// ��������� �� ������� ����������
	CListBox* cListBox;

	// ������������ �������� �� �������� ListBox
	CString csListTextItem;
};

CMyDialog::~CMyDialog()
{
	if (cListBox)
		delete cListBox;
}

CString CMyDialog::GetString()
{
	return csListTextItem;
}

// ��� ������� ������ Ok
void CMyDialog::OnOK()
{
	// ���� ������� ������ �� ������
	if (cListBox->GetCurSel() == LB_ERR)
		MessageBox(L"Select Item List Box");

	else {

		// �������� ������
		cListBox->GetText(cListBox->GetCurSel(), csListTextItem);

		// �������� ������� ������
		CDialog::OnOK();
	}
}

CMyDialog::CMyDialog(UINT nIDTemplate, CWnd* pParentWnd)
	: CDialog(nIDTemplate, pParentWnd), cListBox(NULL) {}

// �������������
BOOL CMyDialog::OnInitDialog()
{
	// �������� ������������� ������
	CDialog::OnInitDialog();

	// ���������� ����
	CenterWindow();

	// ���������� ��� ������
	CRect rect(10, 10, 100, 100);

	// ������ ������ ������
	cListBox = new CListBox();

	// ������ ������ � ��������� ��� � ���������������
	cListBox->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | 
		LBS_NOTIFY | WS_VSCROLL | WS_BORDER, 
		rect, this, IDC_LIST1);

	if (cListBox) {

		// ��������� ������
		cListBox->AddString(L"God");
		cListBox->AddString(L"Bad");
		cListBox->AddString(L"VOID");

		// �������� �������������
		return TRUE;
	}

	else
		// ��������� �������������
		return FALSE;
}

// ���� ����� ������
class CMyPaintDC : public CPaintDC
{
public:
	// ����������� ��� �������������
	CMyPaintDC(CWnd* pWnd);

	// ������� ��������� ����� ������
	void DrawCross(int iPosX, int iPosY);
};

CMyPaintDC::CMyPaintDC(CWnd* pWnd) : CPaintDC(pWnd) {}

void CMyPaintDC::DrawCross(int iPosX, int iPosY)
{
	MoveTo(iPosX - 50, iPosY);
	LineTo(iPosX + 50, iPosY);

	MoveTo(iPosX, iPosY - 50);
	LineTo(iPosX, iPosY + 50);
}

// ���� ����� ������
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
	// ������ ������ ������ ������ ����������� ����
	CMyDialog about(IDD_DIALOG2);
	if (about.DoModal() == IDOK)

		// ���������� ����������
		MessageBox(about.GetString());
	
}

CMainWnd::CMainWnd() : blMenu(FALSE)
{
	// �������� ���� ���������
	Create(NULL, L"Step_Thirteen", WS_OVERLAPPEDWINDOW, rectDefault,
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
	// ���������� ��� ����� ������
	CMyPaintDC dc(this);

	// ����������� ����
	CPen MyPen(PS_DASHDOT, 1, RGB(0, 255, 0));

	// �������� ���� ��� �������������
	dc.SelectObject(MyPen);

	for (int x = 1; x < 400; x += 50)
		dc.DrawCross(x + 100, x + 100);

	//// ��������� ��������� ����������, �� ��� ��������
	//CPaintDC dc(this);

	////����� ������ � ����������� ���������
	//dc.TextOutW(200, 200, L"Hello MFC Programm");

	//dc.TextOutW(200, 216, L"�����: ����� �������");

	////������ �������� �������� �����
	//dc.MoveTo(600, 300);

	////�� ���� ����� ����� �� ����� ������ � �� ���� ����� ������
	//dc.LineTo(600, 55);

	////�������
	//dc.LineTo(0, 55);

	//dc.LineTo(0, 300);

	//dc.LineTo(600, 300);

	////������ ������: ����� ������
	//dc.TextOutW(200, 200, L"TextOut Samples");

	//// ������ ������: ����� �����
	//dc.SetPixel(200, 200, RGB(255, 0, 0));

	//// ������ ������: ����� ���� ����������
	//dc.Arc(200, 200, 100, 100, 400, 400, 10, 10);

	//// �������� ������: ����� ��������� ����
	//dc.Chord(250, 250, 100, 100, 400, 400, 10, 10);

	//// ����� ������: ����� ��������
	//dc.Ellipse(450, 450, 50, 150);

	//// ������ ������: ����� �����
	//dc.MoveTo(200, 200);
	//dc.LineTo(100, 100);
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