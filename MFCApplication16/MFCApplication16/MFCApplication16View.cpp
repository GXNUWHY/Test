
// MFCApplication16View.cpp: CMFCApplication16View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication16.h"
#endif

#include "SHOWDIA.h"
#include "MFCApplication16Doc.h"
#include "MFCApplication16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication16View

IMPLEMENT_DYNCREATE(CMFCApplication16View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication16View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SHOW_FILENAME, &CMFCApplication16View::OnShowFilename)
END_MESSAGE_MAP()

// CMFCApplication16View 构造/析构

CMFCApplication16View::CMFCApplication16View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication16View::~CMFCApplication16View()
{
}

BOOL CMFCApplication16View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication16View 绘图

void CMFCApplication16View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication16Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication16View 诊断

#ifdef _DEBUG
void CMFCApplication16View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication16View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication16Doc* CMFCApplication16View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication16Doc)));
	return (CMFCApplication16Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication16View 消息处理程序

CString filename;
void CMFCApplication16View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog CFD(true);
	CDC *pDC = GetDC();
	if (CFD.DoModal() == IDOK) {
		filename = CFD.GetFileName();
		pDC->TextOutW(200, 200, filename);
	}


	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCApplication16View::OnShowFilename()
{
	// TODO: 在此添加命令处理程序代码
	SHOWDIA showfilenamedia;
	showfilenamedia.filename = filename;
	//showfilenamedia.filename2.AddString(filename);


	/*与非CString成员之类的非窗口类型相比，作为对话框控件的成员只有在对话框被调用后才会处于使用状态DoModal()。

断言是调试宏，这就是为什么你没有在Release配置中指出问题的原因。

填充列表框控件的正确位置通常是OnInitDialog覆盖成员函数。该对话框随后被该阶段调用，并且该对话框拥有的控件将具有窗口句柄并且可以被使用。

如果希望在调用对话框之前将字符串文字传递给对话框，则可以将CString作为对话框类的成员变量。这样的成员在构建类实例时存在，并且可以通过构造函数，公共设置者或通过公共可访问性来设置。*/

	if (showfilenamedia.DoModal() == IDOK) {

	}

}
