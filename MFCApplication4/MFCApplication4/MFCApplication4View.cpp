
// MFCApplication4View.cpp: CMFCApplication4View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "MFCApplication4Doc.h"
#include "MFCApplication4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication4View

IMPLEMENT_DYNCREATE(CMFCApplication4View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication4View, CView)
	ON_COMMAND(ID_DDALINE, &CMFCApplication4View::OnDdaline)
	ON_COMMAND(ID_MIDPOINTLINE, &CMFCApplication4View::OnMidpointline)
	ON_COMMAND(ID_BRESENHAMLINE, &CMFCApplication4View::OnBresenhamline)
END_MESSAGE_MAP()

// CMFCApplication4View 构造/析构

CMFCApplication4View::CMFCApplication4View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication4View::~CMFCApplication4View()
{
}

BOOL CMFCApplication4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View 绘图

void CMFCApplication4View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication4View 诊断

#ifdef _DEBUG
void CMFCApplication4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication4Doc* CMFCApplication4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication4Doc)));
	return (CMFCApplication4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication4View 消息处理程序

//DDA算法生成直线

void CMFCApplication4View::OnDdaline()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int xa = 100, ya = 300, xb = 300, yb = 200;
	int c = RGB(255, 0, 0);
	int x, y;
	float dx, dy, k;
	dx = (float)(xb - xa), dy = (float)(yb - ya);
	k = dy / dx;
	y = ya;
	if (abs(k) < 1) {
		for (x = xa; x <= xb; ++x) {
			pDC->SetPixel(x, int(y + 0.5), c);
			y += k;
		}
	}

	if (abs(k) >= 1) {
		for (y = ya; y <= yb; ++y) {
			pDC->SetPixel(int(x + 0.5), y, c);
			x += 1 / k;
		}
	}
	ReleaseDC(pDC);
}

//中点算法生成直线

void CMFCApplication4View::OnMidpointline()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int xa = 300, ya = 200, xb = 450, yb = 300;
	int c = RGB(0, 255, 0);
	float a, b, d1, d2, d, x, y;
	a = ya - yb, b = xb - xa, d = 2 * a + b;
	d1 = 2 * a, d2 = 2 * (a + b);
	x = xa, y = ya;
	pDC->SetPixel(x, y, c);
	while (x < xb) {
		if (d < 0) {
			++x, ++y;
			d += d2;
		}
		else {
			++x;
			d += d1;
		}
		pDC->SetPixel(x, y, c);
	}
	ReleaseDC(pDC);
}

//Bresenham算法生成直线

void CMFCApplication4View::OnBresenhamline()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int x1 = 100, y1 = 200, x2 = 350, y2 = 100;
	int c = RGB(0, 0, 255);
	int i, s1, s2, interchange;
	float x, y, deltax, deltay, e, temp;
	int f;
	x = x1;
	y = y1;
	deltax = abs(x2 - x1);
	deltay = abs(y2 - y1);
	if (x2 - x1 >= 0) s1 = 1;
	else s1 = -1;

	if (y2 - y1 >= 0) s2 = 1;
	else s2 = -1;

	if (deltay > deltax) {
		temp = deltax;
		deltax = deltay;
		deltay = temp;
		interchange = 1;
	}
	else {
		interchange = 0;
	}
	f = 2 * deltay - deltax;
	pDC->SetPixel(x, y, c);

	for (i = 1; i <= deltax; ++i) {
		if (f >= 0) {
			if (interchange == 1) x += s1;
			else y += s2;
			pDC->SetPixel(x, y, c);
			f -= 2 * deltax;
		}
		else {
			if (interchange == 1) y += s2;
			else x += s1;
			pDC->SetPixel(x, y, c);
			f += 2 * deltay;
		}
	}
}
