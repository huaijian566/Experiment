
// MFCApplication4.3View.cpp : CMFCApplication43View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication4.3.h"
#endif

#include "MFCApplication4.3Doc.h"
#include "MFCApplication4.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication43View

IMPLEMENT_DYNCREATE(CMFCApplication43View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication43View, CView)
	ON_COMMAND(ID_HuaXian, &CMFCApplication43View::OnHuaxian)
	ON_COMMAND(ID_HuaJuXing, &CMFCApplication43View::OnHuajuxing)
	ON_COMMAND(ID_HuaTuoYuan, &CMFCApplication43View::OnHuatuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication43View ����/����

CMFCApplication43View::CMFCApplication43View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication43View::~CMFCApplication43View()
{
}

BOOL CMFCApplication43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication43View ����

void CMFCApplication43View::OnDraw(CDC* pDC)
{
	CMFCApplication43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (pDoc->a)
	{
		pDC->MoveTo(pDoc->p1);
		pDC->LineTo(pDoc->p2);
	}
	if (pDoc->b)
	{
		CRect cr ;
		cr.left = pDoc->p1.x;
		cr.top = pDoc->p1.y;
		cr.right = pDoc->p2.x;
		cr.bottom = pDoc->p2.y;
		pDC->Rectangle(cr);
	}
	if (pDoc->c)
	{
		CRect cr;
		cr.left = pDoc->p1.x;
		cr.top = pDoc->p1.y;
		cr.right = pDoc->p2.x;
		cr.bottom = pDoc->p2.y;
		pDC->Ellipse(cr);
	}

}


// CMFCApplication43View ���

#ifdef _DEBUG
void CMFCApplication43View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication43Doc* CMFCApplication43View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication43Doc)));
	return (CMFCApplication43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication43View ��Ϣ�������


void CMFCApplication43View::OnHuaxian()
{
	// TODO: �ڴ���������������
	CMFCApplication43Doc* pDoc = GetDocument();
	pDoc->a = true;
	pDoc->b = false;
	pDoc->c = false;
}


void CMFCApplication43View::OnHuajuxing()
{
	// TODO: �ڴ���������������
	CMFCApplication43Doc* pDoc = GetDocument();
	pDoc->a = false;
	pDoc->b = true;
	pDoc->c = false;
}


void CMFCApplication43View::OnHuatuoyuan()
{
	// TODO: �ڴ���������������
	CMFCApplication43Doc* pDoc = GetDocument();
	pDoc->a = false;
	pDoc->b = false;
	pDoc->c = true;
}


void CMFCApplication43View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication43Doc* pDoc = GetDocument();
	pDoc->p1 = point;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication43View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication43Doc* pDoc = GetDocument();
	pDoc->p2 = point;
	
	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication43View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnMouseMove(nFlags, point);
}
