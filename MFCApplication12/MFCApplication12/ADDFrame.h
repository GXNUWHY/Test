#pragma once


// ADDFrame 对话框

class ADDFrame : public CDialogEx
{
	DECLARE_DYNAMIC(ADDFrame)

public:
	ADDFrame(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ADDFrame();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int a;
	int b;
	int c;
	afx_msg void OnBnClickedButton1();
};
