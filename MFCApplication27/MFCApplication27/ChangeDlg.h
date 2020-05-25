#pragma once


// ChangeDlg 对话框

class ChangeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChangeDlg)

public:
	ChangeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ChangeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString number;
	CString name;
	CString age;
	CString picpath;
};
