
// MFCApplication30Dlg.h : ͷ�ļ�
//

#pragma once


// CMFCApplication30Dlg �Ի���
class CMFCApplication30Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication30Dlg(CWnd* pParent = NULL);	// ��׼���캯��

	CString path;
	CString file;
	CString filepath;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION30_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
