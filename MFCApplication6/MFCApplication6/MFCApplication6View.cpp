﻿
// MFCApplication6View.cpp: CMFCApplication6View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication6.h"
#define PI 3.14
#endif

#include "MFCApplication6Doc.h"
#include "MFCApplication6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6View

IMPLEMENT_DYNCREATE(CMFCApplication6View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication6View, CView)
	//ON_COMMAND(ID_MIDPOINTELLIPSE, &CMFCApplication6View::OnMidpointellipse)
END_MESSAGE_MAP()

// CMFCApplication6View 构造/析构

CMFCApplication6View::CMFCApplication6View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication6View::~CMFCApplication6View()
{
}

BOOL CMFCApplication6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6View 绘图

void CMFCApplication6View::OnDraw(CDC* pDC)
{
	CMFCApplication6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int xc, x0 = 400, a = 200, b = 100, yc, y0 = 400, angle = 0;


	for (xc = x0 + a, yc = y0; angle <= 360; angle += 10) {

		OnMidpointellipse2(a, b, xc, yc);
		//pDC->SetPixel(xc, yc, 0);

		xc = x0 + cos((float)angle / 180 * PI) * a;
		yc = y0 + sin((float)angle / 180 * PI) * b;
	}


}


// CMFCApplication6View 诊断

#ifdef _DEBUG
void CMFCApplication6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6Doc* CMFCApplication6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6Doc)));
	return (CMFCApplication6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6View 消息处理程序


/*void CMFCApplication6View::OnMidpointellipse()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	
	int c = RGB(0, 0, 0);
	double d1, d2;
	int x, y;
	x = 0;
	y = b;
	d1 = b * b + a * a * (-b + 0.25);
	pDC->SetPixel(x + 300, y + 200, c);
	pDC->SetPixel(-x + 300, y + 200, c);
	pDC->SetPixel(x + 300, -y + 200, c);
	pDC->SetPixel(-x + 300, -y + 200, c);
	while (b * b * (x + 1) < a * a * (y - 0.5)) {
		if (d1 < 0) {
			d1 += b * b * (2 * x + 3);
			++x;
		}
		else {
			d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
			++x;
			--y;
		}
		pDC->SetPixel(x + 300, y + 200, c);
		pDC->SetPixel(-x + 300, y + 200, c);
		pDC->SetPixel(x + 300, -y + 200, c);
		pDC->SetPixel(-x + 300, -y + 200, c);
	}

	d2 = sqrt(b * (x + 0.5)) + a * (y - 1) - a * b;
	while (y > 0) {
		if (d2 < 0) {
			d2 += b * b*(2 * x + 2) + a * a*(-2 * y + 3);
			++x;
			--y;
		}
		else {
			d2 += a * a*(-2 * y + 3);
			--y;
		}
		pDC->SetPixel(x + 300, y + 200, c);
		pDC->SetPixel(-x + 300, y + 200, c);
		pDC->SetPixel(x + 300, -y + 200, c);
		pDC->SetPixel(-x + 300, -y + 200, c);
	}
}*/


void CMFCApplication6View::OnMidpointellipse2(int a, int b, int xc, int yc)
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();

	int c = RGB(0, 0, 0);
	double d1, d2;
	int x, y;
	x = 0;
	y = b;
	d1 = b * b + a * a * (-b + 0.25);
	pDC->SetPixel(x + xc, y + yc, c);
	pDC->SetPixel(-x + xc, y + yc, c);
	pDC->SetPixel(x + xc, -y + yc, c);
	pDC->SetPixel(-x + xc, -y + yc, c);
	while (b * b * (x + 1) < a * a * (y - 0.5)) {
		if (d1 < 0) {
			d1 += b * b * (2 * x + 3);
			++x;
		}
		else {
			d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
			++x;
			--y;
		}
		pDC->SetPixel(x + xc, y + yc, c);
		pDC->SetPixel(-x + xc, y + yc, c);
		pDC->SetPixel(x + xc, -y + yc, c);
		pDC->SetPixel(-x + xc, -y + yc, c);
	}

	d2 = sqrt(b * (x + 0.5)) + a * (y - 1) - a * b;
	while (y > 0) {
		if (d2 < 0) {
			d2 += b * b*(2 * x + 2) + a * a*(-2 * y + 3);
			++x;
			--y;
		}
		else {
			d2 += a * a*(-2 * y + 3);
			--y;
		}
		pDC->SetPixel(x + xc, y + yc, c);
		pDC->SetPixel(-x + xc, y + yc, c);
		pDC->SetPixel(x + xc, -y + yc, c);
		pDC->SetPixel(-x + xc, -y + yc, c);
	}
}
