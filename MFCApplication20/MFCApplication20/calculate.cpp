// calculate.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication20.h"
#include "calculate.h"
#include "afxdialogex.h"
#include "correct.h"


// calculate 对话框

IMPLEMENT_DYNAMIC(calculate, CDialogEx)

calculate::calculate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(0)
	, b(0)
	, c(0)
	, x(0)
	, y(0)
{

}

calculate::~calculate()
{
}

void calculate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
	DDX_Text(pDX, IDC_EDIT4, x);
	DDX_Text(pDX, IDC_EDIT5, y);
}


BEGIN_MESSAGE_MAP(calculate, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &calculate::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &calculate::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &calculate::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &calculate::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &calculate::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &calculate::OnBnClickedButton6)
END_MESSAGE_MAP()


// calculate 消息处理程序


void calculate::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	c = a + b;
	this->UpdateData(false);
}


void calculate::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	c = a - b;
	this->UpdateData(false);
}


void calculate::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	c = a * b;
	this->UpdateData(false);
}


void calculate::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	if (b == 0) {
		correct corr;
		if (corr.DoModal() == IDOK);
	}
	else c = a / b;

	this->UpdateData(false);
}



void calculate::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	if (x < 0) {
		correct corr;
		if (corr.DoModal() == IDOK);
	}
	else y = sqrt(x);
	this->UpdateData(false);
}


void calculate::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	if (x == 0) {
		correct corr;
		if (corr.DoModal() == IDOK);
	}
	else y = 1.0 / x;
	this->UpdateData(false);
}
