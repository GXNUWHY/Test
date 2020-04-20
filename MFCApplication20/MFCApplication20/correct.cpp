// correct.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication20.h"
#include "correct.h"
#include "afxdialogex.h"


// correct 对话框

IMPLEMENT_DYNAMIC(correct, CDialogEx)

correct::correct(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

correct::~correct()
{
}

void correct::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(correct, CDialogEx)
END_MESSAGE_MAP()


// correct 消息处理程序
