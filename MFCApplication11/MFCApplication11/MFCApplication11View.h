
// MFCApplication11View.h: CMFCApplication11View 类的接口
//

#pragma once
typedef struct tEdge
{
	int num, ymin, ymax;
	float xmin, xmax, dx;
}Edge;



class CMFCApplication11View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication11View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication11View)

// 特性
public:
	CMFCApplication11Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication11View();
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
	void ScanFill(CPoint spt[], CDC * pDC);
	afx_msg void On32772();
	void SeedFill(CPoint spt[], CPoint s_point, CDC * pDC);
};

#ifndef _DEBUG  // MFCApplication11View.cpp 中的调试版本
inline CMFCApplication11Doc* CMFCApplication11View::GetDocument() const
   { return reinterpret_cast<CMFCApplication11Doc*>(m_pDocument); }
#endif

