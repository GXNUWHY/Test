
// MFCApplication26Set.cpp : CMFCApplication26Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication26.h"
#include "MFCApplication26Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication26Set ʵ��

// ���������� 2020��5��11��, 20:37

IMPLEMENT_DYNAMIC(CMFCApplication26Set, CRecordset)

CMFCApplication26Set::CMFCApplication26Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_name = L"";
	m_number = L"";
	m_age = L"";
	m_phone = L"";
	m_nFields = 5;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication26Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f;UID=sa;PWD=123456;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=DESKTOP-HKNCPI4;DATABASE=mfcdb");
}

CString CMFCApplication26Set::GetDefaultSQL()
{
	return _T("[dbo].[Table_1]");
}

void CMFCApplication26Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[age]"), m_age);
	RFX_Text(pFX, _T("[phone]"), m_phone);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication26Set ���

#ifdef _DEBUG
void CMFCApplication26Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication26Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

