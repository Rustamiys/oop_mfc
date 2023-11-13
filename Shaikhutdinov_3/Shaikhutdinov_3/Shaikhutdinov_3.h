
// Shaikhutdinov_3.h: основной файл заголовка для приложения Shaikhutdinov_3
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CShaikhutdinov3App:
// Сведения о реализации этого класса: Shaikhutdinov_3.cpp
//

class CShaikhutdinov3App : public CWinApp
{
public:
	CShaikhutdinov3App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CShaikhutdinov3App theApp;
