
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
	ON_COMMAND(ID_32771, &CMFCApplication1View::OnDrawCircle)
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

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


void CMFCApplication1View::OnDrawCircle()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CPen* OldPen;
	CPen ColorPen[100];
	this->GetClientRect(ClientRect);
	int x = (ClientRect.left + ClientRect.right) / 2;//圆心坐标
	int y = (ClientRect.top + ClientRect.bottom) / 2;//圆心坐标
	int r = 10;//半径


	for (int i = 0; i < 20; ++i, r += 10) {
		CRect RectCircle(x - r, y - r, x + r, y + r);
		//RectArray.Add(RectCircle);

		int color = RGB(i * 10, 0, i * 10);
		ColorPen[i].CreatePen(PS_SOLID, 2, color);

		OldPen = dc.SelectObject(&ColorPen[i]);
		//dc.SelectStockObject(NULL_BRUSH);
		dc.Ellipse(RectCircle);
		
		ColorPen[i].DeleteObject();
		Sleep(500);
	}
}
