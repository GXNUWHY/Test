
// MFCApplication24.h: MFCApplication24 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFCApplication24App:
// 有关此类的实现，请参阅 MFCApplication24.cpp
//

class CMFCApplication24App : public CWinApp
{
public:
	CMFCApplication24App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication24App theApp;
