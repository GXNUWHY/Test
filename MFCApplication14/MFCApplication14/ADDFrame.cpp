// ADDFrame.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication14.h"
#include "ADDFrame.h"
#include "afxdialogex.h"


// ADDFrame 对话框

IMPLEMENT_DYNAMIC(ADDFrame, CDialogEx)

ADDFrame::ADDFrame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
	, x(0)
	, ss(_T(""))
{

}

ADDFrame::~ADDFrame()
{
}

void ADDFrame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_Text(pDX, IDC_EDIT2, x);
	DDX_Text(pDX, IDC_EDIT3, ss);
}


BEGIN_MESSAGE_MAP(ADDFrame, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ADDFrame::OnBnClickedButton1)
END_MESSAGE_MAP()


// ADDFrame 消息处理程序


void ADDFrame::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	ss.Format(_T("%s%d"), s, x);
	this->UpdateData(false);
}
