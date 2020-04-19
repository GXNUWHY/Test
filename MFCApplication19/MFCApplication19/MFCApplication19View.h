
// MFCApplication19View.h: CMFCApplication19View 类的接口
//

#pragma once
typedef struct{	float x;	float y;}PNT;//法向量

class CMFCApplication19View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication19View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication19View)

// 特性
public:
	CMFCApplication19Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	void PolyVector(int & k, POINT * ply, PNT * nv);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication19View();
#ifdef _DEBUG
	int Cyrus_Beck(int k, POINT ply[], PNT nv[], POINT p1, POINT p2, float & t1, float & t2);
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication19View.cpp 中的调试版本
inline CMFCApplication19Doc* CMFCApplication19View::GetDocument() const
   { return reinterpret_cast<CMFCApplication19Doc*>(m_pDocument); }
#endif

