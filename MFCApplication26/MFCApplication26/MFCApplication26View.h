
// MFCApplication26View.h : CMFCApplication26View 类的接口
//

#pragma once

class CMFCApplication26Set;

class CMFCApplication26View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication26View();
	DECLARE_DYNCREATE(CMFCApplication26View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION26_FORM };
#endif
	CMFCApplication26Set* m_pSet;

// 特性
public:
	CMFCApplication26Doc* GetDocument() const;

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
	virtual ~CMFCApplication26View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString age;
	CString phone;
};

#ifndef _DEBUG  // MFCApplication26View.cpp 中的调试版本
inline CMFCApplication26Doc* CMFCApplication26View::GetDocument() const
   { return reinterpret_cast<CMFCApplication26Doc*>(m_pDocument); }
#endif

