
// MFCApplication23Dlg.h: 头文件
//

#pragma once


// CMFCApplication23Dlg 对话框
class CMFCApplication23Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication23Dlg(CWnd* pParent = nullptr);	// 标准构造函数
	~CMFCApplication23Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION23_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox names;
	CString name;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
