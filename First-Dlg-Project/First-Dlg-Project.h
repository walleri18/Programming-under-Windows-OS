
// First-Dlg-Project.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CFirstDlgProjectApp:
// � ���������� ������� ������ ��. First-Dlg-Project.cpp
//

class CFirstDlgProjectApp : public CWinApp
{
public:
	CFirstDlgProjectApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CFirstDlgProjectApp theApp;