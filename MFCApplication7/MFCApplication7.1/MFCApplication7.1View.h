
// MFCApplication7.1View.h : CMFCApplication71View ��Ľӿ�
//

#pragma once


class CMFCApplication71View : public CView
{
protected: // �������л�����
	CMFCApplication71View();
	DECLARE_DYNCREATE(CMFCApplication71View)

// ����
public:
	CMFCApplication71Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication71View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowdialog();
};

#ifndef _DEBUG  // MFCApplication7.1View.cpp �еĵ��԰汾
inline CMFCApplication71Doc* CMFCApplication71View::GetDocument() const
   { return reinterpret_cast<CMFCApplication71Doc*>(m_pDocument); }
#endif

