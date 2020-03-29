
// MFCexperiment1.3View.cpp : CMFCexperiment13View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCexperiment1.3.h"
#endif

#include "MFCexperiment1.3Doc.h"
#include "MFCexperiment1.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCexperiment13View

IMPLEMENT_DYNCREATE(CMFCexperiment13View, CView)

BEGIN_MESSAGE_MAP(CMFCexperiment13View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCexperiment13View ����/����

CMFCexperiment13View::CMFCexperiment13View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCexperiment13View::~CMFCexperiment13View()
{
}

BOOL CMFCexperiment13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCexperiment13View ����

void CMFCexperiment13View::OnDraw(CDC* /*pDC*/)
{
	CMFCexperiment13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCexperiment13View ���

#ifdef _DEBUG
void CMFCexperiment13View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexperiment13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexperiment13Doc* CMFCexperiment13View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexperiment13Doc)));
	return (CMFCexperiment13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCexperiment13View ��Ϣ�������


void CMFCexperiment13View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCexperiment13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	 pDoc->count++;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFCexperiment13View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCexperiment13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int c = pDoc->count;
	CString s;
	s.Format(_T("%d"),c );
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
