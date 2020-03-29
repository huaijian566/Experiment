
// MFCApplication2.5View.cpp : CMFCApplication25View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication2.5.h"
#endif

#include "MFCApplication2.5Doc.h"
#include "MFCApplication2.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication25View

IMPLEMENT_DYNCREATE(CMFCApplication25View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication25View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication25View ����/����

CMFCApplication25View::CMFCApplication25View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication25View::~CMFCApplication25View()
{
}

BOOL CMFCApplication25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication25View ����

void CMFCApplication25View::OnDraw(CDC* pDC)
{
	CMFCApplication25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);
}


// CMFCApplication25View ���

#ifdef _DEBUG
void CMFCApplication25View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication25Doc* CMFCApplication25View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication25Doc)));
	return (CMFCApplication25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication25View ��Ϣ�������


void CMFCApplication25View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication25Doc* pDoc = GetDocument();
	CClientDC dc(this);
	
	if(pDoc->A.left<point.x&&point.x<pDoc->A.right&&pDoc->A.top<point.y&&point.y<pDoc->A.bottom)
	{
		int a2 = pDoc->a;
		CString s;
		s.Format(_T("%d"), a2);
		dc.TextOutW(250, 250, s);
	}
	else if (pDoc->B.left<point.x&&point.x<pDoc->B.right&&pDoc->B.top<point.y&&point.y<pDoc->B.bottom)
	{
		int b2 = pDoc->b;
		CString c;
		c.Format(_T("%d"), b2);
		dc.TextOutW(400, 250, c);
	}
	else
	{
		CString n = _T("�����Ч");
		dc.TextOutW(200, 400, n);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication25View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication25Doc* pDoc = GetDocument();
	CClientDC dc(this);

	if (pDoc->C.left<point.x&&point.x<pDoc->C.right&&pDoc->C.top<point.y&&point.y<pDoc->C.bottom)
	{
		int c = pDoc->a+pDoc->b;
		CString s;
		s.Format(_T("%d"), c);
		dc.TextOutW(550, 250, s);
	}
	CView::OnRButtonDown(nFlags, point);
}
