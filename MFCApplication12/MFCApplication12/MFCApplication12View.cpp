
// MFCApplication12View.cpp: CMFCApplication12View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication12.h"
#endif

#include "MFCApplication12Doc.h"
#include "MFCApplication12View.h"
#include "ADDFrame.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication12View

IMPLEMENT_DYNCREATE(CMFCApplication12View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication12View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_ADD, &CMFCApplication12View::OnAdd)
END_MESSAGE_MAP()

// CMFCApplication12View 构造/析构

CMFCApplication12View::CMFCApplication12View() noexcept
{
	// TODO: 在此处添加构造代码
	
}

CMFCApplication12View::~CMFCApplication12View()
{
}

BOOL CMFCApplication12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication12View 绘图
CRect rt(200, 200, 300, 300);
void CMFCApplication12View::OnDraw(CDC* pDC)
{
	CMFCApplication12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	pDC->Rectangle(rt);
}


// CMFCApplication12View 诊断

#ifdef _DEBUG
void CMFCApplication12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication12Doc* CMFCApplication12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication12Doc)));
	return (CMFCApplication12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication12View 消息处理程序

int startx1, startx2;
int starty1, starty2;
void CMFCApplication12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x > rt.left && point.x < rt.right) {
		if ((point.y > rt.top && point.y < rt.bottom)) {
			mode = 1;
			startx1 = point.x - rt.left;
			startx2 = rt.right - point.x;

			starty1 = point.y - rt.top;
			starty2 = rt.bottom - point.y;
		}
	}

	CView::OnLButtonDown(nFlags, point);
}

void CMFCApplication12View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (mode == 1) {
		rt.left = point.x - startx1;
		rt.right = point.x + startx2;
		rt.top = point.y - starty1;
		rt.bottom = point.y + starty2;
		//this->InvalidateRect(rt);
		this->Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication12View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	mode = 0;
	CView::OnLButtonUp(nFlags, point);
}



void CMFCApplication12View::OnAdd()
{
	// TODO: 在此添加命令处理程序代码
	ADDFrame dlg;
	if (dlg.DoModal() == IDOK) {

	}

}
