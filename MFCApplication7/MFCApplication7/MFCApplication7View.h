
// MFCApplication7View.h: CMFCApplication7View 类的接口
//

#pragma once


class CMFCApplication7View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication7View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication7View)

// 特性
public:
	CMFCApplication7Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication7View();
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
};

#ifndef _DEBUG  // MFCApplication7View.cpp 中的调试版本
inline CMFCApplication7Doc* CMFCApplication7View::GetDocument() const
   { return reinterpret_cast<CMFCApplication7Doc*>(m_pDocument); }
#endif

