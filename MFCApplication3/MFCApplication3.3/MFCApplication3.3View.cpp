
// MFCApplication3.3View.cpp : CMFCApplication33View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication3.3.h"
#endif

#include "MFCApplication3.3Doc.h"
#include "MFCApplication3.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication33View

IMPLEMENT_DYNCREATE(CMFCApplication33View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication33View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication33View ����/����

CMFCApplication33View::CMFCApplication33View()
{
	// TODO: �ڴ˴���ӹ������
	n = 5;
	set = true;
	for (int i = 0; i < n; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);
	}

}

CMFCApplication33View::~CMFCApplication33View()
{
}

BOOL CMFCApplication33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication33View ����

void CMFCApplication33View::OnDraw(CDC* pDC)
{
	CMFCApplication33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < n; i++)
	{
		pDC->Ellipse(cr[i]);
	}
		if (set)
		{
			for (int i = 0; i < n; i++)
			{
				SetTimer(i, rand() % 400 + 100, NULL);
			}
			set = false;
		}
	

}


// CMFCApplication33View ���

#ifdef _DEBUG
void CMFCApplication33View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication33Doc* CMFCApplication33View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication33Doc)));
	return (CMFCApplication33Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication33View ��Ϣ�������


void CMFCApplication33View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect r;
	GetClientRect(&r);
	int i = nIDEvent;
	bool b = true;
	if (cr[i].bottom >= r.bottom)b = false;
	else b = true;
	if (b)
	{
		cr[i].top += 10;
		cr[i].bottom += 10;
	
	}
	if (!b)
	{
	
			cr[i].top -= 600;
			cr[i].bottom -= 600;
	
	}
		Invalidate();
	
		

		

	CView::OnTimer(nIDEvent);
}
