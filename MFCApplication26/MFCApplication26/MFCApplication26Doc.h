
// MFCApplication26Doc.h : CMFCApplication26Doc ��Ľӿ�
//


#pragma once
#include "MFCApplication26Set.h"


class CMFCApplication26Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication26Doc();
	DECLARE_DYNCREATE(CMFCApplication26Doc)

// ����
public:
	CMFCApplication26Set m_MFCApplication26Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCApplication26Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
