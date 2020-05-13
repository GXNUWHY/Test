
// MFCApplication29View.cpp : CMFCApplication29View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication29.h"
#endif

#include "MFCApplication29Set.h"
#include "MFCApplication29Doc.h"
#include "MFCApplication29View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication29View

IMPLEMENT_DYNCREATE(CMFCApplication29View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication29View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCApplication29View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication29View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication29View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCApplication29View::OnRecordLast)
END_MESSAGE_MAP()

// CMFCApplication29View 构造/析构

CMFCApplication29View::CMFCApplication29View()
	: CRecordView(IDD_MFCAPPLICATION29_FORM)
	, picname(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	
}

CMFCApplication29View::~CMFCApplication29View()
{
}

void CMFCApplication29View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL CMFCApplication29View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication29View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication29Set;
	CRecordView::OnInitialUpdate();

	GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
	


}


// CMFCApplication29View 诊断

#ifdef _DEBUG
void CMFCApplication29View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication29View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication29Doc* CMFCApplication29View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication29Doc)));
	return (CMFCApplication29Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication29View 数据库支持
CRecordset* CMFCApplication29View::OnGetRecordset()
{
	return m_pSet;
}

void CMFCApplication29View::draw_pic(CString file)
{
	//CDC *pDC = GetDC();
	//pDC->TextOutW(0, 0, file);
	CImage img;
	img.Load(file);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(rect);

	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio) {
	h = rect.Height();
	w = img_ratio * h;
	sx = (rect.Width() - w) / 2;
	sy = 0;
	}
	else {
	w = rect.Width();
	h = w / img_ratio;
	sy = 0;
	sy = (rect.Height() - h) / 2;
	}
	img.Draw(pDC->m_hDC, sx, sy, w, h);

}



// CMFCApplication29View 消息处理程序


void CMFCApplication29View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);

	//CString name = picname;
	//GetDlgItemText(IDC_STATIC, name);

	CString name = m_pSet->column1;
	CString filepath = path + name;

	InvalidateRect(picRect);
	draw_pic(filepath);

}


void CMFCApplication29View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);

	CString name = m_pSet->column1;
	CString filepath = path + name;
	InvalidateRect(picRect);
	draw_pic(filepath);
}


void CMFCApplication29View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
	}
	UpdateData(false);

	CString name = m_pSet->column1;
	CString filepath = path + name;
	InvalidateRect(picRect);
	draw_pic(filepath);
}


void CMFCApplication29View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);

	CString name = m_pSet->column1;
	CString filepath = path + name;
	InvalidateRect(picRect);
	draw_pic(filepath);
}
