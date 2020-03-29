
// MFCApplication4.02View.cpp : CMFCApplication402View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication4.02.h"
#endif

#include "MFCApplication4.02Doc.h"
#include "MFCApplication4.02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication402View

IMPLEMENT_DYNCREATE(CMFCApplication402View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication402View, CView)
	ON_COMMAND(ID_HuaYuan, &CMFCApplication402View::OnHuayuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication402View ����/����

CMFCApplication402View::CMFCApplication402View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
}

CMFCApplication402View::~CMFCApplication402View()
{
}

BOOL CMFCApplication402View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication402View ����

void CMFCApplication402View::OnDraw(CDC* pDC)
{
	CMFCApplication402Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//int red = 0, green = 0, blue = 0;
	int color = RGB(pDoc->red, pDoc -> green, pDoc -> blue);
	int width = 2;
	CPen newPen(PS_SOLID, width, color);
	CPen*oldPen = pDC->SelectObject(&newPen);
	if (set)
		SetTimer(1, 500, NULL);
	pDC->Ellipse(pDoc->t);
	//pDC->SelectObject(oldPen);
	
}


// CMFCApplication402View ���

#ifdef _DEBUG
void CMFCApplication402View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication402View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication402Doc* CMFCApplication402View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication402Doc)));
	return (CMFCApplication402Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication402View ��Ϣ�������


void CMFCApplication402View::OnHuayuan()
{
	// TODO: �ڴ���������������
	CMFCApplication402Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	pDoc->t.left = cr.right / 2 - 10;
	pDoc->t.right = cr.right / 2 + 10;
	pDoc->t.top = cr.bottom / 2 - 10;
	pDoc->t.bottom = cr.bottom / 2 + 10;
	//CClientDC dc(this);
	//dc.Ellipse(t);
	set = true;
	Invalidate();
}


void CMFCApplication402View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication402Doc* pDoc = GetDocument();
	pDoc->t.top -= 10;
	pDoc->t.bottom += 10;
	pDoc->t.right += 10;
	pDoc->t.left -= 10;
	pDoc->red += 100;
	pDoc->green += 2000;
	pDoc->blue += 30;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
