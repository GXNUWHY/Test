
// MFCApplication29View.h : CMFCApplication29View ��Ľӿ�
//

#pragma once

class CMFCApplication29Set;

class CMFCApplication29View : public CRecordView
{
protected: // �������л�����
	CMFCApplication29View();
	DECLARE_DYNCREATE(CMFCApplication29View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION29_FORM };
#endif
	CMFCApplication29Set* m_pSet;

// ����
public:
	CMFCApplication29Doc* GetDocument() const;

// ����
public:
	CString path = _T("E:\\pic2\\");
	CRect picRect;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	void draw_pic(CString file);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFCApplication29View();
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
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	afx_msg void OnEnlarge();
};

#ifndef _DEBUG  // MFCApplication29View.cpp �еĵ��԰汾
inline CMFCApplication29Doc* CMFCApplication29View::GetDocument() const
   { return reinterpret_cast<CMFCApplication29Doc*>(m_pDocument); }
#endif

