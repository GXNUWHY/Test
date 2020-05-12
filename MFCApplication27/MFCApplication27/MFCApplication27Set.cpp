
// MFCApplication27Set.cpp : CMFCApplication27Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication27.h"
#include "MFCApplication27Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication27Set ʵ��

// ���������� 2020��5��12��, 20:03

IMPLEMENT_DYNAMIC(CMFCApplication27Set, CRecordset)

CMFCApplication27Set::CMFCApplication27Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_number = L"";
	m_name = L"";
	m_age = L"";
	m_picpath = L"";
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
// #error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication27Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f;UID=sa;PWD=123456;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=DESKTOP-HKNCPI4;DATABASE=mfcdb");
}

CString CMFCApplication27Set::GetDefaultSQL()
{
	return _T("[dbo].[Table_2]");
}

void CMFCApplication27Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[age]"), m_age);
	RFX_Text(pFX, _T("[picpath]"), m_picpath);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication27Set ���

#ifdef _DEBUG
void CMFCApplication27Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication27Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

