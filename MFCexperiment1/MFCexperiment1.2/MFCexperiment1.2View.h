
// MFCexperiment1.2View.h : CMFCexperiment12View ��Ľӿ�
//

#pragma once


class CMFCexperiment12View : public CView
{
protected: // �������л�����
	CMFCexperiment12View();
	DECLARE_DYNCREATE(CMFCexperiment12View)

// ����
public:
	CMFCexperiment12Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCexperiment12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCexperiment1.2View.cpp �еĵ��԰汾
inline CMFCexperiment12Doc* CMFCexperiment12View::GetDocument() const
   { return reinterpret_cast<CMFCexperiment12Doc*>(m_pDocument); }
#endif

