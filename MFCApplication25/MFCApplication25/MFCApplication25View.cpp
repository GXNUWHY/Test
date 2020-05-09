
// MFCApplication25View.cpp: CMFCApplication25View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication25.h"
#endif

#include "MFCApplication25Doc.h"
#include "MFCApplication25View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication25View

IMPLEMENT_DYNCREATE(CMFCApplication25View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication25View, CView)
END_MESSAGE_MAP()

// CMFCApplication25View 构造/析构

CMFCApplication25View::CMFCApplication25View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication25View::~CMFCApplication25View()
{
}

BOOL CMFCApplication25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication25View 绘图

void CMFCApplication25View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication25View 诊断

#ifdef _DEBUG
void CMFCApplication25View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication25Doc* CMFCApplication25View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication25Doc)));
	return (CMFCApplication25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication25View 消息处理程序
