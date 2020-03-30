
// MFCApplication7View.cpp: CMFCApplication7View 类的实现
//

#include "pch.h"
#include "framework.h"


// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication7.h"
#endif

#include "MFCApplication7Doc.h"
#include "MFCApplication7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication7View

IMPLEMENT_DYNCREATE(CMFCApplication7View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication7View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication7View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCApplication7View 构造/析构

CMFCApplication7View::CMFCApplication7View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication7View::~CMFCApplication7View()
{
}

BOOL CMFCApplication7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication7View 绘图

void CMFCApplication7View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication7View 诊断

#ifdef _DEBUG
void CMFCApplication7View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication7Doc* CMFCApplication7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication7Doc)));
	return (CMFCApplication7Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication7View 消息处理程序


void CMFCApplication7View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog jpgfile(true);
	CString filepath;
	CClientDC dc(this);

	if (jpgfile.DoModal() == IDOK) {
		filepath = jpgfile.GetPathName();

		CImage image;
		image.Load(filepath);
		image.Draw(dc.m_hDC, 0, 0, image.GetWidth(), image.GetHeight());
	}
}
