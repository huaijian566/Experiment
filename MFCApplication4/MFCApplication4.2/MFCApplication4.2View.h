
// MFCApplication4.2View.h : CMFCApplication42View ��Ľӿ�
//

#pragma once


class CMFCApplication42View : public CView
{
protected: // �������л�����
	CMFCApplication42View();
	DECLARE_DYNCREATE(CMFCApplication42View)

// ����
public:
	CMFCApplication42Doc* GetDocument() const;

// ����
public:
	CBitmap b;
	int w,h;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication42View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication4.2View.cpp �еĵ��԰汾
inline CMFCApplication42Doc* CMFCApplication42View::GetDocument() const
   { return reinterpret_cast<CMFCApplication42Doc*>(m_pDocument); }
#endif

