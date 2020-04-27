
// MFCApplication22View.cpp: CMFCApplication22View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication22.h"
#endif

#include "MFCApplication22Doc.h"
#include "MFCApplication22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication22View

IMPLEMENT_DYNCREATE(CMFCApplication22View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication22View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication22View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCApplication22View 构造/析构

CMFCApplication22View::CMFCApplication22View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication22View::~CMFCApplication22View()
{
}

BOOL CMFCApplication22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication22View 绘图

void CMFCApplication22View::OnDraw(CDC* pDC)
{
	CMFCApplication22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(200, 200, pDoc->path);
}


// CMFCApplication22View 打印

BOOL CMFCApplication22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication22View 诊断

#ifdef _DEBUG
void CMFCApplication22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication22Doc* CMFCApplication22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication22Doc)));
	return (CMFCApplication22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication22View 消息处理程序


void CMFCApplication22View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	if (cfd.DoModal() == IDOK) {

	}
}
