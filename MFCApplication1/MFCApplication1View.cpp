
// MFCApplication1View.cpp: CMFCApplication1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 绘图

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int b = pDoc->A;
	CString S = pDoc->S;
	num = pDoc->count;

	CString s;
	s.Format(_T("%s%d"), S, b);
	pDC->TextOutW(100, 200, s);
	// TODO: 在此处为本机数据添加绘制代码
	/*int red = 0, green = 0, blue = 0;
	int width = 2;
	int row = 20;
	for (int s = 0; s < 8; ++s) {

		int color = RGB(red, green, blue);
		CPen newPen(PS_SOLID, width, color);
		CPen *oldPen = pDC->SelectObject(&newPen);

		pDC->MoveTo(20, row);
		pDC->LineTo(200, row);
		pDC->SelectObject(oldPen);

		red += 30;
		green += 30;
		blue += 30;
		width += 2;
		row += 30;
	}*/

}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 消息处理程序


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*CClientDC dc(this);
	CRect rc;
	GetClientRect(&rc);
	
	dc.MoveTo(0, (rc.bottom + rc.top) / 2);
	dc.LineTo((rc.left + rc.right) / 2, 0);
	dc.LineTo(rc.right, (rc.bottom + rc.top) / 2);
	dc.LineTo((rc.left + rc.right) / 2, rc.bottom);
	dc.LineTo(0, (rc.bottom + rc.top) / 2);*/
	CClientDC dc(this);
	num ++;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s.Format(_T("%d"), num);
	dc.TextOutW(100, 500, s);

	CView::OnRButtonDown(nFlags, point);
}
