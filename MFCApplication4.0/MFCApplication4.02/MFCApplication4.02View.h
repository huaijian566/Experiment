
// MFCApplication4.02View.h : CMFCApplication402View ��Ľӿ�
//

#pragma once


class CMFCApplication402View : public CView
{
protected: // �������л�����
	CMFCApplication402View();
	DECLARE_DYNCREATE(CMFCApplication402View)

// ����
public:
	CMFCApplication402Doc* GetDocument() const;

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
	virtual ~CMFCApplication402View();
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

#ifndef _DEBUG  // MFCApplication4.02View.cpp �еĵ��԰汾
inline CMFCApplication402Doc* CMFCApplication402View::GetDocument() const
   { return reinterpret_cast<CMFCApplication402Doc*>(m_pDocument); }
#endif

