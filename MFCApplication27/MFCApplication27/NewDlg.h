#pragma once


// NewDlg 对话框

class NewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NewDlg)

public:
	NewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~NewDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString number;
	CString name;
	CString age;
	CString picapth;
};
