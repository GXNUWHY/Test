
// MFCApplication30.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApplication30App: 
// �йش����ʵ�֣������ MFCApplication30.cpp
//

class CMFCApplication30App : public CWinApp
{
public:
	CMFCApplication30App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication30App theApp;