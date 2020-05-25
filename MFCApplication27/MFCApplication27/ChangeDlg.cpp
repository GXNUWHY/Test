// ChangeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication27.h"
#include "ChangeDlg.h"
#include "afxdialogex.h"


// ChangeDlg 对话框

IMPLEMENT_DYNAMIC(ChangeDlg, CDialogEx)

ChangeDlg::ChangeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, number(_T(""))
	, name(_T(""))
	, age(_T(""))
	, picpath(_T(""))
{

}

ChangeDlg::~ChangeDlg()
{
}

void ChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, number);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, age);
	DDX_Text(pDX, IDC_EDIT4, picpath);
}


BEGIN_MESSAGE_MAP(ChangeDlg, CDialogEx)
END_MESSAGE_MAP()


// ChangeDlg 消息处理程序
