#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// RecordSet 对话框

class RecordSet : public CDialogEx
{
	DECLARE_DYNAMIC(RecordSet)

public:
	RecordSet(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RecordSet();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox recordfield;
	CArray<CString, CString&> recordarray;
	int fieldnum;
};
