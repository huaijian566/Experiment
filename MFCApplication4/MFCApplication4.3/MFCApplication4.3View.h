
// MFCApplication4.3View.h : CMFCApplication43View ��Ľӿ�
//

#pragma once


class CMFCApplication43View : public CView
{
protected: // �������л�����
	CMFCApplication43View();
	DECLARE_DYNCREATE(CMFCApplication43View)

// ����
public:
	CMFCApplication43Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHuaxian();
	afx_msg void OnHuajuxing();
	afx_msg void OnHuatuoyuan();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication4.3View.cpp �еĵ��԰汾
inline CMFCApplication43Doc* CMFCApplication43View::GetDocument() const
   { return reinterpret_cast<CMFCApplication43Doc*>(m_pDocument); }
#endif

