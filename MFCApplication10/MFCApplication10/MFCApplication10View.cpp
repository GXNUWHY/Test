
// MFCApplication10View.cpp: CMFCApplication10View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication10.h"
#endif

#include "graphics.h"
#include "MFCApplication10Doc.h"
#include "MFCApplication10View.h"
#define WINDOW_HEIGHT 9999

int M = 40, N = 60;
int pattern[40][60];

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication10View

IMPLEMENT_DYNCREATE(CMFCApplication10View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication10View, CView)
END_MESSAGE_MAP()

// CMFCApplication10View 构造/析构

CMFCApplication10View::CMFCApplication10View() noexcept
{
	// TODO: 在此处添加构造代码
	//******************************************//
	for (int i = 0;i < M;i++)
		for (int j = 0;j < N;j++)
			pattern[i][j] = 0;
	for (int j = 0;j < N;j++)
	{
		pattern[0][j] = 1; pattern[M / 2][j] = 1;
	}
	for (int i = 0;i < M / 2;i++)
	{
		pattern[i][0] = 1;
	}
	for (int i = M / 2;i < M;i++)
	{
		pattern[i][N / 2] = 1;
	}
	//***********************************************//
	for (int i = 0;i < 16;i++)
		for (int j = 0;j < 16;j++)
			pattern3[i][j] = 0;
	for (int i = 0; i < 16; ++i) {
		int j = i;
		pattern3[i][j] = 1;
		int k = 15 - i;
		pattern3[i][k] = 1;
	}
	//***********************************************//
	for (int i = 0;i < 50;i++)
		for (int j = 0;j < 50;j++)
			pattern4[i][j] = 0;
	for (int i = 0;i < 25;i++)
		for (int j = 0;j < 25;j++)
			pattern4[i][j] = 1;
	for (int i = 25;i < 50;i++)
		for (int j = 25;j < 50;j++)
			pattern4[i][j] = 1;
	//***********************************************//
}

CMFCApplication10View::~CMFCApplication10View()
{
}

BOOL CMFCApplication10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication10View 绘图

void CMFCApplication10View::OnDraw(CDC* pDC)
{
	CMFCApplication10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int cnt = 5;
	POINT *pts = new POINT[cnt];
	pts[0].x = 100;pts[0].y = 100;
	pts[1].x = 300;pts[1].y = 100;
	pts[2].x = 300;pts[2].y = 300;
	pts[3].x = 100;pts[3].y = 300;
	pts[4].x = 100;pts[4].y = 100;


	pDC->Polyline(pts, 5);
	ScanFill(cnt, pts, RGB(255,0,0));
}

void CMFCApplication10View::InsertEdge(Edge * list, Edge * edge)    /*按交点x的升序对边进行插入排序*/
{                                     /* list为有序边表，edge为待插入的边*/
	Edge *p, *q = list;
	p = q->next;
	while (p)
	{
		if (edge->x < p->x) p = NULL;      /* 停止循环，edge应插入到链表的头*/
		else { q = p; p = p->next; }           /* 遍历list*/
	}
	edge->next = q->next;    /* q指向edge应插入位置的前一个结点，edge插入到q之后*/
	q->next = edge;
}
int CMFCApplication10View::yNext(int k, int cnt, POINT * pts)   /*计算下一条非水平线的y值*/
{
	int j;
	if ((k + 1) > (cnt - 1)) j = 0;
	else  j = k + 1;
	while (pts[k].y == pts[j].y)
		if ((j + 1) > (cnt - 1)) j = 0;
		else  j++;
	return (pts[j].y);
}
void CMFCApplication10View::MakeEdgeRec(POINT lower, POINT upper, int yComp, Edge *edge, Edge *edges[])
/*生成有序边表的一条边*/
{
	edge->dx = (float)(upper.x - lower.x) / (upper.y - lower.y);
	edge->x = lower.x;
	if (upper.y < yComp)  edge->ymax = upper.y - 1;
	else  edge->ymax = upper.y;
	InsertEdge(edges[lower.y], edge);
}
void CMFCApplication10View::BuildEdgeList(int cnt, POINT * pts, Edge * edges[])
/*建立有序边表，每次从顶点数组中取出两个点，调用MakeEdgeRec来生成一条边，
并调用InsertEdge把建好的边插入到有序边表中*/
{
	Edge *edge;  POINT v1, v2;
	int i, ykrev = pts[cnt - 2].y;
	v1.x = pts[cnt - 1].x;  v1.y = pts[cnt - 1].y;
	for (i = 0; i < cnt; i++)
	{
		v2 = pts[i];
		if (v1.y != v2.y)
		{
			edge = (Edge *)malloc(sizeof(Edge));
			if (v1.y < v2.y)  MakeEdgeRec(v1, v2, yNext(i, cnt, pts), edge, edges);
			else  MakeEdgeRec(v2, v1, ykrev, edge, edges);
		}
		ykrev = v1.y;  v1 = v2;
	}
}
void CMFCApplication10View::BuildActiveList(int scan, Edge *active, Edge *edges[])  /*建立活化边表*/
{
	Edge *p, *q;
	p = edges[scan]->next;
	while (p)
	{
		q = p->next;  InsertEdge(active, p);  p = q;
	}
}

void CMFCApplication10View::FillScan(int scan, Edge *active, int color)  /*对当前扫描线填充*/
{
	int i;  Edge *p1, *p2;
	CDC *pDC = GetDC();
	p1 = active->next;
	while (p1)
	{
		p2 = p1->next;
		for (i = p1->x; i < p2->x; i++) {

			//pDC->SetPixel(i, scan, color);

			//if (pattern2[i % 8][scan % 8])
				//pDC->SetPixel(i, scan, color);

			//if (pattern[i % M][scan % N])
				//pDC->SetPixel(i, scan, color);

			//if (pattern3[i % 16][scan % 16]) {
				//pDC->SetPixel(i, scan, color);
			//}
			if (pattern4[i % 50][scan % 50])
				pDC->SetPixel(i, scan, color);

		//color = (color + 12777215) % 16777215;
		}

		p1 = p2->next;
	}
}
void CMFCApplication10View::DeleteAfter(Edge *q)   /*删除不再相交的边*/
{
	Edge *p = q->next;
	q->next = p->next;
	free(p);
}
void CMFCApplication10View::UpdateActiveList(int scan, Edge *active)   /*为下一条扫描线进行更新*/
{
	Edge *q = active, *p = active->next;
	while (p)
	{
		if (scan >= p->ymax) /*如果当前扫描线scan的值大于p所指向的边的ymax，则删除该边*/
		{
			p = p->next;  DeleteAfter(q);
		}
		else        /* 否则p所指向的边的x值加一个dx*/
		{
			p->x = p->x + p->dx;  q = p; p = p->next;
		}
	}
}
	void CMFCApplication10View::ResortActiveList(Edge *active)  /*重排活化边表*/
	{
		Edge *q, *p = active->next;
		active->next = NULL;
		while (p)
		{
			q = p->next; InsertEdge(active, p); p = q;
		}
	}
	void CMFCApplication10View::ScanFill(int cnt, POINT *pts, int color)  /* cnt为多边形的顶点数，pts为顶点坐标数组*/
	{
		Edge *edges[WINDOW_HEIGHT], *active;
		int i, scan, scanmax = 0, scanmin = WINDOW_HEIGHT;
		for (i = 0; i < cnt - 1; i++)   /* 求填充区域的扫描线最大值scanmax和最小值scanmin*/
		{
			if (scanmax < pts[i].y) scanmax = pts[i].y;
			if (scanmin > pts[i].y) scanmin = pts[i].y;
		}
		for (scan = scanmin; scan <= scanmax; scan++)  /* 初始化每条扫描线的边链表*/
		{
			edges[scan] = (Edge *)malloc(sizeof(Edge));
			edges[scan]->next = NULL;
		}
		BuildEdgeList(cnt, pts, edges);  /* 用顶点坐标pts建立有序边表，放在edges中*/
		active = (Edge *)malloc(sizeof(Edge));   /*初始化活化边表*/
		active->next = NULL;
		for (scan = scanmin; scan <= scanmax; scan++)
		{
			BuildActiveList(scan, active, edges);   /*建立当前扫描线scan的活化边表*/
			if (active->next)
			{
				FillScan(scan, active, color);  /*填充当前扫描线*/
				UpdateActiveList(scan, active);   /*为下一条扫描线更新活化边表*/
				ResortActiveList(active);    /*重排活化边表*/
			}
		}
	}


// CMFCApplication10View 诊断

#ifdef _DEBUG
void CMFCApplication10View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication10Doc* CMFCApplication10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication10Doc)));
	return (CMFCApplication10Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication10View 消息处理程序
