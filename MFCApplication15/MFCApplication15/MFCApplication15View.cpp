
// MFCApplication15View.cpp: CMFCApplication15View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication15.h"
#endif

#include "MFCApplication15Doc.h"
#include "MFCApplication15View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication15View

IMPLEMENT_DYNCREATE(CMFCApplication15View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication15View, CView)
END_MESSAGE_MAP()

// CMFCApplication15View 构造/析构

CMFCApplication15View::CMFCApplication15View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication15View::~CMFCApplication15View()
{
}

BOOL CMFCApplication15View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication15View 绘图

void CMFCApplication15View::OnDraw(CDC* pDC)
{
	CMFCApplication15Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int x0 = 200, y0 = 150, r = 50, cr1, cr2;
	cr1 = RGB(255, 0, 0);
	cr2 = RGB(0, 255, 0);

	//Bresenhamcircle(x0, y0, r, cr1);
	//boundaryfill4(x0, y0, cr2, cr1, pDC);

	Poly();
	boundaryfill4(125, 125, cr2, cr1, pDC);
}

void CMFCApplication15View::Poly() {
	CPoint spt[5];
	CDC *pDC = GetDC();
	CPen newpen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *old = pDC->SelectObject(&newpen);

	spt[0] = CPoint(100, 100);
	spt[1] = CPoint(150, 100);
	spt[2] = CPoint(150, 150);
	spt[3] = CPoint(100, 150);
	spt[4] = CPoint(100, 100);
	pDC->Polyline(spt, 5);

	
}


void CMFCApplication15View::boundaryfill4(int seedx, int seedy, int fcolor, int bcolor, CDC *pDC)
{
	int current = pDC->GetPixel(seedx, seedy);
	if ((current != bcolor) && (current != fcolor))
	{
		pDC->SetPixel(seedx, seedy, fcolor);
		
		boundaryfill4(seedx, seedy + 1, fcolor, bcolor, pDC);
		boundaryfill4(seedx, seedy - 1, fcolor, bcolor, pDC);
		boundaryfill4(seedx + 1, seedy, fcolor, bcolor, pDC);
		boundaryfill4(seedx - 1, seedy, fcolor, bcolor, pDC);
	}
}

void CMFCApplication15View::Bresenhamcircle(int xc, int yc, int radius, int c)
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


// CMFCApplication15View 诊断

#ifdef _DEBUG
void CMFCApplication15View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication15View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication15Doc* CMFCApplication15View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication15Doc)));
	return (CMFCApplication15Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication15View 消息处理程序
