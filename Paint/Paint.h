
// Paint.h : ������� ���� ��������� ��� ���������� Paint
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CPaintApp:
// � ���������� ������� ������ ��. Paint.cpp
//

class CPaintApp : public CWinApp
{
public:
	CPaintApp();


// ���������������
public:
	virtual BOOL InitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPaintApp theApp;
