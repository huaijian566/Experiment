
// MFCexperiment1View.h : CMFCexperiment1View ��Ľӿ�
//

#pragma once


class CMFCexperiment1View : public CView
{
protected: // �������л�����
	CMFCexperiment1View();
	DECLARE_DYNCREATE(CMFCexperiment1View)

// ����
public:
	CMFCexperiment1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCexperiment1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCexperiment1View.cpp �еĵ��԰汾
inline CMFCexperiment1Doc* CMFCexperiment1View::GetDocument() const
   { return reinterpret_cast<CMFCexperiment1Doc*>(m_pDocument); }
#endif

