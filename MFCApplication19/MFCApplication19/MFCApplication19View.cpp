
// MFCApplication19View.cpp: CMFCApplication19View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication19.h"
#endif

#include "MFCApplication19Doc.h"
#include "MFCApplication19View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication19View

IMPLEMENT_DYNCREATE(CMFCApplication19View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication19View, CView)
END_MESSAGE_MAP()

// CMFCApplication19View 构造/析构

CMFCApplication19View::CMFCApplication19View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication19View::~CMFCApplication19View()
{
}

BOOL CMFCApplication19View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication19View 绘图

void CMFCApplication19View::OnDraw(CDC* pDC)
{
	CMFCApplication19Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int N = 5;
	int color;
	CPoint *ply = new CPoint[N];

	ply[0] = CPoint(250, 50);
	ply[1] = CPoint(450, 180);
	ply[2] = CPoint(400, 350);
	ply[3] = CPoint(200, 400);
	ply[4] = CPoint(20, 200);


	/*ply[0] = CPoint(200, 50);
	ply[1] = CPoint(300, 20);
	ply[2] = CPoint(400, 200);
	ply[3] = CPoint(350, 300);
	ply[4] = CPoint(150, 100);*/


	CPoint p1(50, 100), p2(550, 300);
	CPoint pl, pu;

	PNT *nv = new PNT[N];
	PolyVector(N, ply, nv);

	color = RGB(0, 0, 255);
	CPen pen1(PS_SOLID, 1, color);
	pDC->SelectObject(&pen1);
	pDC->Polygon(ply, N);

	color = RGB(0, 255, 0);
	CPen pen2(PS_DOT, 1, color);
	pDC->SelectObject(&pen2);
	pDC->MoveTo(p1.x, p1.y);
	pDC->LineTo(p2.x, p2.y);

	int sig;
	float t1 = 0.0f, t2 = 0.0f;
	sig = Cyrus_Beck(N, ply, nv, p1, p2, t1, t2);
	pl = p1;
	pu = p2;

	if (sig) {
		pl.x = p1.x + (p2.x - p1.x)*t1;
		pl.y = p1.y + (p2.y - p1.y)*t1;

		pu.x = p1.x + (p2.x - p1.x)*t2;
		pu.y = p1.y + (p2.y - p1.y)*t2;
	}

	color = RGB(255, 0, 0);
	CPen pen3(PS_SOLID, 2, color);
	pDC->SelectObject(&pen3);
	pDC->MoveTo(pl.x, pl.y);
	pDC->LineTo(pu.x, pu.y);


}

void CMFCApplication19View::PolyVector(int &k, POINT *ply, PNT *nv)
{ //根据多边形的边数k,节点坐标数组ply[],求各边的法向量nv[]
	int i;
	float a, b;
	for (i = 0;i < k;i++) //各边线段迭代求解法向量
	{ //各边线段方程F(x,y)=ax+by+c
		a = (float)ply[i].y - ply[(i + 1) % k].y;//a=y1-y2
		b = (float)ply[(i + 1) % k].x - ply[i].x;//b=x2-x1
		nv[i].x = a; //法向量Ni获取
		nv[i].y = b;
	}
}


int CMFCApplication19View::Cyrus_Beck(int k, POINT ply[], PNT nv[], POINT p1, POINT p2, float &t1, float &t2)
{
	int i, j;
	float t, tl, tu, dn, nw;
	tl = 0.0;tu = 1.0;
	for (i = 0;i < k;i++)   //多边形逐边迭代
	{
		dn = (float)(p2.x - p1.x)*nv[i].x + (p2.y - p1.y)*nv[i].y;  //dn=Ni*(P2-P1)
		nw = (float)(p1.x - ply[i].x)*nv[i].x + (p1.y - ply[i].y)*nv[i].y;  //nw=Ni*(P1-Ai)
		if (fabs(dn) < 0.000001)     //线段P1P2与多边形边平行情况
		{
			if (nw >= 0.0) continue;else return (0);
		}   //线段P1P2在多边形内，则继续；反之，则退出。
		else
		{   //线段P1P2与多边形边相交情况
			t = -nw / dn;   //求交点
			if (dn < 0.0)
			{  //线段由里向外
				if (t < tu)tu = t;
			}
			else
			{  //线段由外向里
				if (t > tl)tl = t;
			}
		}
		if (tl > tu)return(0);     //线段P1P2在多边形外部情况
	}//for loop
	t1 = tl;  //线段与多边形的最后参数t
	t2 = tu;
	return (1);
}



// CMFCApplication19View 诊断

#ifdef _DEBUG
void CMFCApplication19View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication19View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication19Doc* CMFCApplication19View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication19Doc)));
	return (CMFCApplication19Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication19View 消息处理程序
