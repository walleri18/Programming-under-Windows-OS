#pragma once


// ���������� ���� CExtensive

class CExtensive : public CDialog
{
	DECLARE_DYNAMIC(CExtensive)

public:
	CExtensive(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CExtensive();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXTENSIVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// ��������� ������ �����
	int m_extensive;
};
