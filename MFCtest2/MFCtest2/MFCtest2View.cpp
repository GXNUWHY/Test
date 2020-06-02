
// MFCtest2View.cpp: CMFCtest2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtest2.h"
#endif

#include "MFCtest2Doc.h"
#include "MFCtest2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtest2View

IMPLEMENT_DYNCREATE(CMFCtest2View, CView)

BEGIN_MESSAGE_MAP(CMFCtest2View, CView)
	ON_WM_KEYDOWN()
//	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtest2View 构造/析构

CMFCtest2View::CMFCtest2View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCtest2View::~CMFCtest2View()
{
}

BOOL CMFCtest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtest2View 绘图

void CMFCtest2View::OnDraw(CDC* pDC)
{
	CMFCtest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->rect);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCtest2View 诊断

#ifdef _DEBUG
void CMFCtest2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtest2Doc* CMFCtest2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtest2Doc)));
	return (CMFCtest2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtest2View 消息处理程序


void CMFCtest2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCtest2Doc* pDoc = GetDocument();
	CRect clientrect;
	GetClientRect(&clientrect);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->rect.left>0)
		{
			pDoc->rect.left -= 5;
			pDoc->rect.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->rect.right <=(clientrect.right- clientrect.left))
		{
			pDoc->rect.left += 5;
			pDoc->rect.right += 5;
		}
		break;
	case VK_UP:
		if (pDoc->rect.top > 0)
		{
			pDoc->rect.bottom -= 5;
			pDoc->rect.top-= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->rect.bottom <= (clientrect.bottom - clientrect.top))
		{
			pDoc->rect.bottom += 5;
			pDoc->rect.top += 5;
		}
		break;
	case VK_HOME:
		if (pDoc->rect.left>=0&& pDoc->rect.top>=0)
		{
			pDoc->rect.left -= 5;
			pDoc->rect.top -= 5;
		}
		break;
	case VK_END:
		if (pDoc->rect.left >= 0 && pDoc->rect.top >= 0)
		{
			pDoc->rect.right -= 5;
			pDoc->rect.bottom -= 5;
		}
		break;

		}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}





void CMFCtest2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCtest2Doc* pDoc = GetDocument();
	pDoc->rect.left = 80;    pDoc->rect.top = 80;
	pDoc->rect.right = 150;  pDoc->rect.bottom = 130;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
