
// MFCApplication28Set.cpp : CMFCApplication28Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication28.h"
#include "MFCApplication28Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication28Set ʵ��

// ���������� 2020��5��13��, 14:46

IMPLEMENT_DYNAMIC(CMFCApplication28Set, CRecordset)

CMFCApplication28Set::CMFCApplication28Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}
// #error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication28Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f;UID=sa;PWD=123456;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=DESKTOP-HKNCPI4;DATABASE=mfcdb");
}

CString CMFCApplication28Set::GetDefaultSQL()
{
	return _T("[dbo].[Table_3]");
}

void CMFCApplication28Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[ͼƬ�ļ���]"), column1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication28Set ���

#ifdef _DEBUG
void CMFCApplication28Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication28Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

