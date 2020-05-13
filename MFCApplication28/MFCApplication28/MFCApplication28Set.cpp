
// MFCApplication28Set.cpp : CMFCApplication28Set 类的实现
//

#include "stdafx.h"
#include "MFCApplication28.h"
#include "MFCApplication28Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication28Set 实现

// 代码生成在 2020年5月13日, 14:46

IMPLEMENT_DYNAMIC(CMFCApplication28Set, CRecordset)

CMFCApplication28Set::CMFCApplication28Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}
// #error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[图片文件名]"), column1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication28Set 诊断

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

