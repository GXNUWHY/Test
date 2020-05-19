#pragma once


// EnlargeDlg 对话框

class EnlargeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EnlargeDlg)

public:
	EnlargeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EnlargeDlg();

	CString filepath;
	CRect picRect;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	void draw_pic(CString file);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
