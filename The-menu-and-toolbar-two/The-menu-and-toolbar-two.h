
// The-menu-and-toolbar-two.h : главный файл заголовка для приложения The-menu-and-toolbar-two
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CThemenuandtoolbartwoApp:
// О реализации данного класса см. The-menu-and-toolbar-two.cpp
//

class CThemenuandtoolbartwoApp : public CWinApp
{
public:
	CThemenuandtoolbartwoApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CThemenuandtoolbartwoApp theApp;
