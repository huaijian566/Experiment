
// MFCApplication4.3Doc.h : CMFCApplication43Doc ��Ľӿ�
//


#pragma once


class CMFCApplication43Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication43Doc();
	DECLARE_DYNCREATE(CMFCApplication43Doc)

// ����
public:

// ����
public:
	CPoint p1, p2;
	bool a,b,c;
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
	virtual ~CMFCApplication43Doc();
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
