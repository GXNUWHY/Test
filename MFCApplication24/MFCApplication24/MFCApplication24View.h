
// MFCApplication24View.h: CMFCApplication24View 类的接口
//

#pragma once


class CMFCApplication24View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication24View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication24View)

// 特性
public:
	CMFCApplication24Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	int num = 0;
	int mode = 0;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication24View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication24View.cpp 中的调试版本
inline CMFCApplication24Doc* CMFCApplication24View::GetDocument() const
   { return reinterpret_cast<CMFCApplication24Doc*>(m_pDocument); }
#endif

