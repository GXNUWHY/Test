
// MFCApplication8View.cpp: CMFCApplication8View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication8.h"
#endif

#include "MFCApplication8Doc.h"
#include "MFCApplication8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication8View

IMPLEMENT_DYNCREATE(CMFCApplication8View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication8View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// CMFCApplication8View 构造/析构

CMFCApplication8View::CMFCApplication8View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication8View::~CMFCApplication8View()
{
}

BOOL CMFCApplication8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication8View 绘图

void CMFCApplication8View::OnDraw(CDC* pDC)
{
	CMFCApplication8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(190, 190, 510, 500);
}


// CMFCApplication8View 诊断

#ifdef _DEBUG
void CMFCApplication8View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication8Doc* CMFCApplication8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication8Doc)));
	return (CMFCApplication8Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication8View 消息处理程序

int i = 1;
CString s;
int x;
int y;
void CMFCApplication8View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString ch;
	CClientDC dc(this);

	//s.AppendChar(nChar);
	/*if (i >= 1) {
		s.Append(_T("abc"));
	}
	if (i == 2) {
		s.Append('1');
	}
	if (i == 3) {
		s.AppendChar('2 ');
	}
	++i;*/
	
	int position;
	int flag;
	CRect Rect(200, 200, 500, 500);

	ch.Format(_T("%c"), nChar);

	if (x >= 200 && y >= 200) {
		position = (x - 200) / 10 + (y - 200) / 20 * 30;

		s.Insert(position, nChar);
	}
	else {
		s.Append(ch);
	}
	/*if (s.GetLength() == 30 * i) {
		s.Append(_T("\r\n"));
		++i;
	}*/
	
	dc.DrawText(s, Rect, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCApplication8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	x = point.x;
	y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


BOOL CMFCApplication8View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCursor(LoadCursor(NULL, IDC_IBEAM)); //设定光标为箭头，就是我们平时用的。

	return TRUE;

	return CView::OnSetCursor(pWnd, nHitTest, message);
}
