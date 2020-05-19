#pragma once


// AddDlg 对话框

class AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddDlg)

public:
	AddDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long i;
};
