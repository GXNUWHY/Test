
// MFCApplication29View.cpp : CMFCApplication29View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCApplication29View ����/����

CMFCApplication29View::CMFCApplication29View()
	: CRecordView(IDD_MFCAPPLICATION29_FORM)
	, picname(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	
}

CMFCApplication29View::~CMFCApplication29View()
{
}

void CMFCApplication29View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL CMFCApplication29View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication29View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication29Set;
	CRecordView::OnInitialUpdate();

	GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
	


}


// CMFCApplication29View ���

#ifdef _DEBUG
void CMFCApplication29View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication29View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication29Doc* CMFCApplication29View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication29Doc)));
	return (CMFCApplication29Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication29View ���ݿ�֧��
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



// CMFCApplication29View ��Ϣ�������


void CMFCApplication29View::OnRecordFirst()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);

	CString name = m_pSet->column1;
	CString filepath = path + name;
	InvalidateRect(picRect);
	draw_pic(filepath);
}
