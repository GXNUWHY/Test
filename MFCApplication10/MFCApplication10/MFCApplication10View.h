
// MFCApplication10View.h: CMFCApplication10View 类的接口
//

#pragma once

typedef struct tEdge     // 有序边表和活化边表的结构
{
	int ymax;
	float x, dx;
	struct tEdge *next;
}Edge;


class CMFCApplication10View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication10View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication10View)

// 特性
public:
	CMFCApplication10Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication10View();
#ifdef _DEBUG
	void InsertEdge(Edge * list, Edge * edge);
	int yNext(int k, int cnt, POINT * pts);
	void MakeEdgeRec(POINT lower, POINT upper, int yComp, Edge * edge, Edge * edges[]);
	void BuildEdgeList(int cnt, POINT * pts, Edge * edges[]);
	void BuildActiveList(int scan, Edge * active, Edge * edges[]);
	void FillScan(int scan, Edge * active, int color);
	void DeleteAfter(Edge * q);
	void UpdateActiveList(int scan, Edge * active);
	void ResortActiveList(Edge * active);
	void ScanFill(int cnt, POINT * pts, int color);
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On1();
	void ScanFill2(CPoint spt[], CDC * pDC);
};

#ifndef _DEBUG  // MFCApplication10View.cpp 中的调试版本
inline CMFCApplication10Doc* CMFCApplication10View::GetDocument() const
   { return reinterpret_cast<CMFCApplication10Doc*>(m_pDocument); }
#endif

