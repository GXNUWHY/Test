#pragma once


// SHOWDIA 对话框

class SHOWDIA : public CDialogEx
{
	DECLARE_DYNAMIC(SHOWDIA)

public:
	SHOWDIA(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SHOWDIA();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	

	DECLARE_MESSAGE_MAP()
public:
	CString filename;
	
	CListBox filename2;
	virtual BOOL OnInitDialog();
};
