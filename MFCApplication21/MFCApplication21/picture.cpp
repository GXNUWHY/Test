// picture.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication21.h"
#include "picture.h"
#include "afxdialogex.h"


// picture 对话框

IMPLEMENT_DYNAMIC(picture, CDialogEx)

picture::picture(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

picture::~picture()
{
}

void picture::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(picture, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &picture::OnBnClickedButton1)
END_MESSAGE_MAP()


// picture 消息处理程序


void picture::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CImage img;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	img.Load(path);
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
}
