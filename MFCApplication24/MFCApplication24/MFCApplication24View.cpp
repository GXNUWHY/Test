
// MFCApplication24View.cpp: CMFCApplication24View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication24.h"
#endif

#include "MFCApplication24Doc.h"
#include "MFCApplication24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication24View

IMPLEMENT_DYNCREATE(CMFCApplication24View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication24View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication24View 构造/析构

CMFCApplication24View::CMFCApplication24View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication24View::~CMFCApplication24View()
{
}

BOOL CMFCApplication24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication24View 绘图

void CMFCApplication24View::OnDraw(CDC* pDC)
{
	CMFCApplication24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->SelectStockObject(NULL_BRUSH);
	pDC->Ellipse(cr);
	int n = pDoc->rectarray.GetCount();
	CString s;
	s.Format(_T("%d"), n);

	pDC->TextOutW(100, 100, s);

	for (int i = 0; i < n; ++i) {
		pDC->Ellipse(pDoc->rectarray[i]);
	}
}


// CMFCApplication24View 诊断

#ifdef _DEBUG
void CMFCApplication24View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication24Doc* CMFCApplication24View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication24Doc)));
	return (CMFCApplication24Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication24View 消息处理程序


void CMFCApplication24View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (mode == 0) {
		cr.left = point.x;
		cr.top = point.y;
		mode = 1;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication24View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (mode == 1) {
		cr.right = point.x;
		cr.bottom = point.y;
		this->Invalidate();
		//this->InvalidateRect(cr, true);
	}

	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication24View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication24Doc* pDoc = GetDocument();
	mode = 0;

	pDoc->rectarray.Add(cr);

	CView::OnLButtonUp(nFlags, point);
}
