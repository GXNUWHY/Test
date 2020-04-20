
// MFCApplication20View.h: CMFCApplication20View 类的接口
//

#pragma once


class CMFCApplication20View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication20View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication20View)

// 特性
public:
	CMFCApplication20Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication20View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void On32772();
};

#ifndef _DEBUG  // MFCApplication20View.cpp 中的调试版本
inline CMFCApplication20Doc* CMFCApplication20View::GetDocument() const
   { return reinterpret_cast<CMFCApplication20Doc*>(m_pDocument); }
#endif

