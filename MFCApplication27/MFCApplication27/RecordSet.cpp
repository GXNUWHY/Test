// RecordSet.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication27.h"
#include "RecordSet.h"
#include "afxdialogex.h"


// RecordSet 对话框

IMPLEMENT_DYNAMIC(RecordSet, CDialogEx)

RecordSet::RecordSet(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

RecordSet::~RecordSet()
{
}

void RecordSet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, recordfield);
}


BEGIN_MESSAGE_MAP(RecordSet, CDialogEx)
END_MESSAGE_MAP()


// RecordSet 消息处理程序


BOOL RecordSet::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for (int i = 0; i <= fieldnum + 1; ++i) {
		recordfield.AddString(recordarray[i]);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
