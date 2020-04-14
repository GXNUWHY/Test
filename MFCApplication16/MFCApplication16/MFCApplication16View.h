
// MFCApplication16View.h: CMFCApplication16View 类的接口
//

#pragma once


class CMFCApplication16View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication16View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication16View)

// 特性
public:
	CMFCApplication16Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication16View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnShowFilename();
};

#ifndef _DEBUG  // MFCApplication16View.cpp 中的调试版本
inline CMFCApplication16Doc* CMFCApplication16View::GetDocument() const
   { return reinterpret_cast<CMFCApplication16Doc*>(m_pDocument); }
#endif

