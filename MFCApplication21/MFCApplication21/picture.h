#pragma once


// picture 对话框

class picture : public CDialogEx
{
	DECLARE_DYNAMIC(picture)

public:
	picture(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~picture();
	CString path;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
