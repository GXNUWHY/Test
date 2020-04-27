
// MFCApplication21View.h: CMFCApplication21View 类的接口
//

#pragma once


class CMFCApplication21View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication21View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication21View)

// 特性
public:
	CMFCApplication21Doc* GetDocument() const;

// 操作
public:
	CString filepath;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFCApplication21View.cpp 中的调试版本
inline CMFCApplication21Doc* CMFCApplication21View::GetDocument() const
   { return reinterpret_cast<CMFCApplication21Doc*>(m_pDocument); }
#endif

