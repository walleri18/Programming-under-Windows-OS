
// The-menu-and-toolbar-two.h : ������� ���� ��������� ��� ���������� The-menu-and-toolbar-two
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CThemenuandtoolbartwoApp:
// � ���������� ������� ������ ��. The-menu-and-toolbar-two.cpp
//

class CThemenuandtoolbartwoApp : public CWinApp
{
public:
	CThemenuandtoolbartwoApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CThemenuandtoolbartwoApp theApp;
