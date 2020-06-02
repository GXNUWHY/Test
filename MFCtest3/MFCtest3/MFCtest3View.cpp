
// MFCtest3View.cpp: CMFCtest3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtest3.h"
#endif

#include "MFCtest3Doc.h"
#include "MFCtest3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtest3View

IMPLEMENT_DYNCREATE(CMFCtest3View, CView)

BEGIN_MESSAGE_MAP(CMFCtest3View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCtest3View 构造/析构

CMFCtest3View::CMFCtest3View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCtest3View::~CMFCtest3View()
{
}

BOOL CMFCtest3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtest3View 绘图

void CMFCtest3View::OnDraw(CDC* pDC)
{
	CMFCtest3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (pDoc->set) {
		SetTimer(1, rand() % 400 + 100, NULL);
		pDoc->set = false;
	}
	pDC->Ellipse(pDoc->circle);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCtest3View 诊断

#ifdef _DEBUG
void CMFCtest3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtest3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtest3Doc* CMFCtest3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtest3Doc)));
	return (CMFCtest3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtest3View 消息处理程序


void CMFCtest3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCtest3Doc* pDoc = GetDocument();
	CRect clientrect;
	GetClientRect(&clientrect);
	if (pDoc->circle.top>=0&& pDoc->circle.bottom<= (clientrect.bottom- clientrect.top)&& pDoc->key ==0) {
		pDoc->circle.top += 10;
		pDoc->circle.bottom += 10;
	}
	else  {
		pDoc->key =1;
	}
	if(pDoc->key ==1&& pDoc->circle.top >= 0){
		pDoc->circle.top -= 10;
		pDoc->circle.bottom -= 10;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
