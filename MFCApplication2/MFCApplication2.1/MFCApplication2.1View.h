
// MFCApplication2.1View.h : CMFCApplication21View ��Ľӿ�
//

#pragma once


class CMFCApplication21View : public CView
{
protected: // �������л�����
	CMFCApplication21View();
	DECLARE_DYNCREATE(CMFCApplication21View)

// ����
public:
	CMFCApplication21Doc* GetDocument() const;

// ����
public:
	CRect cr;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	//CRect cr;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication2.1View.cpp �еĵ��԰汾
inline CMFCApplication21Doc* CMFCApplication21View::GetDocument() const
   { return reinterpret_cast<CMFCApplication21Doc*>(m_pDocument); }
#endif

