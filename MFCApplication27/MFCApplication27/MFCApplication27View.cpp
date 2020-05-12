
// MFCApplication27View.cpp : CMFCApplication27View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication27.h"
#endif

#include "MFCApplication27Set.h"
#include "MFCApplication27Doc.h"
#include "MFCApplication27View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication27View

IMPLEMENT_DYNCREATE(CMFCApplication27View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication27View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication27View::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication27View::OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication27View::OnRecordPrev)
END_MESSAGE_MAP()

// CMFCApplication27View 构造/析构

CMFCApplication27View::CMFCApplication27View()
	: CRecordView(IDD_MFCAPPLICATION27_FORM)
	, number(_T(""))
	, name(_T(""))
	, age(_T(""))
	, picpath(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	//GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);

}

CMFCApplication27View::~CMFCApplication27View()
{
}

void CMFCApplication27View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_number);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_name);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_age);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_picpath);
}

BOOL CMFCApplication27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication27View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication27Set;
	CRecordView::OnInitialUpdate();
	GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
}


// CMFCApplication27View 诊断

#ifdef _DEBUG
void CMFCApplication27View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication27View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication27Doc* CMFCApplication27View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication27Doc)));
	return (CMFCApplication27Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication27View 数据库支持
CRecordset* CMFCApplication27View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication27View 消息处理程序


void CMFCApplication27View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CClientDC dc(this);
	CImage img;
	//CString filepath = m_pSet->m_picpath;
	
	CString s;
	GetDlgItemText(IDC_EDIT4, s);//从指定ID号的编辑控件中读取

	img.Load(s);
	img.Draw(dc.m_hDC, 300, 0, img.GetWidth(), img.GetHeight());
}


void CMFCApplication27View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CImage img;
	CString s;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	//GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
	GetDlgItemText(IDC_EDIT4, s);//从指定ID号的编辑控件中读取
	int width;
	int height;
	CRect rect;

	img.Load(s);
	img.Draw(pDC->m_hDC, 0, 0, 300, 300);

	//InvalidateRect(picRect);
}


void CMFCApplication27View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
	}
	UpdateData(false);
	InvalidateRect(picRect);

}


void CMFCApplication27View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	InvalidateRect(picRect);
}
