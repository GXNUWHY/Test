#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// RecordSet �Ի���

class RecordSet : public CDialogEx
{
	DECLARE_DYNAMIC(RecordSet)

public:
	RecordSet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RecordSet();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox recordfield;
	CArray<CString, CString&> recordarray;
	int fieldnum;
};
