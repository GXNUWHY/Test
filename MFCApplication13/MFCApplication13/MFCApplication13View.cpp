
// MFCApplication13View.cpp: CMFCApplication13View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication13.h"
#endif

#include "MFCApplication13Doc.h"
#include "MFCApplication13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication13View

IMPLEMENT_DYNCREATE(CMFCApplication13View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication13View, CView)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication13View 构造/析构

CMFCApplication13View::CMFCApplication13View() noexcept
{
	// TODO: 在此处添加构造代码
	set = false;
}

CMFCApplication13View::~CMFCApplication13View()
{
}

BOOL CMFCApplication13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication13View 绘图
CRect rt(0, 0, 100, 100);
int mode = 0;
void CMFCApplication13View::OnDraw(CDC* pDC)
{
	CMFCApplication13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set) {
		SetTimer(1, rand() % 400 + 100, NULL);
		set = false;
	}
	// TODO: 在此处为本机数据添加绘制代码
	
	CRect client;
	this->GetClientRect(client);
	
	if (rt.right >= client.right) {
		mode = 1;
	}
	if (rt.left <= client.left) {
		mode = 0;
	}

	pDC->Ellipse(rt);

}


// CMFCApplication13View 诊断

#ifdef _DEBUG
void CMFCApplication13View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication13Doc* CMFCApplication13View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication13Doc)));
	return (CMFCApplication13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication13View 消息处理程序


void CMFCApplication13View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//set = true;
	//this->Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication13View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	KillTimer(1);
	this->Invalidate();
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCApplication13View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (mode == 0) {
		rt.left += 10;
		rt.right += 10;
	}
	else if (mode == 1) {
		rt.left -= 10;
		rt.right -= 10;
	}

	this->Invalidate();

	CView::OnTimer(nIDEvent);
}


void CMFCApplication13View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
