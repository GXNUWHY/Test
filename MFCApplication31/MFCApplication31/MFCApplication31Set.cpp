
// MFCApplication31Set.cpp : CMFCApplication31Set 类的实现
//

#include "stdafx.h"
#include "MFCApplication31.h"
#include "MFCApplication31Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication31Set 实现

// 代码生成在 2020年5月19日, 19:51

IMPLEMENT_DYNAMIC(CMFCApplication31Set, CRecordset)

CMFCApplication31Set::CMFCApplication31Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_num = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
// #error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFCApplication31Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f;UID=sa;PWD=123456;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=DESKTOP-HKNCPI4;DATABASE=mfcdb");
}

CString CMFCApplication31Set::GetDefaultSQL()
{
	return _T("[dbo].[Table_4]");
}

void CMFCApplication31Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[num]"), m_num);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication31Set 诊断

#ifdef _DEBUG
void CMFCApplication31Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication31Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

