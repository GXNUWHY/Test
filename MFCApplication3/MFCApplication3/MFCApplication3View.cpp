
// MFCApplication3View.cpp: CMFCApplication3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3View

IMPLEMENT_DYNCREATE(CMFCApplication3View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication3View, CView)
	ON_COMMAND(ID_32771, &CMFCApplication3View::OnShowName)
	ON_COMMAND(ID_32772, &CMFCApplication3View::OnDrawLine)
	ON_COMMAND(ID_32773, &CMFCApplication3View::OnDrawRect)
	ON_COMMAND(ID_32774, &CMFCApplication3View::OnDrawEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32775, &CMFCApplication3View::OnShowBitmap)
END_MESSAGE_MAP()

// CMFCApplication3View 构造/析构

CMFCApplication3View::CMFCApplication3View() noexcept
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmapW(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMFCApplication3View::~CMFCApplication3View()
{
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication3View 绘图

void CMFCApplication3View::OnDraw(CDC* pDC)
{
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	/*CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);

	pDC->BitBlt(0, 0, m_nWidth, m_nHeight,&MemDC , 0, 0, SRCCOPY);*/

	if (flag == 1) {
		switch (mode) {
		case 1:pDC->MoveTo(startx, starty);
			pDC->LineTo(pointarr.x, pointarr.y);
			break;
		case 2:pDC->Rectangle(startx, starty, pointarr.x, pointarr.y);

			break;
		case 3:pDC->Ellipse(startx, starty, pointarr.x, pointarr.y);
			break;
		default:;
		}
	}

}


// CMFCApplication3View 诊断

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View 消息处理程序


void CMFCApplication3View::OnShowName()
{
	// TODO: 在此添加命令处理程序代码
	CString namestr;
	CClientDC dc(this);

	namestr.Format(_T("吴航宇"));
	dc.TextOutW(100, 100, namestr);
}


void CMFCApplication3View::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	mode = 1;
}


void CMFCApplication3View::OnDrawRect()
{
	// TODO: 在此添加命令处理程序代码
	mode = 2;
}


void CMFCApplication3View::OnDrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	mode = 3;
}


void CMFCApplication3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	startx = point.x;
	starty = point.y;
	flag = 1;
	CView::OnLButtonDown(nFlags, point);
}

void CMFCApplication3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	//dc.SelectStockObject(NULL_BRUSH);

	pointarr = point;
	if (flag == 1 && mode != 0) {
		Invalidate();
	}
	
	
	CView::OnMouseMove(nFlags, point);
}

void CMFCApplication3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;
	CClientDC dc(this);
	

	//pointarr.Add(point);


	CView::OnLButtonUp(nFlags, point);
}

void CMFCApplication3View::OnShowBitmap()
{
	// TODO: 在此添加命令处理程序代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);

	CClientDC dc(this);
	dc.BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
}
