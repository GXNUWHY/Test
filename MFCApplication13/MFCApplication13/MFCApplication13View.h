
// MFCApplication13View.h: CMFCApplication13View 类的接口
//

#pragma once


class CMFCApplication13View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication13View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication13View)

// 特性
public:
	CMFCApplication13Doc* GetDocument() const;

// 操作
public:
	bool set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication13View.cpp 中的调试版本
inline CMFCApplication13Doc* CMFCApplication13View::GetDocument() const
   { return reinterpret_cast<CMFCApplication13Doc*>(m_pDocument); }
#endif

