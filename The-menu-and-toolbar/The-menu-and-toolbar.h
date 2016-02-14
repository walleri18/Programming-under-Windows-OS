
// The-menu-and-toolbar.h : главный файл заголовка для приложения The-menu-and-toolbar
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CThemenuandtoolbarApp:
// О реализации данного класса см. The-menu-and-toolbar.cpp
//

class CThemenuandtoolbarApp : public CWinApp
{
public:
	CThemenuandtoolbarApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CThemenuandtoolbarApp theApp;
