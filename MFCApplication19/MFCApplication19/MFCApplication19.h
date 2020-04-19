
// MFCApplication19.h: MFCApplication19 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFCApplication19App:
// 有关此类的实现，请参阅 MFCApplication19.cpp
//

class CMFCApplication19App : public CWinApp
{
public:
	CMFCApplication19App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication19App theApp;
