
// MFCApplication6.2View.h : CMFCApplication62View ��Ľӿ�
//

#pragma once


class CMFCApplication62View : public CView
{
protected: // �������л�����
	CMFCApplication62View();
	DECLARE_DYNCREATE(CMFCApplication62View)

// ����
public:
	CMFCApplication62Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication62View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication6.2View.cpp �еĵ��԰汾
inline CMFCApplication62Doc* CMFCApplication62View::GetDocument() const
   { return reinterpret_cast<CMFCApplication62Doc*>(m_pDocument); }
#endif

