
// MFCApplication4.1View.h : CMFCApplication41View ��Ľӿ�
//

#pragma once


class CMFCApplication41View : public CView
{
protected: // �������л�����
	CMFCApplication41View();
	DECLARE_DYNCREATE(CMFCApplication41View)

// ����
public:
	CMFCApplication41Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFCApplication4.1View.cpp �еĵ��԰汾
inline CMFCApplication41Doc* CMFCApplication41View::GetDocument() const
   { return reinterpret_cast<CMFCApplication41Doc*>(m_pDocument); }
#endif

