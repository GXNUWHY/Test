
// MFCApplication20View.cpp: CMFCApplication20View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication20.h"
#endif

#include "MFCApplication20Doc.h"
#include "MFCApplication20View.h"
#include "calculate.h"
#include "color.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication20View

IMPLEMENT_DYNCREATE(CMFCApplication20View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication20View, CView)
	ON_COMMAND(ID_32771, &CMFCApplication20View::On32771)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32772, &CMFCApplication20View::On32772)
END_MESSAGE_MAP()

// CMFCApplication20View 构造/析构

CMFCApplication20View::CMFCApplication20View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication20View::~CMFCApplication20View()
{
}

BOOL CMFCApplication20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication20View 绘图

CRect ellipse;
int mode = 0;
void CMFCApplication20View::OnDraw(CDC* pDC)
{
	CMFCApplication20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->SelectStockObject(NULL_BRUSH);
	if (mode == 1) {
		pDC->Ellipse(ellipse);
	}

}


// CMFCApplication20View 诊断

#ifdef _DEBUG
void CMFCApplication20View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication20View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication20Doc* CMFCApplication20View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication20Doc)));
	return (CMFCApplication20Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication20View 消息处理程序


void CMFCApplication20View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	calculate cal;
	if (cal.DoModal() == IDOK) {
	}
}


void CMFCApplication20View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (mode == 0) {
		ellipse.left = point.x;
		ellipse.top = point.y;
		mode = 1;
	}
	else if (mode == 2) {
		if (point.x > ellipse.left && point.x < ellipse.right) {
			if (point.y > ellipse.top && point.y < ellipse.bottom) {
				dc.SelectStockObject(NULL_BRUSH);
				dc.Rectangle(ellipse);
			}
		}
	}
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication20View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (mode == 1) {
		ellipse.right = point.x;
		ellipse.bottom = point.y;
		this->Invalidate();
	}
	

	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication20View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	mode = 2;

	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication20View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	color col;
	if (col.DoModal() == IDOK) {
		int R, G, B;
		CDC *pDC = GetDC();
		CClientDC dc(this);
		R = col.R;
		G = col.G;
		B = col.B;
		CBrush fillellipse(RGB(R, G, B));
		pDC->SelectObject(fillellipse);
		pDC->Ellipse(ellipse);

	}
}
