// DRAW.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication11.h"
#include "DRAW.h"
#include "afxdialogex.h"


// DRAW 对话框

IMPLEMENT_DYNAMIC(DRAW, CDialogEx)

DRAW::DRAW(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x1(0)
	, y1(0)
	, x2(0)
	, y2(0)
	, x3(0)
	, y3(0)
{

}

DRAW::~DRAW()
{
}

void DRAW::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x1);
	DDX_Text(pDX, IDC_EDIT4, y1);
	DDX_Text(pDX, IDC_EDIT2, x2);
	DDX_Text(pDX, IDC_EDIT5, y2);
	DDX_Text(pDX, IDC_EDIT3, x3);
	DDX_Text(pDX, IDC_EDIT6, y3);
}


BEGIN_MESSAGE_MAP(DRAW, CDialogEx)
END_MESSAGE_MAP()


// DRAW 消息处理程序
