
// MFC(3)View.cpp: CMFC3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC(3).h"
#endif

#include "MFC(3)Doc.h"
#include "MFC(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3View

IMPLEMENT_DYNCREATE(CMFC3View, CView)

BEGIN_MESSAGE_MAP(CMFC3View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC3View 构造/析构

CMFC3View::CMFC3View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3View::~CMFC3View()
{
}

BOOL CMFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3View 绘图

void CMFC3View::OnDraw(CDC* /*pDC*/)
{
	CMFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3View 诊断

#ifdef _DEBUG
void CMFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3Doc* CMFC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3Doc)));
	return (CMFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3View 消息处理程序


void CMFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s.Format(_T("左键正被按下"));
	dc.TextOutW(20, 20, s);
	CView::OnLButtonDown(nFlags, point);
}


void CMFC3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s.Format(_T("左键正在抬起"));
	dc.TextOutW(20, 20, s);
	CView::OnLButtonUp(nFlags, point);
}
