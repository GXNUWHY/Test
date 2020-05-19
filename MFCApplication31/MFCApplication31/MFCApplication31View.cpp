
// MFCApplication31View.cpp : CMFCApplication31View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication31.h"
#endif

#include "MFCApplication31Set.h"
#include "MFCApplication31Doc.h"
#include "MFCApplication31View.h"
#include "AddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication31View

IMPLEMENT_DYNCREATE(CMFCApplication31View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication31View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication31View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication31View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication31View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CMFCApplication31View 构造/析构

CMFCApplication31View::CMFCApplication31View()
	: CRecordView(IDD_MFCAPPLICATION31_FORM)
	, num(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCApplication31View::~CMFCApplication31View()
{
}

void CMFCApplication31View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_num);
}

BOOL CMFCApplication31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication31View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication31Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication31View 诊断

#ifdef _DEBUG
void CMFCApplication31View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication31View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication31Doc* CMFCApplication31View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication31Doc)));
	return (CMFCApplication31Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication31View 数据库支持
CRecordset* CMFCApplication31View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication31View 消息处理程序

void CMFCApplication31View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	AddDlg adddlg;

	if (adddlg.DoModal() == IDOK) {
		long num = adddlg.i;

		m_pSet->AddNew();
		m_pSet->m_num = num;
		m_pSet->Update();
	}
	UpdateData(false);

}

void CMFCApplication31View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	AddDlg adddlg;

	adddlg.i = m_pSet->m_num;

	if (adddlg.DoModal() == IDOK) {
		long num = adddlg.i;

		m_pSet->Edit();
		m_pSet->m_num = num;
		m_pSet->Update();
	}
	UpdateData(false);

}

void CMFCApplication31View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);
}

