
// MFCApplication4.02Doc.h : CMFCApplication402Doc ��Ľӿ�
//


#pragma once


class CMFCApplication402Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication402Doc();
	DECLARE_DYNCREATE(CMFCApplication402Doc)

// ����
public:

// ����
public:
	CRect t;
	int red, green, blue;
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
	virtual ~CMFCApplication402Doc();
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
