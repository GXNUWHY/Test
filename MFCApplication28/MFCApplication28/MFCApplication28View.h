
// MFCApplication28View.h : CMFCApplication28View ��Ľӿ�
//

#pragma once

class CMFCApplication28Set;

class CMFCApplication28View : public CRecordView
{
protected: // �������л�����
	CMFCApplication28View();
	DECLARE_DYNCREATE(CMFCApplication28View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION28_FORM };
#endif
	CMFCApplication28Set* m_pSet;

// ����
public:
	CMFCApplication28Doc* GetDocument() const;

// ����
public:
	void draw_pic(CString file);
	CString path = _T("E:\\pic2");
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFCApplication28View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString picname;
	afx_msg void OnRecordNext();
};

#ifndef _DEBUG  // MFCApplication28View.cpp �еĵ��԰汾
inline CMFCApplication28Doc* CMFCApplication28View::GetDocument() const
   { return reinterpret_cast<CMFCApplication28Doc*>(m_pDocument); }
#endif

