#pragma once


// OrderDlg �Ի���

class OrderDlg : public CDialogEx
{
	DECLARE_DYNAMIC(OrderDlg)

public:
	OrderDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~OrderDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString order;
};
