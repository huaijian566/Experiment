
// MFCexperiment1View.cpp : CMFCexperiment1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCexperiment1.h"
#endif

#include "MFCexperiment1Doc.h"
#include "MFCexperiment1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCexperiment1View

IMPLEMENT_DYNCREATE(CMFCexperiment1View, CView)

BEGIN_MESSAGE_MAP(CMFCexperiment1View, CView)
END_MESSAGE_MAP()

// CMFCexperiment1View ����/����

CMFCexperiment1View::CMFCexperiment1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCexperiment1View::~CMFCexperiment1View()
{
}

BOOL CMFCexperiment1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCexperiment1View ����

void CMFCexperiment1View::OnDraw(CDC* pDC)
{
	CMFCexperiment1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s = _T("��������");
	CString c;
	int a = 666;
	c.Format(_T("%d"), a);
	pDC->TextOutW(200, 200, s);
	pDC->TextOutW(300, 200, c);

}


// CMFCexperiment1View ���

#ifdef _DEBUG
void CMFCexperiment1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexperiment1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexperiment1Doc* CMFCexperiment1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexperiment1Doc)));
	return (CMFCexperiment1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCexperiment1View ��Ϣ�������
