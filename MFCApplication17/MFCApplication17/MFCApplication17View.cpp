
// MFCApplication17View.cpp: CMFCApplication17View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication17.h"
#endif

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define  TOP 8

#define XL 100
#define XR 300
#define YT 100
#define YB 250



#include "MFCApplication17Doc.h"
#include "MFCApplication17View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication17View

IMPLEMENT_DYNCREATE(CMFCApplication17View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication17View, CView)
END_MESSAGE_MAP()

// CMFCApplication17View 构造/析构

CMFCApplication17View::CMFCApplication17View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication17View::~CMFCApplication17View()
{
}

BOOL CMFCApplication17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication17View 绘图

void CMFCApplication17View::OnDraw(CDC* pDC)
{
	CMFCApplication17Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPen newpen(PS_DOT, 1, RGB(0, 255, 0)); //设置画笔，画绿色虚线
	CPen *old = pDC->SelectObject(&newpen);
	pDC->Rectangle(CRect(XL, YT, XR, YB));   //剪切窗口
	int N = 2;
	CPoint *ptset = new CPoint[N];  //若干线段端点定义数组
	ptset[0] = CPoint(200, 0); //若干线段端点赋值
	ptset[1] = CPoint(200, 300);
	
	

	
	for (int i = 0;i < N;i++)
	{
		pDC->MoveTo(ptset[i]);
		pDC->LineTo(ptset[i + 1]);  //裁剪前的若干线段绘制
		i++;
	}
	Clipline(ptset, N, pDC);  //调用裁剪程序并绘制裁剪后的线段 
}

void CMFCApplication17View::Clipline(CPoint *ptset, int N, CDC *pDC)
{
	CPen newpen(PS_SOLID, 2, RGB(255, 0, 0));
	CPen *old = pDC->SelectObject(&newpen);
	float x, y;
	int i;
	int code1, code2;
	// 求两端点所在区号code
	for (i = 0;i < N;i++, i++)
	{  //for
		int c = 0;
		if (ptset[i].x < XL) c = c | LEFT;
		else if (ptset[i].x > XR)c = c | RIGHT;
		if (ptset[i].y > YB) c = c | BOTTOM;
		else if (ptset[i].y < YT) c = c | TOP;
		code1 = c;
		c = 0;
		if (ptset[i + 1].x < XL) c = c | LEFT;
		else if (ptset[i + 1].x > XR) c = c | RIGHT;
		if (ptset[i + 1].y > YB) c = c | BOTTOM;
		else if (ptset[i + 1].y < YT) c = c | TOP;
		code2 = c;
		//线段与区域的相交情况
		if (code1 != 0 && code2 != 0 && (code1&code2) == 0)
		{ //1 半可见情况，求交
			if ((LEFT&code1) != 0)         //线段与左边界相交
			{
				x = XL;
				y = ptset[i].y + (ptset[i + 1].y - ptset[i].y)*(XL - ptset[i].x) / (ptset[i + 1].x - ptset[i].x);
			}
			else if ((RIGHT&code1) != 0)          //线段与右边界相交
			{
				x = XR;
				y = ptset[i].y + (ptset[i + 1].y - ptset[i].y)*(XR - ptset[i].x) / (ptset[i + 1].x - ptset[i].x);
			}
			else if ((BOTTOM&code1) != 0)          //线段与下边界相交
			{
				y = YB;
				x = ptset[i].x + (ptset[i + 1].x - ptset[i].x)*(YB - ptset[i].y) / (ptset[i + 1].y - ptset[i].y);
			}
			else if ((TOP&code1) != 0)          //线段与上边界相交
			{
				y = YT;
				x = ptset[i].x + (ptset[i + 1].x - ptset[i].x)*(YT - ptset[i].y) / (ptset[i + 1].y - ptset[i].y);
			}
			ptset[i].x = x;
			ptset[i].y = y;
			if ((LEFT&code2) != 0)         //线段与左边界相交
			{
				x = XL;
				y = ptset[i].y + (ptset[i + 1].y - ptset[i].y)*(XL - ptset[i].x) / (ptset[i + 1].x - ptset[i].x);
			}
			else if ((RIGHT&code2) != 0)          //线段与右边界相交
			{
				x = XR;
				y = ptset[i].y + (ptset[i + 1].y - ptset[i].y)*(XR - ptset[i].x) / (ptset[i + 1].x - ptset[i].x);
			}
			else if ((BOTTOM&code2) != 0)          //线段与下边界相交
			{
				y = YB;
				x = ptset[i].x + (ptset[i + 1].x - ptset[i].x)*(YB - ptset[i].y) / (ptset[i + 1].y - ptset[i].y);
			}
			else if ((TOP&code2) != 0)          //线段与上边界相交
			{
				y = YT;
				x = ptset[i].x + (ptset[i + 1].x - ptset[i].x)*(YT - ptset[i].y) / (ptset[i + 1].y - ptset[i].y);
			}
			ptset[i + 1].x = x;
			ptset[i + 1].y = y;
			pDC->MoveTo(ptset[i].x, ptset[i].y);
			pDC->LineTo(ptset[i + 1].x, ptset[i + 1].y);
		} //1
		if (code1 == 0 && code2 == 0)
		{ //2 全可见情况
			pDC->MoveTo(ptset[i].x, ptset[i].y);
			pDC->LineTo(ptset[i + 1].x, ptset[i + 1].y);
		}  //2
		if (code1 == 0 && code2 != 0)
		{  //3半可见情况，求交
			pDC->MoveTo(ptset[0].x, ptset[0].y);
			if ((LEFT&code2) != 0)         //线段与左边界相交
			{
				x = XL;
				y = (float)ptset[i].y + (ptset[i + 1].y - ptset[i].y)*(XL - ptset[i].x) / (ptset[i + 1].x - ptset[i].x);
			}
			else if ((RIGHT&code2) != 0)          //线段与右边界相交
			{
				x = XR;
				y = (float)ptset[i].y + (ptset[i + 1].y - ptset[i].y)*(XR - ptset[i].x) / (ptset[i + 1].x - ptset[i].x);
			}
			else if ((BOTTOM&code2) != 0)          //线段与下边界相交
			{
				y = YB;
				x = (float)ptset[i].x + (ptset[i + 1].x - ptset[i].x)*(YB - ptset[i].y) / (ptset[i + 1].y - ptset[i].y);
			}
			else if ((TOP&code2) != 0)          //线段与上边界相交
			{
				y = YT;
				x = (float)ptset[i].x + (ptset[i + 1].x - ptset[i].x)*(YT - ptset[i].y) / (ptset[i + 1].y - ptset[i].y);
			}
			ptset[i + 1].x = x;
			ptset[i + 1].y = y;
			pDC->LineTo(ptset[i + 1].x, ptset[i + 1].y);
		} //3

		if (code1 != 0 && code2 == 0)
		{  //4半可见情况，求交
			pDC->MoveTo(ptset[i + 1].x, ptset[i + 1].y);
			if ((LEFT&code1) != 0)         //线段与左边界相交
			{
				x = XL;
				y = (float)ptset[i].y + (ptset[i + 1].y - ptset[i].y)*(XL - ptset[i].x) / (ptset[i + 1].x - ptset[i].x);
			}
			else if ((RIGHT&code1) != 0)          //线段与右边界相交
			{
				x = XR;
				y = (float)ptset[i].y + (ptset[i + 1].y - ptset[i].y)*(XR - ptset[i].x) / (ptset[i + 1].x - ptset[i].x);
			}
			else if ((BOTTOM&code1) != 0)          //线段与下边界相交
			{
				y = YB;
				x = (float)ptset[i].x + (ptset[i + 1].x - ptset[i].x)*(YB - ptset[i].y) / (ptset[i + 1].y - ptset[i].y);
			}
			else if ((TOP&code1) != 0)          //线段与上边界相交
			{
				y = YT;
				x = (float)ptset[i].x + (ptset[i + 1].x - ptset[i].x)*(YT - ptset[i].y) / (ptset[i + 1].y - ptset[i].y);
			}
			ptset[i].x = (long)x;
			ptset[i].y = (long)y;
			pDC->LineTo(ptset[i].x, ptset[i].y);
		} //4
	} //for
}






// CMFCApplication17View 诊断

#ifdef _DEBUG
void CMFCApplication17View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication17View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication17Doc* CMFCApplication17View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication17Doc)));
	return (CMFCApplication17Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication17View 消息处理程序
