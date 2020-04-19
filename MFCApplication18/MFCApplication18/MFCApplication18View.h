
// MFCApplication18View.h: CMFCApplication18View 类的接口
//

#pragma once


class CMFCApplication18View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication18View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication18View)

// 特性
public:
	CMFCApplication18Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	void PolygonClip(CPoint * ptset1, int M0, CDC * pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication18View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication18View.cpp 中的调试版本
inline CMFCApplication18Doc* CMFCApplication18View::GetDocument() const
   { return reinterpret_cast<CMFCApplication18Doc*>(m_pDocument); }
#endif

