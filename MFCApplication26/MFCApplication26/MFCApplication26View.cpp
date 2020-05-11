
// MFCApplication26View.cpp : CMFCApplication26View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCApplication26View ����/����

CMFCApplication26View::CMFCApplication26View()
	: CRecordView(IDD_MFCAPPLICATION26_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication26View::~CMFCApplication26View()
{
}

void CMFCApplication26View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_name);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_number);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_age);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_phone);
}

BOOL CMFCApplication26View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication26View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication26Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication26View ���

#ifdef _DEBUG
void CMFCApplication26View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication26View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication26Doc* CMFCApplication26View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication26Doc)));
	return (CMFCApplication26Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication26View ���ݿ�֧��
CRecordset* CMFCApplication26View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication26View ��Ϣ�������
