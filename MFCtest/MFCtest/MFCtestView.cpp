
// MFCtestView.cpp: CMFCtestView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtest.h"
#endif

#include "MFCtestDoc.h"
#include "MFCtestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtestView

IMPLEMENT_DYNCREATE(CMFCtestView, CView)

BEGIN_MESSAGE_MAP(CMFCtestView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCtestView 构造/析构

CMFCtestView::CMFCtestView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCtestView::~CMFCtestView()
{
}

BOOL CMFCtestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtestView 绘图

void CMFCtestView::OnDraw(CDC* pDC)
{
	CMFCtestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->rect);
	// TODO: 在此处为本机数据添加绘制代码 
}


// CMFCtestView 诊断

#ifdef _DEBUG
void CMFCtestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtestDoc* CMFCtestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtestDoc)));
	return (CMFCtestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtestView 消息处理程序


void CMFCtestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCtestDoc* pDoc = GetDocument();
	pDoc->rect.left = point.x;
	pDoc->rect.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCtestDoc* pDoc = GetDocument();
	pDoc->rect.right = point.x;
	pDoc->rect.bottom= point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CMFCtestView::OnMouseMove(UINT nFlags, CPoint point)
{
   #undef UNICODE
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCtestDoc* pDoc = GetDocument();
	pDoc->point = point;
	CClientDC dc(this);
	CString str;
	str.Format(_T("x=%d,y=%d"), pDoc->point.x, pDoc->point.y);
	dc.TextOutW(20, 20, str);
	CView::OnMouseMove(nFlags, point);
}
