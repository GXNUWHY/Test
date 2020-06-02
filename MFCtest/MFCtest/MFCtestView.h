
// MFCtestView.h: CMFCtestView 类的接口
//

#pragma once


class CMFCtestView : public CView
{
protected: // 仅从序列化创建
	CMFCtestView() noexcept;
	DECLARE_DYNCREATE(CMFCtestView)

// 特性
public:
	CMFCtestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtestView.cpp 中的调试版本
inline CMFCtestDoc* CMFCtestView::GetDocument() const
   { return reinterpret_cast<CMFCtestDoc*>(m_pDocument); }
#endif

