// EnlargeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication29.h"
#include "EnlargeDlg.h"
#include "afxdialogex.h"


// EnlargeDlg �Ի���

IMPLEMENT_DYNAMIC(EnlargeDlg, CDialogEx)

EnlargeDlg::EnlargeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

EnlargeDlg::~EnlargeDlg()
{
}

void EnlargeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EnlargeDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// EnlargeDlg ��Ϣ�������
void EnlargeDlg::draw_pic(CString file)
{
	//CDC *pDC = GetDC();
	//pDC->TextOutW(0, 0, file);
	CImage img;
	img.Load(file);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(rect);

	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio * h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sy = 0;
		sy = (rect.Height() - h) / 2;
	}
	img.Draw(pDC->m_hDC, sx, sy, w, h);

}

void EnlargeDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);

	draw_pic(filepath);
}
