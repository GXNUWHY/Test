
// MFCApplication31View.h : CMFCApplication31View 类的接口
//

#pragma once

class CMFCApplication31Set;

class CMFCApplication31View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication31View();
	DECLARE_DYNCREATE(CMFCApplication31View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION31_FORM };
#endif
	CMFCApplication31Set* m_pSet;

// 特性
public:
	CMFCApplication31Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCApplication31View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long num;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // MFCApplication31View.cpp 中的调试版本
inline CMFCApplication31Doc* CMFCApplication31View::GetDocument() const
   { return reinterpret_cast<CMFCApplication31Doc*>(m_pDocument); }
#endif

