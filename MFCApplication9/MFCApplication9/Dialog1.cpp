// Dialog1.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication9.h"
#include "Dialog1.h"
#include "afxdialogex.h"


// Dialog1 对话框

IMPLEMENT_DYNAMIC(Dialog1, CDialogEx)

Dialog1::Dialog1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, r(0)
{

}

Dialog1::~Dialog1()
{
}

void Dialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDV_MinMaxInt(pDX, x, 0, INT_MAX);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDV_MinMaxInt(pDX, y, 0, INT_MAX);
	DDX_Text(pDX, IDC_EDIT3, r);
	DDV_MinMaxInt(pDX, r, 50, INT_MAX);
}


BEGIN_MESSAGE_MAP(Dialog1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dialog1::OnBnClickedButton1)
END_MESSAGE_MAP()


// Dialog1 消息处理程序


void Dialog1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	int temp;
	temp = x;
	x = y;
	y = temp;
	this->UpdateData(false);
}
