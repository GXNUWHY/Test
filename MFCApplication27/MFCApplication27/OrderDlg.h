#pragma once


// OrderDlg 对话框

class OrderDlg : public CDialogEx
{
	DECLARE_DYNAMIC(OrderDlg)

public:
	OrderDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OrderDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString order;
};
