
// MFCApplication26View.cpp : CMFCApplication26View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication26.h"
#endif

#include "MFCApplication26Set.h"
#include "MFCApplication26Doc.h"
#include "MFCApplication26View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication26View

IMPLEMENT_DYNCREATE(CMFCApplication26View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication26View, CRecordView)
END_MESSAGE_MAP()

// CMFCApplication26View 构造/析构

CMFCApplication26View::CMFCApplication26View()
	: CRecordView(IDD_MFCAPPLICATION26_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCApplication26View::~CMFCApplication26View()
{
}

void CMFCApplication26View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_name);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_number);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_age);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_phone);
}

BOOL CMFCApplication26View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication26View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication26Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication26View 诊断

#ifdef _DEBUG
void CMFCApplication26View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication26View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication26Doc* CMFCApplication26View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication26Doc)));
	return (CMFCApplication26Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication26View 数据库支持
CRecordset* CMFCApplication26View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication26View 消息处理程序
