
// MFCApplication4.01View.cpp : CMFCApplication401View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication4.01.h"
#endif

#include "MFCApplication4.01Doc.h"
#include "MFCApplication4.01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication401View

IMPLEMENT_DYNCREATE(CMFCApplication401View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication401View, CView)
	ON_COMMAND(ID_HuaYuan, &CMFCApplication401View::OnHuayuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication401View ����/����

CMFCApplication401View::CMFCApplication401View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
}

CMFCApplication401View::~CMFCApplication401View()
{
}

BOOL CMFCApplication401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication401View ����

void CMFCApplication401View::OnDraw(CDC* pDC)
{
	CMFCApplication401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(pDoc->t);
	if (set)
		SetTimer(1,500,NULL);

}


// CMFCApplication401View ���

#ifdef _DEBUG
void CMFCApplication401View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication401Doc* CMFCApplication401View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication401Doc)));
	return (CMFCApplication401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication401View ��Ϣ�������


void CMFCApplication401View::OnHuayuan()
{
	// TODO: �ڴ���������������
	CMFCApplication401Doc* pDoc = GetDocument();
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


void CMFCApplication401View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication401Doc* pDoc = GetDocument();
	pDoc->t.top -= 10;
	pDoc->t.bottom += 10;
	pDoc->t.right += 10;
	pDoc->t.left-= 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
