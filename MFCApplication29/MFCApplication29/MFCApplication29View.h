
// MFCApplication29View.h : CMFCApplication29View 类的接口
//

#pragma once

class CMFCApplication29Set;

class CMFCApplication29View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication29View();
	DECLARE_DYNCREATE(CMFCApplication29View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION29_FORM };
#endif
	CMFCApplication29Set* m_pSet;

// 特性
public:
	CMFCApplication29Doc* GetDocument() const;

// 操作
public:
	CString path = _T("E:\\pic2\\");
	CRect picRect;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	void draw_pic(CString file);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCApplication29View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFCApplication29View.cpp 中的调试版本
inline CMFCApplication29Doc* CMFCApplication29View::GetDocument() const
   { return reinterpret_cast<CMFCApplication29Doc*>(m_pDocument); }
#endif

