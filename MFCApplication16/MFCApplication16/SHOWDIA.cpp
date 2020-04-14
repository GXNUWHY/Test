// SHOWDIA.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication16.h"
#include "SHOWDIA.h"
#include "afxdialogex.h"


// SHOWDIA 对话框

IMPLEMENT_DYNAMIC(SHOWDIA, CDialogEx)

SHOWDIA::SHOWDIA(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, filename(_T(""))
{

}

SHOWDIA::~SHOWDIA()
{
}

void SHOWDIA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, filename);
	DDX_Control(pDX, IDC_LIST1, filename2);
}


BEGIN_MESSAGE_MAP(SHOWDIA, CDialogEx)
END_MESSAGE_MAP()


// SHOWDIA 消息处理程序


BOOL SHOWDIA::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	filename2.AddString(filename);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
