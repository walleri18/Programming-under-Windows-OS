#pragma once


// диалоговое окно CExtensive

class CExtensive : public CDialog
{
	DECLARE_DYNAMIC(CExtensive)

public:
	CExtensive(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CExtensive();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXTENSIVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// Переенная ширины линии
	int m_extensive;
};
