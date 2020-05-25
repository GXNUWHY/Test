// NewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication27.h"
#include "NewDlg.h"
#include "afxdialogex.h"


// NewDlg 对话框

IMPLEMENT_DYNAMIC(NewDlg, CDialogEx)

NewDlg::NewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, number(_T(""))
	, name(_T(""))
	, age(_T(""))
	, picapth(_T(""))
{

}

NewDlg::~NewDlg()
{
}

void NewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, number);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, age);
	DDX_Text(pDX, IDC_EDIT4, picapth);
}


BEGIN_MESSAGE_MAP(NewDlg, CDialogEx)
END_MESSAGE_MAP()


// NewDlg 消息处理程序
