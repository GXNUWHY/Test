
// MFCApplication28View.h : CMFCApplication28View 类的接口
//

#pragma once

class CMFCApplication28Set;

class CMFCApplication28View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication28View();
	DECLARE_DYNCREATE(CMFCApplication28View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION28_FORM };
#endif
	CMFCApplication28Set* m_pSet;

// 特性
public:
	CMFCApplication28Doc* GetDocument() const;

// 操作
public:
	void draw_pic(CString file);
	CString path = _T("E:\\pic2");
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCApplication28View();
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
	afx_msg void OnRecordNext();
};

#ifndef _DEBUG  // MFCApplication28View.cpp 中的调试版本
inline CMFCApplication28Doc* CMFCApplication28View::GetDocument() const
   { return reinterpret_cast<CMFCApplication28Doc*>(m_pDocument); }
#endif

