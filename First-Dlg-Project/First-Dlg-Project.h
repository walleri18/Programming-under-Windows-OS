
// First-Dlg-Project.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CFirstDlgProjectApp:
// О реализации данного класса см. First-Dlg-Project.cpp
//

class CFirstDlgProjectApp : public CWinApp
{
public:
	CFirstDlgProjectApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CFirstDlgProjectApp theApp;