
// Project_UNI.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CProject_UNIApp:
// О реализации данного класса см. Project_UNI.cpp
//

class CProject_UNIApp : public CWinApp
{
public:
	CProject_UNIApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CProject_UNIApp theApp;