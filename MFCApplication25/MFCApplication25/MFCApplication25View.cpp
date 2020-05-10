
// MFCApplication25View.cpp: CMFCApplication25View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication25.h"
#endif

#include "MFCApplication25Doc.h"
#include "MFCApplication25View.h"

#include "MyClass.h"
#include "math.h"
#define PI  3.141926


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication25View

IMPLEMENT_DYNCREATE(CMFCApplication25View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication25View, CView)
END_MESSAGE_MAP()

// CMFCApplication25View 构造/析构

CMFCApplication25View::CMFCApplication25View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication25View::~CMFCApplication25View()
{
}

BOOL CMFCApplication25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication25View 绘图

void CMFCApplication25View::OnDraw(CDC* pDC)
{
	CMFCApplication25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	int i, j;
	CMyClass my1;  //构造新的CMyClass对象
 //将图形变换矩阵清零
	for (i = 1;i <= 3;++i)
	{
		for (j = 1;j <= 3;++j)
			my1.A1[i][j] = 0;
	}
	//给图形变换矩阵赋值
	my1.A1[1][1] = 1;
	my1.A1[2][2] = 1;
	my1.A1[3][3] = 1;
	//将图形变换矩阵清零
	for (i = 1;i <= 3;++i)
	{
		for (j = 1;j <= 3;++j)
			my1.A[i][j] = 0;
	}
	my1.Display();
	//OnMirrorO();//关于原点对称
	//OnRotation();//绕原点顺时针旋转
	//OnScaling();//比例变换
	//OnTranslation();//平移变换
	//OnEnlarge();//放大变换
	//symmetry();//对称变换
	dislocation();//错切变换
}


// CMFCApplication25View 诊断

#ifdef _DEBUG
void CMFCApplication25View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication25Doc* CMFCApplication25View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication25Doc)));
	return (CMFCApplication25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication25View 消息处理程序

void CMFCApplication25View::OnMirrorO()
{
	// TODO: Add your command handler code here
	int i, j;
	CMyClass my1;  //构造新的CMyClass对象

	//将图形变换矩阵清零
	for (i = 1;i <= 3;++i)
	{
		for (j = 1;j <= 3;++j)
			my1.A[i][j] = 0;
	}

	//给图形变换矩阵赋值
	my1.A[1][1] = -1;
	my1.A[2][2] = -1;
	my1.A[3][3] = 1;
	//RedrawWindow();
	my1.Display();
}
void CMFCApplication25View::OnRotation()
{
	// TODO: Add your command handler code here
	int i, j;
	CMyClass my1;  //构造新的CMyClass对象
	//将图形变换矩阵清零
	for (i = 1;i <= 3;++i)
	{
		for (j = 1;j <= 3;++j)
			my1.A[i][j] = 0;
	}
	//给图形变换矩阵赋值
	my1.A[1][1] = cos(PI * 90 / 180);//旋转90度
	my1.A[1][2] = sin(PI * 90 / 180);
	my1.A[2][1] = -sin(PI * 90 / 180);
	my1.A[2][2] = cos(PI * 90 / 180);

	/*my1.A[1][1] = cos(PI * 60 / 180);//旋转60度
	my1.A[1][2] = sin(PI * 60 / 180);
	my1.A[2][1] = -sin(PI * 60 / 180);
	my1.A[2][2] = cos(PI * 60 / 180);*/

	my1.A[3][3] = 1;
	//RedrawWindow();
	my1.Display();

}
void CMFCApplication25View::OnScaling()
{
	// TODO: Add your command handler code here
	int i, j;
	CMyClass my1;  //构造新的CMyClass对象
	//将图形变换矩阵清零
	for (i = 1;i <= 3;++i)
	{
		for (j = 1;j <= 3;++j)
			my1.A[i][j] = 0;
	}
	//给图形变换矩阵赋值
	my1.A[1][1] = 5;
	my1.A[2][2] = 2;
	my1.A[3][3] = 1;
	//RedrawWindow();
	my1.Display();
}
void CMFCApplication25View::OnTranslation()
{
	// TODO: Add your command handler code here
	int i, j;
	CMyClass my1;  //构造新的CMyClass对象
	//将图形变换矩阵清零
	for (i = 1;i <= 3;++i)
	{
		for (j = 1;j <= 3;++j)
			my1.A[i][j] = 0;
	}
	//给图形变换矩阵赋值
	my1.A[1][1] = 1;
	my1.A[2][2] = 1;
	my1.A[3][1] = 15;
	my1.A[3][2] = 45;
	my1.A[3][3] = 1;
	//RedrawWindow();
	my1.Display();
}

void CMFCApplication25View::OnEnlarge() {
	// TODO: Add your command handler code here
	int i, j;
	CMyClass my1;  //构造新的CMyClass对象
	//将图形变换矩阵清零
	for (i = 1;i <= 3;++i)
	{
		for (j = 1;j <= 3;++j)
			my1.A[i][j] = 0;
	}
	//给图形变换矩阵赋值
	my1.A[1][1] = 3;
	my1.A[2][2] = 3;
	
	my1.A[3][3] = 1;
	//RedrawWindow();
	my1.Display();
}
void CMFCApplication25View::symmetry() {
	// TODO: Add your command handler code here
	int i, j;
	CMyClass my1;  //构造新的CMyClass对象
	//将图形变换矩阵清零
	for (i = 1;i <= 3;++i)
	{
		for (j = 1;j <= 3;++j)
			my1.A[i][j] = 0;
	}
	//给图形变换矩阵赋值

	/*my1.A[1][1] = 1;
	my1.A[2][2] = -1;
	my1.A[3][3] = 1;*/

	my1.A[1][2] = 1;
	my1.A[2][1] = 1;
	my1.A[3][3] = 1;

	//RedrawWindow();
	my1.Display();
}

void CMFCApplication25View::dislocation() {
	// TODO: Add your command handler code here
	int i, j;
	CMyClass my1;  //构造新的CMyClass对象
	//将图形变换矩阵清零
	for (i = 1;i <= 3;++i)
	{
		for (j = 1;j <= 3;++j)
			my1.A[i][j] = 0;
	}
	//给图形变换矩阵赋值


	my1.A[1][1] = 1;
	my1.A[2][1] = 1;
	my1.A[2][2] = 1;
	my1.A[3][3] = 1;

	//RedrawWindow();
	my1.Display();
}