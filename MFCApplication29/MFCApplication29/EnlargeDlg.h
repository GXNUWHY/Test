#pragma once


// EnlargeDlg �Ի���

class EnlargeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EnlargeDlg)

public:
	EnlargeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EnlargeDlg();

	CString filepath;
	CRect picRect;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	void draw_pic(CString file);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
