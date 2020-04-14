#pragma once


// DRAW 对话框

class DRAW : public CDialogEx
{
	DECLARE_DYNAMIC(DRAW)

public:
	DRAW(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DRAW();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
};
