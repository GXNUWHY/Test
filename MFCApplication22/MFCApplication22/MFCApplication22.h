
// MFCApplication22.h: MFCApplication22 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFCApplication22App:
// 有关此类的实现，请参阅 MFCApplication22.cpp
//

class CMFCApplication22App : public CWinApp
{
public:
	CMFCApplication22App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication22App theApp;
