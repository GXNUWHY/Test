
// MFCApplication14View.cpp: CMFCApplication14View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication14.h"
#endif

#include "MFCApplication14Doc.h"
#include "MFCApplication14View.h"
#include "ADDFrame.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication14View

IMPLEMENT_DYNCREATE(CMFCApplication14View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication14View, CView)
	ON_COMMAND(ID_32771, &CMFCApplication14View::On32771)
END_MESSAGE_MAP()

// CMFCApplication14View 构造/析构

CMFCApplication14View::CMFCApplication14View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication14View::~CMFCApplication14View()
{
}

BOOL CMFCApplication14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication14View 绘图

void CMFCApplication14View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication14View 诊断

#ifdef _DEBUG
void CMFCApplication14View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication14Doc* CMFCApplication14View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication14Doc)));
	return (CMFCApplication14Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication14View 消息处理程序


void CMFCApplication14View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	ADDFrame add;
	if (add.DoModal() == IDOK) {

	}
}
