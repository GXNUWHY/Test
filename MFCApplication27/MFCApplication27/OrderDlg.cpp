// OrderDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication27.h"
#include "OrderDlg.h"
#include "afxdialogex.h"


// OrderDlg 对话框

IMPLEMENT_DYNAMIC(OrderDlg, CDialogEx)

OrderDlg::OrderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, order(_T(""))
{

}

OrderDlg::~OrderDlg()
{
}

void OrderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, order);
}


BEGIN_MESSAGE_MAP(OrderDlg, CDialogEx)
END_MESSAGE_MAP()


// OrderDlg 消息处理程序
