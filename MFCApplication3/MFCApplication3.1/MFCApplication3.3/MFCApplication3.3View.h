
// MFCApplication3.3View.h : CMFCApplication33View ��Ľӿ�
//

#pragma once


class CMFCApplication33View : public CView
{
protected: // �������л�����
	CMFCApplication33View();
	DECLARE_DYNCREATE(CMFCApplication33View)

// ����
public:
	CMFCApplication33Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication33View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication3.3View.cpp �еĵ��԰汾
inline CMFCApplication33Doc* CMFCApplication33View::GetDocument() const
   { return reinterpret_cast<CMFCApplication33Doc*>(m_pDocument); }
#endif

