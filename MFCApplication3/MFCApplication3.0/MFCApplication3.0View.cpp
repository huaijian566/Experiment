
// MFCApplication3.0View.cpp : CMFCApplication30View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication3.0.h"
#endif

#include "MFCApplication3.0Doc.h"
#include "MFCApplication3.0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication30View

IMPLEMENT_DYNCREATE(CMFCApplication30View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication30View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication30View ����/����

CMFCApplication30View::CMFCApplication30View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication30View::~CMFCApplication30View()
{
}

BOOL CMFCApplication30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication30View ����

void CMFCApplication30View::OnDraw(CDC* pDC)
{
	CMFCApplication30Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->cr);
}


// CMFCApplication30View ���

#ifdef _DEBUG
void CMFCApplication30View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication30View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication30Doc* CMFCApplication30View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication30Doc)));
	return (CMFCApplication30Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication30View ��Ϣ�������


void CMFCApplication30View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication30Doc* pDoc = GetDocument();
	SetCapture();
	pDoc->cr.left = point.x;
	pDoc->cr.top = point.y;
	//InvalidateRect(NULL, true);
	CString str;
	str.Format(_T("���������µ����꣺��%d,%d��"), point.x, point.y);
	CClientDC dc(this);
	dc.TextOutW(point.x, point.y, str);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication30View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication30Doc* pDoc = GetDocument();
	ReleaseCapture();
	pDoc->cr.right = point.x;
	pDoc->cr.bottom = point.y;
	InvalidateRect(NULL, true);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication30View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	CClientDC dc(this);
	//int a = point.x;
	str.Format(_T("��ǰ�������꣺��%d,%d��"), point.x,point.y);
	dc.TextOutW(20, 20, str);
	CView::OnMouseMove(nFlags, point);
}
