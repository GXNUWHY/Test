
// MFCApplication26View.h : CMFCApplication26View ��Ľӿ�
//

#pragma once

class CMFCApplication26Set;

class CMFCApplication26View : public CRecordView
{
protected: // �������л�����
	CMFCApplication26View();
	DECLARE_DYNCREATE(CMFCApplication26View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION26_FORM };
#endif
	CMFCApplication26Set* m_pSet;

// ����
public:
	CMFCApplication26Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFCApplication26View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString age;
	CString phone;
};

#ifndef _DEBUG  // MFCApplication26View.cpp �еĵ��԰汾
inline CMFCApplication26Doc* CMFCApplication26View::GetDocument() const
   { return reinterpret_cast<CMFCApplication26Doc*>(m_pDocument); }
#endif

