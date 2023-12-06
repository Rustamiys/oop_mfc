
// lr4.h: основной файл заголовка для приложения lr4
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Clr4App:
// Сведения о реализации этого класса: lr4.cpp
//

class Clr4App : public CWinApp
{
public:
	Clr4App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clr4App theApp;
