
// MFCApplication4.01View.h : CMFCApplication401View ��Ľӿ�
//

#pragma once


class CMFCApplication401View : public CView
{
protected: // �������л�����
	CMFCApplication401View();
	DECLARE_DYNCREATE(CMFCApplication401View)

// ����
public:
	CMFCApplication401Doc* GetDocument() const;

// ����
public:
	bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication401View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHuayuan();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCApplication4.01View.cpp �еĵ��԰汾
inline CMFCApplication401Doc* CMFCApplication401View::GetDocument() const
   { return reinterpret_cast<CMFCApplication401Doc*>(m_pDocument); }
#endif

