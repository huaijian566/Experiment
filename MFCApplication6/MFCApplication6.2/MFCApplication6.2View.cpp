
// MFCApplication6.2View.cpp : CMFCApplication62View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication6.2.h"
#endif

#include "MFCApplication6.2Doc.h"
#include "MFCApplication6.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication62View

IMPLEMENT_DYNCREATE(CMFCApplication62View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication62View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication62View ����/����

CMFCApplication62View::CMFCApplication62View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication62View::~CMFCApplication62View()
{
}

BOOL CMFCApplication62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication62View ����

void CMFCApplication62View::OnDraw(CDC* pDC)
{
	CMFCApplication62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cr(100,100,800,130);
	pDC->Rectangle(cr);
	pDC->TextOutW(350, 105, pDoc->L);

}


// CMFCApplication62View ���

#ifdef _DEBUG
void CMFCApplication62View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication62Doc* CMFCApplication62View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication62Doc)));
	return (CMFCApplication62Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication62View ��Ϣ�������


void CMFCApplication62View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication62Doc* pDoc = GetDocument();
	char ch[100];
	int i = 0;
	//int length;
	ch[i] = nChar;
	pDoc->s.Format(_T("%c"), ch[i]); 
	pDoc->L = pDoc->L + pDoc->s;
	if (pDoc->a)
	{

	}
	i++;
	//dc.TextOutW(250,105,s);
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCApplication62View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication62Doc* pDoc = GetDocument();
	pDoc->p = point;
	pDoc->a = true;
	CView::OnLButtonDown(nFlags, point);
}
