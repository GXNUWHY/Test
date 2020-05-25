// SearchDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication27.h"
#include "SearchDlg.h"
#include "afxdialogex.h"


// SearchDlg 对话框

IMPLEMENT_DYNAMIC(SearchDlg, CDialogEx)

SearchDlg::SearchDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, where(_T(""))
{

}

SearchDlg::~SearchDlg()
{
}

void SearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, where);
}


BEGIN_MESSAGE_MAP(SearchDlg, CDialogEx)
END_MESSAGE_MAP()


// SearchDlg 消息处理程序
