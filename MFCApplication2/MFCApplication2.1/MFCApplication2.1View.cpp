
// MFCApplication2.1View.cpp : CMFCApplication21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication2.1.h"
#endif

#include "MFCApplication2.1Doc.h"
#include "MFCApplication2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication21View

IMPLEMENT_DYNCREATE(CMFCApplication21View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication21View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication21View ����/����

CMFCApplication21View::CMFCApplication21View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication21View::~CMFCApplication21View()
{
}

BOOL CMFCApplication21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication21View ����

void CMFCApplication21View::OnDraw(CDC* pDC)
{
	CMFCApplication21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
   pDC->Ellipse(cr.right / 2 - cr.bottom / 2, 0, cr.right / 2 + cr.bottom / 2, cr.bottom);
}


// CMFCApplication21View ���

#ifdef _DEBUG
void CMFCApplication21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication21Doc* CMFCApplication21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication21Doc)));
	return (CMFCApplication21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication21View ��Ϣ�������


void CMFCApplication21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CRect cr;
	this->GetClientRect(&(cr));
	this->Invalidate();
	//CClientDC dc(this);
	//dc.Ellipse(cr.right / 2 - cr.bottom / 2, 0, cr.right / 2 + cr.bottom / 2, cr.bottom);
	CView::OnLButtonDown(nFlags, point);
}
