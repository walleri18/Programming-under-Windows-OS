
// Function_Calculate.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CFunction_CalculateApp:
// � ���������� ������� ������ ��. Function_Calculate.cpp
//

class CFunction_CalculateApp : public CWinApp
{
public:
	CFunction_CalculateApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CFunction_CalculateApp theApp;