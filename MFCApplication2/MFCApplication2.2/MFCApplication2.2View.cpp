
// MFCApplication2.2View.cpp : CMFCApplication22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication2.2.h"
#endif

#include "MFCApplication2.2Doc.h"
#include "MFCApplication2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication22View

IMPLEMENT_DYNCREATE(CMFCApplication22View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication22View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication22View ����/����

CMFCApplication22View::CMFCApplication22View()
{
	// TODO: �ڴ˴���ӹ������
	//ca.SetSize(100);
}

CMFCApplication22View::~CMFCApplication22View()
{
}

BOOL CMFCApplication22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication22View ����

void CMFCApplication22View::OnDraw(CDC* pDC)
{
	CMFCApplication22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));

}


// CMFCApplication22View ���

#ifdef _DEBUG
void CMFCApplication22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication22Doc* CMFCApplication22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication22Doc)));
	return (CMFCApplication22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication22View ��Ϣ�������


void CMFCApplication22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication22Doc* pDoc = GetDocument();
	int r = rand() % 50 + 5;
	int r2 = rand() % 30 + 3;
	CRect cr(point.x - r, point.y - r2, point.x + r, point.y + r2);
	pDoc->ca.Add(cr);
	this->Invalidate();
	//CClientDC dc(this);
	//dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
