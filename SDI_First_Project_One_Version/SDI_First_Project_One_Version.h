
// SDI_First_Project_One_Version.h : ������� ���� ��������� ��� ���������� SDI_First_Project_One_Version
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CSDI_First_Project_One_VersionApp:
// � ���������� ������� ������ ��. SDI_First_Project_One_Version.cpp
//

class CSDI_First_Project_One_VersionApp : public CWinApp
{
public:
	CSDI_First_Project_One_VersionApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDI_First_Project_One_VersionApp theApp;
