
// MFCApplication2View.cpp : CMFCApplication2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"
#include "Dialog1.h"
#include "yansedialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_OPENDIALOG, &CMFCApplication2View::OnOpendialog)
	ON_COMMAND(ID_yansezhi, &CMFCApplication2View::Onyansezhi)
END_MESSAGE_MAP()

// CMFCApplication2View ����/����

CMFCApplication2View::CMFCApplication2View()
{
	// TODO: �ڴ˴���ӹ������
	set1 = false;
	set2 = true;
	set3 = false;
}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View ����

void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(pDoc->a);
	
	
}


// CMFCApplication2View ���

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View ��Ϣ�������


void CMFCApplication2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication2Doc* pDoc = GetDocument();
	set1 = true;
	pDoc->a.left = point.x;
	pDoc->a.top = point.y;

	for (int i = 0; i < pDoc->ca.GetSize(); i++)
	{
		if ((point.x > pDoc->ca[i].left) && (point.x < pDoc->ca[i].right) && (point.y > pDoc->ca[i].top) && (point.y < pDoc->ca[i].bottom))

		{
			CDC* pDC = GetDC();
			int color = RGB(0, 0, 0);
			CPen newPen(PS_DOT, 1, color);
			CPen*oldPen = pDC->SelectObject(&newPen);
			pDC->Rectangle(pDoc->ca[i]);
			pDC->SelectObject(oldPen);
			pDC->Ellipse(pDoc->ca[i]);
			k = i;

		}
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication2Doc* pDoc = GetDocument();
	set1 = false;
	pDoc->a.right = point.x;
	pDoc->a.bottom = point.y;
	//InvalidateRect(NULL, true);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication2Doc* pDoc = GetDocument();
	if (set1)
	{
		pDoc->a.right = point.x;
		pDoc->a.bottom = point.y;
	}
	if(set2)
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication2View::OnOpendialog()
{
	// TODO: �ڴ���������������
	CMFCApplication2Doc* pDoc = GetDocument();
	Dialog1 dlg;
	int t = dlg.DoModal();
	set2 = false;
	if (t == IDOK)
	{
		int L, D;
		L = dlg.l;
		D = dlg.d;
		CRect cr(dlg.x, dlg.y, dlg.x + L, dlg.y + D);
		pDoc->ca.Add(cr);
		for (int i = 0; i < pDoc->ca.GetSize(); i++)
		{
			
			GetDC()->Ellipse(cr);
		}
	}
}


void CMFCApplication2View::Onyansezhi()
{
	// TODO: �ڴ���������������
	CMFCApplication2Doc* pDoc = GetDocument();
	yansedialog dlg;
	int t = dlg.DoModal();
	//set2 = false;
	if (t == IDOK)
	{
			CDC* pDC = GetDC();
			int color = RGB(dlg.r,dlg.g,dlg.b);
			CBrush newBrush(color);
			CBrush*oldBrush = pDC->SelectObject(&newBrush);
			pDC->Ellipse(pDoc->ca[k]);
			pDC->SelectObject(oldBrush);
			//GetDC()->Ellipse(cr);
		
	}
}
