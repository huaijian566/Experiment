
// DB11Doc.h : CDB11Doc ��Ľӿ�
//


#pragma once
#include "DB11Set.h"


class CDB11Doc : public CDocument
{
protected: // �������л�����
	CDB11Doc();
	DECLARE_DYNCREATE(CDB11Doc)

// ����
public:
	CDB11Set m_DB11Set;

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
	virtual ~CDB11Doc();
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
