
// Function_Calculate.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CFunction_CalculateApp:
// О реализации данного класса см. Function_Calculate.cpp
//

class CFunction_CalculateApp : public CWinApp
{
public:
	CFunction_CalculateApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CFunction_CalculateApp theApp;