
// MFCApplication28View.cpp : CMFCApplication28View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication28.h"
#endif

#include "MFCApplication28Set.h"
#include "MFCApplication28Doc.h"
#include "MFCApplication28View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication28View

IMPLEMENT_DYNCREATE(CMFCApplication28View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication28View, CRecordView)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication28View::OnRecordNext)
END_MESSAGE_MAP()

// CMFCApplication28View ����/����

CMFCApplication28View::CMFCApplication28View()
	: CRecordView(IDD_MFCAPPLICATION28_FORM)
	, picname(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication28View::~CMFCApplication28View()
{
}

void CMFCApplication28View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL CMFCApplication28View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication28View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication28Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication28View ���

#ifdef _DEBUG
void CMFCApplication28View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication28View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication28Doc* CMFCApplication28View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication28Doc)));
	return (CMFCApplication28Doc*)m_pDocument;
}
#endif //_DEBUG


void CMFCApplication28View::draw_pic(CString file)
{
	

	/*CImage img;
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
	img.Draw(pDC->m_hDC, sx, sy, w, h);*/

}

// CMFCApplication28View ���ݿ�֧��
CRecordset* CMFCApplication28View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication28View ��Ϣ�������


void CMFCApplication28View::OnRecordNext()
{
	// TODO: �ڴ��������������� 
	m_pSet->MoveNext();
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
	}
	UpdateData(false);
	CString filepath, name;
	GetDlgItemText(IDC_STATIC, name);
	//filepath.Append(path);
	//filepath.Append(name);

	//draw_pic(filepath);

}
