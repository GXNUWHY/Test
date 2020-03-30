
// MFCApplication5View.cpp: CMFCApplication5View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication5.h"
#endif

#include "MFCApplication5Doc.h"
#include "MFCApplication5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5View

IMPLEMENT_DYNCREATE(CMFCApplication5View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication5View, CView)
	ON_COMMAND(ID_MIDPOINTCIRCLE, &CMFCApplication5View::OnMidpointcircle)
	ON_COMMAND(ID_BRESENHAMCIRCLE, &CMFCApplication5View::OnBresenhamcircle)
	ON_COMMAND(ID_DRAWWAVE, &CMFCApplication5View::OnDrawwave)
	ON_COMMAND(ID_DRAWCIRCIR, &CMFCApplication5View::OnDrawcircir)
	ON_COMMAND(ID_DRAWCIR, &CMFCApplication5View::OnDrawcir)
END_MESSAGE_MAP()

// CMFCApplication5View 构造/析构

CMFCApplication5View::CMFCApplication5View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication5View::~CMFCApplication5View()
{
}

BOOL CMFCApplication5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication5View 绘图

void CMFCApplication5View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication5View 诊断

#ifdef _DEBUG
void CMFCApplication5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication5Doc* CMFCApplication5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication5Doc)));
	return (CMFCApplication5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication5View 消息处理程序


void CMFCApplication5View::OnMidpointcircle()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int xc = 300, yc = 300, r = 50, c = 0;
	int x, y;
	float d;
	x = 0;
	y = r;
	d = 1.25 - r;
	pDC->SetPixel((xc + x), (yc + y), c);
	pDC->SetPixel((xc - x), (yc + y), c);
	pDC->SetPixel((xc + x), (yc - y), c);
	pDC->SetPixel((xc - x), (yc - y), c);
	pDC->SetPixel((xc + y), (yc + x), c);
	pDC->SetPixel((xc - y), (yc + x), c);
	pDC->SetPixel((xc + y), (yc - x), c);
	pDC->SetPixel((xc - y), (yc - x), c);

	while (x <= y) {
		if (d < 0) d += 2 * x + 3;
		else {
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
		pDC->SetPixel((xc + x), (yc + y), c);
		pDC->SetPixel((xc - x), (yc + y), c);
		pDC->SetPixel((xc + x), (yc - y), c);
		pDC->SetPixel((xc - x), (yc - y), c);
		pDC->SetPixel((xc + y), (yc + x), c);
		pDC->SetPixel((xc - y), (yc + x), c);
		pDC->SetPixel((xc + y), (yc - x), c);
		pDC->SetPixel((xc - y), (yc - x), c);
	}
}


void CMFCApplication5View::OnBresenhamcircle()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int xc = 100, yc = 100, radius = 50, c = 0;
	int x = 0, y = radius, p = 3 - 2 * radius;

	while (x < y) {
		pDC->SetPixel((xc + x), (yc + y), c);
		pDC->SetPixel((xc - x), (yc + y), c);
		pDC->SetPixel((xc + x), (yc - y), c);
		pDC->SetPixel((xc - x), (yc - y), c);
		pDC->SetPixel((xc + y), (yc + x), c);
		pDC->SetPixel((xc - y), (yc + x), c);
		pDC->SetPixel((xc + y), (yc - x), c);
		pDC->SetPixel((xc - y), (yc - x), c);

		if (p < 0) {
			p += 4 * x + 6;
		}
		else {
			p += 4 * (x - y) + 10;
			--y;
		}
		++x;
	}
	
	if (x == y) {
		pDC->SetPixel((xc + x), (yc + y), c);
		pDC->SetPixel((xc - x), (yc + y), c);
		pDC->SetPixel((xc + x), (yc - y), c);
		pDC->SetPixel((xc - x), (yc - y), c);
		pDC->SetPixel((xc + y), (yc + x), c);
		pDC->SetPixel((xc - y), (yc + x), c);
		pDC->SetPixel((xc + y), (yc - x), c);
		pDC->SetPixel((xc - y), (yc - x), c);
	}
}

void CMFCApplication5View::Bresenhamcircle(int xc , int yc, int radius, int c)
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int x = 0, y = radius, p = 3 - 2 * radius;

	while (x < y) {
		pDC->SetPixel((xc + x), (yc + y), c);
		pDC->SetPixel((xc - x), (yc + y), c);
		pDC->SetPixel((xc + x), (yc - y), c);
		pDC->SetPixel((xc - x), (yc - y), c);
		pDC->SetPixel((xc + y), (yc + x), c);
		pDC->SetPixel((xc - y), (yc + x), c);
		pDC->SetPixel((xc + y), (yc - x), c);
		pDC->SetPixel((xc - y), (yc - x), c);

		if (p < 0) {
			p += 4 * x + 6;
		}
		else {
			p += 4 * (x - y) + 10;
			--y;
		}
		++x;
	}

	if (x == y) {
		pDC->SetPixel((xc + x), (yc + y), c);
		pDC->SetPixel((xc - x), (yc + y), c);
		pDC->SetPixel((xc + x), (yc - y), c);
		pDC->SetPixel((xc - x), (yc - y), c);
		pDC->SetPixel((xc + y), (yc + x), c);
		pDC->SetPixel((xc - y), (yc + x), c);
		pDC->SetPixel((xc + y), (yc - x), c);
		pDC->SetPixel((xc - y), (yc - x), c);
	}
}

//填充颜色
void CMFCApplication5View::Bresenhamcircle2(int xc, int yc, int radius, int c)
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int x = 0, y = radius, p = 3 - 2 * radius;

	while (x < y) {

		Bresenhamcircle((xc + x), (yc + y), radius , c);
		Bresenhamcircle((xc - x), (yc + y), radius , c);
		Bresenhamcircle((xc + x), (yc - y), radius , c);
		Bresenhamcircle((xc - x), (yc - y), radius , c);
		Bresenhamcircle((xc + y), (yc + x), radius , c);
		Bresenhamcircle((xc - y), (yc + x), radius , c);
		Bresenhamcircle((xc + y), (yc - x), radius , c);
		Bresenhamcircle((xc - y), (yc - x), radius , c);

		if (p < 0) {
			p += 4 * x + 6;
		}
		else {
			p += 4 * (x - y) + 10;
			--y;
		}
		++x;
		c = (c + 12777215) % 16777215;
	}

	if (x == y) {

		Bresenhamcircle((xc + x), (yc + y), radius / 10, c);
		Bresenhamcircle((xc - x), (yc + y), radius / 10, c);
		Bresenhamcircle((xc + x), (yc - y), radius / 10, c);
		Bresenhamcircle((xc - x), (yc - y), radius / 10, c);
		Bresenhamcircle((xc + y), (yc + x), radius / 10, c);
		Bresenhamcircle((xc - y), (yc + x), radius / 10, c);
		Bresenhamcircle((xc + y), (yc - x), radius / 10, c);
		Bresenhamcircle((xc - y), (yc - x), radius / 10, c);
	}
}
//填充颜色

//绘制波
void CMFCApplication5View::OnDrawwave()
{
	// TODO: 在此添加命令处理程序代码
	int xc;
	int yc;
	int radius;
	int c = 0;

	//right
	for (xc = 300, yc = 200, radius = 1; radius <= 100; xc += 10, radius += 3) {
		Bresenhamcircle(xc, yc, radius, c);
	}

}
//绘制波


void CMFCApplication5View::OnDrawcircir()
{
	// TODO: 在此添加命令处理程序代码
	int c = 0;
	Bresenhamcircle2(350, 250, 100, c);
}


//绘制环
void CMFCApplication5View::OnDrawcir()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	int x0 = 300;
	int y0 = 200;
	int xc;
	int yc;
	int radius = 100;
	int c = 0;
	float PI = 3.1415;
	int angle = 0;
	int dy = sin(45.0 / 180 * PI) * radius;
	int dx = cos(45.0 / 180 * PI) * radius;

	CString s;
	//s.Format(_T("%f"), angle);
	//dc.TextOutW(200, 200, s);


	for (xc = x0 + radius, yc = y0; angle <= 360; angle += 2) {

		Bresenhamcircle(xc, yc, radius/2 , RGB(147,181,207));

		xc = x0 + cos((float)angle / 180 * PI) * radius;
		yc = y0 + sin((float)angle / 180 * PI) * radius;
	}

}
//绘制环