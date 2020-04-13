
// MFCApplication11View.cpp: CMFCApplication11View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication11.h"
#endif

#include "MFCApplication11Doc.h"
#include "MFCApplication11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication11View

IMPLEMENT_DYNCREATE(CMFCApplication11View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication11View, CView)
	ON_COMMAND(ID_32771, &CMFCApplication11View::On32771)
	ON_COMMAND(ID_32772, &CMFCApplication11View::On32772)
END_MESSAGE_MAP()

// CMFCApplication11View 构造/析构

CMFCApplication11View::CMFCApplication11View() noexcept
{
	// TODO: 在此处添加构造代码
}

CMFCApplication11View::~CMFCApplication11View()
{
}

BOOL CMFCApplication11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication11View 绘图

void CMFCApplication11View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication11View 诊断

#ifdef _DEBUG
void CMFCApplication11View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication11Doc* CMFCApplication11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication11Doc)));
	return (CMFCApplication11Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication11View 消息处理程序

Edge edge[7], newedge[1];
void CMFCApplication11View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	CDC *pDC = GetDC();
	CPen newpen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *old = pDC->SelectObject(&newpen);
	CPoint spt[8], s_point;
	spt[0] = CPoint(100, 100);
	spt[1] = CPoint(300, 100);
	spt[2] = CPoint(250, 250);
	spt[3] = CPoint(100, 250);
	spt[4] = CPoint(150, 200);
	spt[5] = CPoint(90, 180);
	spt[6] = CPoint(150, 150);
	spt[7] = CPoint(100, 100);
	pDC->Polyline(spt, 8);
	ScanFill(spt, pDC);
	//  s_point=CPoint(200,200);
	// SeedFill(spt,s_point,pDC);

}
void CMFCApplication11View::ScanFill(CPoint spt[], CDC *pDC)
{
	int j, k, s = 0;
	int p[10];  //交点x坐标值
	int pmin, pmax = 0;
	pmin = spt[0].y;
	CPen newpen(PS_SOLID, 1, RGB(0, 255, 0));
	pDC->SelectObject(&newpen);
	for (int i = 0;i <= 6;i++)  //建立新边表NET
	{  //1
		edge[i].dx = (float)(spt[i + 1].x - spt[i].x) / (spt[i + 1].y - spt[i].y);
		if (spt[i].y <= spt[i + 1].y)
		{
			edge[i].num = i;
			edge[i].ymin = spt[i].y;
			edge[i].ymax = spt[i + 1].y;
			edge[i].xmin = (float)spt[i].x;
			edge[i].xmax = (float)spt[i + 1].x;
			if (pmax < spt[i + 1].y)
				pmax = spt[i + 1].y;
			if (pmin > spt[i].y)
				pmin = spt[i].y;
		}
		else
		{
			edge[i].num = i;
			edge[i].ymin = spt[i + 1].y;
			edge[i].ymax = spt[i].y;
			edge[i].xmin = (float)spt[i + 1].x;
			edge[i].xmax = (float)spt[i].x;
			if (pmax < spt[i].y)
				pmax = spt[i].y;
			if (pmin > spt[i + 1].y)
				pmin = spt[i + 1].y;
		}
	} //1
	for (int r = 1;r < 6;r++) //排序（按ymin由大到小）
	{ //2
		for (int q = 0;q < 6 - r;q++)
		{
			if (edge[q].ymin < edge[q + 1].ymin)
			{
				newedge[0] = edge[q];
				edge[q] = edge[q + 1];
				edge[q + 1] = newedge[0];
			}
		}
	} //2

	for (int scan = pmax - 1;scan > pmin;scan--) //多边形自上而下扫描求交、填充
	{  //3
		int b = 0;
		k = s;
		for (j = k;j <= 6;j++)    //对于某条扫描线，求与多边形的交点
		{   //AA
			if ((scan > edge[j].ymin) && (scan <= edge[j].ymax))
			{  //111 
				if (scan == edge[j].ymax)  //极大值，2个交点
				{  //aaaa
					if (spt[edge[j].num + 1].y < edge[j].ymax)
					{
						b++;
						p[b] = (int)edge[j].xmax;
					}
					if (spt[edge[j].num - 1].y < edge[j].ymax)
					{
						b++;
						p[b] = (int)edge[j].xmax;
					}
				} //aaaa
				if ((scan > edge[j].ymin) && (scan < edge[j].ymax)) //正常求交
				{//bbbb
					b++;
					p[b] = (int)(edge[j].xmax + edge[j].dx*(scan - edge[j].ymax));
				} //bbbb
			} //111
			if (scan <= edge[j].ymin)  //极小值不求交，0个交点，往后
				s = j;
		} //AA
		if (b > 1)   //若有交点，则进行划线填充
		{  //BB
			for (int u = 1;u < b;u++)
			{
				pDC->MoveTo(p[u], scan);
				u++;
				pDC->LineTo(p[u], scan);
			}
		} //BB
	} //3
}



void CMFCApplication11View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	CDC *pDC = GetDC();
	CPen newpen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *old = pDC->SelectObject(&newpen);
	CPoint spt[8], s_point;
	spt[0] = CPoint(100, 100);
	spt[1] = CPoint(300, 100);
	spt[2] = CPoint(250, 250);
	spt[3] = CPoint(100, 250);
	spt[4] = CPoint(150, 200);
	spt[5] = CPoint(90, 180);
	spt[6] = CPoint(150, 150);
	spt[7] = CPoint(100, 100);
	pDC->Polyline(spt, 8);
	s_point = CPoint(200, 200);
	SeedFill(spt, s_point, pDC);

}

void CMFCApplication11View::SeedFill(CPoint spt[], CPoint s_point, CDC *pDC)
{
	CDC dc;
	int fill = RGB(0, 255, 0);
	int boundary = RGB(255, 0, 0);
	int x, y, pmin, pmax;
	CPoint p0;
	for (int m = 1;m < 7;m++)
	{ //1求多边形最大、最小值
		for (int n = 0;n < 7 - m;n++)
		{
			if (spt[n].y < spt[n + 1].y)
			{
				p0 = spt[n];
				spt[n] = spt[n + 1];
				spt[n + 1] = p0;
			}
		}
	}  //1求多边形最大、最小值
	pmax = spt[0].y;
	pmin = spt[6].y;
	x = s_point.x;
	y = s_point.y;
	for (;y < pmax;y++)
	{  //2上半部分填充
		int current = pDC->GetPixel(x, y);
		while ((current != boundary) && (current != fill))
		{  //往右填充
			pDC->SetPixel(x, y, fill);
			x++;
			current = pDC->GetPixel(x, y);
		}
		x = s_point.x;  //复位
		x--;
		current = pDC->GetPixel(x, y);
		while ((current != boundary) && (current != fill))
		{  //往左填充
			pDC->SetPixel(x, y, fill);
			x--;
			current = pDC->GetPixel(x, y);
		}
		x = s_point.x;
	} //2上半部分填充
	x = s_point.x; //复位
	y = s_point.y;
	for (;y > pmin;y--)
	{   //3下半部分填充
		int current = pDC->GetPixel(x, y);
		while ((current != boundary) && (current != fill))
		{
			pDC->SetPixel(x, y, fill);
			x++;
			current = pDC->GetPixel(x, y);
		}
		x = s_point.x;
		x--;
		current = pDC->GetPixel(x, y);
		while ((current != boundary) && (current != fill))
		{
			pDC->SetPixel(x, y, fill);
			x--;
			current = pDC->GetPixel(x, y);
		}
		x = s_point.x;
	} //3下半部分填充
}
