
// MFCexperiment1.2View.cpp : CMFCexperiment12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCexperiment1.2.h"
#endif

#include "MFCexperiment1.2Doc.h"
#include "MFCexperiment1.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCexperiment12View

IMPLEMENT_DYNCREATE(CMFCexperiment12View, CView)

BEGIN_MESSAGE_MAP(CMFCexperiment12View, CView)
END_MESSAGE_MAP()

// CMFCexperiment12View ����/����

CMFCexperiment12View::CMFCexperiment12View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCexperiment12View::~CMFCexperiment12View()
{
}

BOOL CMFCexperiment12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCexperiment12View ����

void CMFCexperiment12View::OnDraw(CDC* pDC)
{
	CMFCexperiment12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->TextOutW(200, 200, pDoc->s);
	int b = pDoc->a;
	CString c;
	c.Format(_T("%d"), b);
	pDC->TextOutW(300, 200, c);

}


// CMFCexperiment12View ���

#ifdef _DEBUG
void CMFCexperiment12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexperiment12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexperiment12Doc* CMFCexperiment12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexperiment12Doc)));
	return (CMFCexperiment12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCexperiment12View ��Ϣ�������
