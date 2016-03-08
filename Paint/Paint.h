
// Paint.h : главный файл заголовка для приложения Paint
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CPaintApp:
// О реализации данного класса см. Paint.cpp
//

class CPaintApp : public CWinApp
{
public:
	CPaintApp();


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPaintApp theApp;
