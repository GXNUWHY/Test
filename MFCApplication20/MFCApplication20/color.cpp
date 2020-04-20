// color.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication20.h"
#include "color.h"
#include "afxdialogex.h"


// color 对话框

IMPLEMENT_DYNAMIC(color, CDialogEx)

color::color(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, R(0)
	, G(0)
	, B(0)
{

}

color::~color()
{
}

void color::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, R);
	DDV_MinMaxInt(pDX, R, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, G);
	DDV_MinMaxInt(pDX, G, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, B);
	DDV_MinMaxInt(pDX, B, 0, 255);
}


BEGIN_MESSAGE_MAP(color, CDialogEx)
END_MESSAGE_MAP()


// color 消息处理程序
