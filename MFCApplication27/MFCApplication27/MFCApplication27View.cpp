
// MFCApplication27View.cpp : CMFCApplication27View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCApplication27View ����/����

CMFCApplication27View::CMFCApplication27View()
	: CRecordView(IDD_MFCAPPLICATION27_FORM)
	, number(_T(""))
	, name(_T(""))
	, age(_T(""))
	, picpath(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	//GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);

}

CMFCApplication27View::~CMFCApplication27View()
{
}

void CMFCApplication27View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_number);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_name);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_age);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_picpath);
}

BOOL CMFCApplication27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication27View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication27Set;
	CRecordView::OnInitialUpdate();
	GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
}


// CMFCApplication27View ���

#ifdef _DEBUG
void CMFCApplication27View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication27View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication27Doc* CMFCApplication27View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication27Doc)));
	return (CMFCApplication27Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication27View ���ݿ�֧��
CRecordset* CMFCApplication27View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication27View ��Ϣ�������


void CMFCApplication27View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CClientDC dc(this);
	CImage img;
	//CString filepath = m_pSet->m_picpath;
	
	CString s;
	GetDlgItemText(IDC_EDIT4, s);//��ָ��ID�ŵı༭�ؼ��ж�ȡ

	img.Load(s);
	img.Draw(dc.m_hDC, 300, 0, img.GetWidth(), img.GetHeight());
}


void CMFCApplication27View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CImage img;
	CString s;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	//GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
	GetDlgItemText(IDC_EDIT4, s);//��ָ��ID�ŵı༭�ؼ��ж�ȡ
	int width;
	int height;
	CRect rect;

	img.Load(s);
	img.Draw(pDC->m_hDC, 0, 0, 300, 300);

	//InvalidateRect(picRect);
}


void CMFCApplication27View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
	}
	UpdateData(false);
	InvalidateRect(picRect);

}


void CMFCApplication27View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	InvalidateRect(picRect);
}
