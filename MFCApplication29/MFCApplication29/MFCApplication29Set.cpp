
// MFCApplication29Set.cpp : CMFCApplication29Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication29.h"
#include "MFCApplication29Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication29Set ʵ��

// ���������� 2020��5��13��, 15:44

IMPLEMENT_DYNAMIC(CMFCApplication29Set, CRecordset)

CMFCApplication29Set::CMFCApplication29Set(CDatabase* pdb)
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
CString CMFCApplication29Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f;UID=sa;PWD=123456;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=DESKTOP-HKNCPI4;DATABASE=mfcdb");
}

CString CMFCApplication29Set::GetDefaultSQL()
{
	return _T("[dbo].[Table_3]");
}

void CMFCApplication29Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[ͼƬ�ļ���]"), column1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication29Set ���

#ifdef _DEBUG
void CMFCApplication29Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication29Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

