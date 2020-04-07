
// MFCApplication9View.h: CMFCApplication9View 类的接口
//

#pragma once


class CMFCApplication9View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication9View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication9View)

// 特性
public:
	CMFCApplication9Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFCApplication9View.cpp 中的调试版本
inline CMFCApplication9Doc* CMFCApplication9View::GetDocument() const
   { return reinterpret_cast<CMFCApplication9Doc*>(m_pDocument); }
#endif

