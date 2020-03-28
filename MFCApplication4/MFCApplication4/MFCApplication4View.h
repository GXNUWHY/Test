
// MFCApplication4View.h: CMFCApplication4View 类的接口
//

#pragma once


class CMFCApplication4View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication4View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication4View)

// 特性
public:
	CMFCApplication4Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDdaline();
	afx_msg void OnMidpointline();
	afx_msg void OnBresenhamline();
};

#ifndef _DEBUG  // MFCApplication4View.cpp 中的调试版本
inline CMFCApplication4Doc* CMFCApplication4View::GetDocument() const
   { return reinterpret_cast<CMFCApplication4Doc*>(m_pDocument); }
#endif

