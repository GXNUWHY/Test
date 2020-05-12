
// MFCApplication27View.h : CMFCApplication27View 类的接口
//

#pragma once

class CMFCApplication27Set;

class CMFCApplication27View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication27View();
	DECLARE_DYNCREATE(CMFCApplication27View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION27_FORM };
#endif
	CMFCApplication27Set* m_pSet;

// 特性
public:
	CMFCApplication27Doc* GetDocument() const;

// 操作
public:
	CRect picRect;

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCApplication27View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString number;
	CString name;
	CString age;
	CString picpath;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
};

#ifndef _DEBUG  // MFCApplication27View.cpp 中的调试版本
inline CMFCApplication27Doc* CMFCApplication27View::GetDocument() const
   { return reinterpret_cast<CMFCApplication27Doc*>(m_pDocument); }
#endif

