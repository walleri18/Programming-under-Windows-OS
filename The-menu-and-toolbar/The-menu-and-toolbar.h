
// The-menu-and-toolbar.h : ������� ���� ��������� ��� ���������� The-menu-and-toolbar
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CThemenuandtoolbarApp:
// � ���������� ������� ������ ��. The-menu-and-toolbar.cpp
//

class CThemenuandtoolbarApp : public CWinApp
{
public:
	CThemenuandtoolbarApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CThemenuandtoolbarApp theApp;
