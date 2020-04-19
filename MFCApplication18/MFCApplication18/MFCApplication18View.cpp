
// MFCApplication18View.cpp: CMFCApplication18View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication18.h"
#endif


#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define  TOP 8

#define XL 100
#define XR 300
#define YT 100
#define YB 250

#define N  10


#include "MFCApplication18Doc.h"
#include "MFCApplication18View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication18View

IMPLEMENT_DYNCREATE(CMFCApplication18View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication18View, CView)
END_MESSAGE_MAP()

// CMFCApplication18View 构造/析构

CMFCApplication18View::CMFCApplication18View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication18View::~CMFCApplication18View()
{
}

BOOL CMFCApplication18View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication18View 绘图

void CMFCApplication18View::OnDraw(CDC* pDC)
{
	CMFCApplication18Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPen newpen(PS_DOT, 1, RGB(0, 255, 0));
	CPen *old = pDC->SelectObject(&newpen);
	pDC->Rectangle(CRect(XL, YT, XR, YB));//剪切窗口
	CPoint ptset1[N]; //多边形端点定义及赋值
	int M0 = 4;
	ptset1[0] = CPoint(50, 150);
	ptset1[1] = CPoint(160, 120);
	ptset1[2] = CPoint(250, 150);
	ptset1[3] = CPoint(180, 230);
	ptset1[4] = CPoint(50, 150);

		/*ptset1[0]=CPoint(50,200);	ptset1[1]=CPoint(170,80);	ptset1[2]=CPoint(350,150);	ptset1[3]=CPoint(220,300);	ptset1[4]=CPoint(50,200);*/	

	pDC->MoveTo(ptset1[0]);
	for (int i = 1;i <= M0;i++)
	{
		pDC->LineTo(ptset1[i]); //起初被裁剪多边形的绘制
	}
	PolygonClip(ptset1, M0, pDC);

}

void CMFCApplication18View::PolygonClip(CPoint *ptset1, int M0, CDC *pDC)
{
	// TODO: Add your command handler code here
	CPoint pt[N], pts[N], ptse[N], p[N];
	CPen newpen(PS_SOLID, 2, RGB(255, 0, 0));
	//实心画笔，2像素粗的红色实线
	CPen *old = pDC->SelectObject(&newpen);
	int i, k, M, w;
	int code1, code2;
	M = M0; //初始化及其数据输入
// 求两端点所在区号code
	k = 0;
	for (i = 0;i < M;i++)//xxll
	{  //A左边XL裁剪
		int c = 0;
		if (ptset1[i].x < XL) c = 1;
		else if (ptset1[i].x > XL)c = 0;
		code1 = c;
		c = 0;
		if (ptset1[i + 1].x < XL) c = 1;
		else if (ptset1[i + 1].x > XL) c = 0;
		code2 = c;
		if (code1 != 0 && code2 == 0)
		{  //11
			pt[k].x = XL;
			pt[k].y = ptset1[i].y + (ptset1[i + 1].y - ptset1[i].y)*(XL - ptset1[i].x) / (ptset1[i + 1].x - ptset1[i].x);
			pt[k + 1].x = ptset1[i + 1].x;
			pt[k + 1].y = ptset1[i + 1].y;
			k = k + 2;
		} //11

		if (code1 == 0 && code2 == 0)
		{  //22
			if (k == 0)
			{ //aaa
				pt[k].x = ptset1[i].x;
				pt[k].y = ptset1[i].y;
				pt[k + 1].x = ptset1[i + 1].x;
				pt[k + 1].y = ptset1[i + 1].y;
				k = k + 2;
			} //aaa
			else
			{ //bbb
				pt[k].x = ptset1[i + 1].x;
				pt[k].y = ptset1[i + 1].y;
				k = k + 1;
			} //bbb
		} //22
		if (code1 == 0 && code2 != 0)
		{ //33
			pt[k].x = XL;
			pt[k].y = ptset1[i].y + (ptset1[i + 1].y - ptset1[i].y)*(XL - ptset1[i].x) / (ptset1[i + 1].x - ptset1[i].x);
			k++;
		} //33
	}  //A左边XL裁剪

	if (pt[0] != ptset1[0])
		M = k;
	else
		M = k - 1;
	pt[k] = pt[0];
	k = 0;
	for (i = 0;i < M;i++)//xxrr
	{ //B右边XR裁剪
		int c = 0;
		if (pt[i].x < XR) c = 0;
		else if (pt[i].x > XR) c = 2;
		code1 = c;
		c = 0;
		if (pt[i + 1].x < XR) c = 0;
		else if (pt[i + 1].x > XR) c = 2;
		code2 = c;

		if (code1 == 0 && code2 == 0)
		{
			if (k == 0)
			{
				pts[k].x = pt[i].x;
				pts[k].y = pt[i].y;
				pts[k + 1].x = pt[i + 1].x;
				pts[k + 1].y = pt[i + 1].y;
				k = k + 2;
			}
			else
			{
				pts[k].x = pt[i + 1].x;
				pts[k].y = pt[i + 1].y;
				k++;
			}
		}
		if (code1 != 0 && code2 == 0)
		{
			pts[k].x = XR;
			pts[k].y = pt[i].y + (pt[i + 1].y - pt[i].y)*(XR - pt[i].x) / (pt[i + 1].x - pt[i].x);
			pts[k + 1].x = pt[i + 1].x;
			pts[k + 1].y = pt[i + 1].y;
			k = k + 2;
		}
		if (code1 == 0 && code2 != 0)
		{
			pts[k].x = XR;w = k;
			pts[k].y = pt[i].y + (pt[i + 1].y - pt[i].y)*(XR - pt[i].x) / (pt[i + 1].x - pt[i].x);
			k = k + 1;
		}
	}  //B右边XR裁剪



//增加对最后一条边的判断
	if (pts[0] != pt[0])
		M = k;
	else
		M = k - 1;
	pts[M] = pts[0];
	k = 0;
	for (i = 0;i < M;i++)//yybb
	{   //C底边YB裁剪
		int c = 0;
		if (pts[i].y > YB) c = 4;
		else if (pts[i].y < YB) c = 0;
		code1 = c;
		c = 0;
		if (pts[i + 1].y > YB) c = 4;
		else if (pts[i + 1].y < YB) c = 0;
		code2 = c;

		if (code1 == 0 && code2 == 0)
		{
			if (k == 0)
			{
				ptse[k].x = pts[i].x;
				ptse[k].y = pts[i].y;
				ptse[k + 1].x = pts[i + 1].x;
				ptse[k + 1].y = pts[i + 1].y;
				k = k + 2;
			}
			else
			{
				ptse[k].x = pts[i + 1].x;
				ptse[k].y = pts[i + 1].y;
				k = k + 1;
			}
		}
		if (code1 != 0 && code2 == 0)
		{
			ptse[k].y = YB;
			ptse[k].x = pts[i].x + (pts[i + 1].x - pts[i].x)*(YB - pts[i].y) / (pts[i + 1].y - pts[i].y);
			ptse[k + 1].x = pts[i + 1].x;
			ptse[k + 1].y = pts[i + 1].y;
			k = k + 2;
		}
		if (code1 == 0 && code2 != 0)
		{
			ptse[k].y = YB;
			ptse[k].x = pts[i].x + (pts[i + 1].x - pts[i].x)*(YB - pts[i].y) / (pts[i + 1].y - pts[i].y);
			k = k + 1;
		}
	}  //C底边YB裁剪
	if (ptse[0] != pts[0])
		M = k;
	else
		M = k - 1;
	ptse[M] = ptse[0];
	k = 0;
	for (i = 0;i < M;i++)//yytt
	{   //D顶边YT裁剪
		int c = 0;
		if (ptse[i].y > YT) c = 0;
		else if (ptse[i].y < YT) c = 1;
		code1 = c;
		c = 0;
		if (ptse[i + 1].y > YT) c = 0;
		else if (ptse[i + 1].y < YT) c = 1;
		code2 = c;
		if (code1 != 0 && code2 == 0)
		{
			p[k].y = YT;
			p[k].x = ptse[i].x + (ptse[i + 1].x - ptse[i].x)*(YT - ptse[i].y) / (ptse[i + 1].y - ptse[i].y);
			p[k + 1].x = ptse[i + 1].x;
			p[k + 1].y = ptse[i + 1].y;
			k = k + 2;
		}

		if (code1 == 0 && code2 == 0)
		{
			if (k == 0)
			{
				p[k].x = ptse[i].x;
				p[k].y = ptse[i].y;
				p[k + 1].x = ptse[i + 1].x;
				p[k + 1].y = ptse[i + 1].y;
				k = k + 2;
			}
			else
			{
				p[k].x = ptse[i + 1].x;
				p[k].y = ptse[i + 1].y;
				k = k + 1;
			}
		}
		if (code1 == 0 && code2 != 0)
		{
			p[k].y = YT;
			p[k].x = ptse[i].x + (ptse[i + 1].x - ptse[i].x)*(YT - ptse[i].y) / (ptse[i + 1].y - ptse[i].y);
			k++;
		}
	}  //D顶边YT裁剪
	if (p[0] != ptse[0])
		M = k;
	else
		M = k - 1;
	p[M] = p[0];
	//M=k;
	pDC->MoveTo(p[0]);
	for (int j = 1;j <= M;j++) //O最后裁剪结果输出
	{
		pDC->LineTo(p[j]);
	}
}



// CMFCApplication18View 诊断

#ifdef _DEBUG
void CMFCApplication18View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication18View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication18Doc* CMFCApplication18View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication18Doc)));
	return (CMFCApplication18Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication18View 消息处理程序
