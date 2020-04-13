
// MFCApplication12View.h: CMFCApplication12View 类的接口
//

#pragma once


class CMFCApplication12View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication12View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication12View)

// 特性
public:
	CMFCApplication12Doc* GetDocument() const;

// 操作
public:
	int mode = 0;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication12View();
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
	afx_msg void OnAdd();
};

#ifndef _DEBUG  // MFCApplication12View.cpp 中的调试版本
inline CMFCApplication12Doc* CMFCApplication12View::GetDocument() const
   { return reinterpret_cast<CMFCApplication12Doc*>(m_pDocument); }
#endif

