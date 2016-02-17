
// SDI_First_Project_Two_Version.h : главный файл заголовка для приложения SDI_First_Project_Two_Version
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSDI_First_Project_Two_VersionApp:
// О реализации данного класса см. SDI_First_Project_Two_Version.cpp
//

class CSDI_First_Project_Two_VersionApp : public CWinApp
{
public:
	CSDI_First_Project_Two_VersionApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDI_First_Project_Two_VersionApp theApp;
