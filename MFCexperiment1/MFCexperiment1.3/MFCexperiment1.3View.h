
// MFCexperiment1.3View.h : CMFCexperiment13View ��Ľӿ�
//

#pragma once


class CMFCexperiment13View : public CView
{
protected: // �������л�����
	CMFCexperiment13View();
	DECLARE_DYNCREATE(CMFCexperiment13View)

// ����
public:
	CMFCexperiment13Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCexperiment13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCexperiment1.3View.cpp �еĵ��԰汾
inline CMFCexperiment13Doc* CMFCexperiment13View::GetDocument() const
   { return reinterpret_cast<CMFCexperiment13Doc*>(m_pDocument); }
#endif

