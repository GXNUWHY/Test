
// MFCApplication15View.h: CMFCApplication15View 类的接口
//

#pragma once


class CMFCApplication15View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication15View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication15View)

// 特性
public:
	CMFCApplication15Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	void Poly();
	void boundaryfill4(int seedx, int seedy, int fcolor, int bcolor, CDC * pDC);
	void Bresenhamcircle(int xc, int yc, int radius, int c);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication15View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication15View.cpp 中的调试版本
inline CMFCApplication15Doc* CMFCApplication15View::GetDocument() const
   { return reinterpret_cast<CMFCApplication15Doc*>(m_pDocument); }
#endif

