
// MFCApplication6.2Doc.h : CMFCApplication62Doc ��Ľӿ�
//


#pragma once


class CMFCApplication62Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication62Doc();
	DECLARE_DYNCREATE(CMFCApplication62Doc)

// ����
public:

// ����
public:
	CString s, L;
	CPoint p,q;
	bool a;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCApplication62Doc();
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
