
// MFC(4)View.cpp: CMFC4View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC(4).h"
#endif

#include "MFC(4)Doc.h"
#include "MFC(4)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4View

IMPLEMENT_DYNCREATE(CMFC4View, CView)

BEGIN_MESSAGE_MAP(CMFC4View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC4View 构造/析构

CMFC4View::CMFC4View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4View::~CMFC4View()
{
}

BOOL CMFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4View 绘图

void CMFC4View::OnDraw(CDC* /*pDC*/)
{
	CMFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4View 诊断

#ifdef _DEBUG
void CMFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4Doc* CMFC4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4Doc)));
	return (CMFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4View 消息处理程序


void CMFC4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s;
	s.Format(_T("A+B=%d"), pDoc->A + pDoc->B);
	dc.TextOutW(20, 20, s);
	CView::OnLButtonDown(nFlags, point);
}
