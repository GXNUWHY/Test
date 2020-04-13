
// MFCApplication12.h: MFCApplication12 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFCApplication12App:
// 有关此类的实现，请参阅 MFCApplication12.cpp
//

class CMFCApplication12App : public CWinApp
{
public:
	CMFCApplication12App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication12App theApp;
