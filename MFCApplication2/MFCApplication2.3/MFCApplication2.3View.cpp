
// MFCApplication2.3View.cpp : CMFCApplication23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication2.3.h"
#endif

#include "MFCApplication2.3Doc.h"
#include "MFCApplication2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication23View

IMPLEMENT_DYNCREATE(CMFCApplication23View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication23View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication23View ����/����

CMFCApplication23View::CMFCApplication23View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication23View::~CMFCApplication23View()
{
}

BOOL CMFCApplication23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication23View ����

void CMFCApplication23View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCApplication23View ���

#ifdef _DEBUG
void CMFCApplication23View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication23Doc* CMFCApplication23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication23Doc)));
	return (CMFCApplication23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication23View ��Ϣ�������


void CMFCApplication23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s = _T("�����������");
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication23View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s = _T("�������̧��");
	dc.TextOutW(200, 200, s);
	CView::OnLButtonUp(nFlags, point);
}
