
// MFCApplication4.2View.cpp : CMFCApplication42View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication4.2.h"
#endif

#include "MFCApplication4.2Doc.h"
#include "MFCApplication4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication42View

IMPLEMENT_DYNCREATE(CMFCApplication42View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication42View, CView)
END_MESSAGE_MAP()

// CMFCApplication42View ����/����

CMFCApplication42View::CMFCApplication42View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP bm;
	b.LoadBitmapW(IDB_BITMAP1);
	b.GetBitmap(&bm);
	w = bm.bmWidth;
	h = bm.bmHeight;
}

CMFCApplication42View::~CMFCApplication42View()
{
}

BOOL CMFCApplication42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication42View ����

void CMFCApplication42View::OnDraw(CDC* pDC)
{
	CMFCApplication42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC M;
	M.CreateCompatibleDC(NULL);
	M.SelectObject(b);
	pDC->BitBlt(0, 0, w, h, &M, 0, 0, SRCCOPY);

}


// CMFCApplication42View ���

#ifdef _DEBUG
void CMFCApplication42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication42Doc* CMFCApplication42View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication42Doc)));
	return (CMFCApplication42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication42View ��Ϣ�������
