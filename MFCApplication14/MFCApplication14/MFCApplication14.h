﻿
// MFCApplication14.h: MFCApplication14 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFCApplication14App:
// 有关此类的实现，请参阅 MFCApplication14.cpp
//

class CMFCApplication14App : public CWinApp
{
public:
	CMFCApplication14App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication14App theApp;
