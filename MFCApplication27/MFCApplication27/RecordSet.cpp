// RecordSet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication27.h"
#include "RecordSet.h"
#include "afxdialogex.h"


// RecordSet �Ի���

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


// RecordSet ��Ϣ�������


BOOL RecordSet::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	for (int i = 0; i <= fieldnum + 1; ++i) {
		recordfield.AddString(recordarray[i]);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
