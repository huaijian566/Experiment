
// MFCApplication3.2View.cpp : CMFCApplication32View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication3.2.h"
#endif

#include "MFCApplication3.2Doc.h"
#include "MFCApplication3.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication32View

IMPLEMENT_DYNCREATE(CMFCApplication32View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication32View, CView)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication32View ����/����

CMFCApplication32View::CMFCApplication32View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication32View::~CMFCApplication32View()
{
}

BOOL CMFCApplication32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication32View ����

void CMFCApplication32View::OnDraw(CDC* pDC)
{
	CMFCApplication32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	this->GetClientRect(&pDoc->cr);
	/*pDoc->a.left = pDoc->cr.right / 2 - 50;
	pDoc->a.right = pDoc->cr.right / 2 + 50;
	pDoc->a.top = pDoc->cr.bottom / 2 - 25;
	pDoc->a.bottom = pDoc->cr.bottom / 2 + 25;*/
	pDC->Rectangle(pDoc->a);

}


// CMFCApplication32View ���

#ifdef _DEBUG
void CMFCApplication32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication32Doc* CMFCApplication32View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication32Doc)));
	return (CMFCApplication32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication32View ��Ϣ�������


void CMFCApplication32View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication32Doc* pDoc = GetDocument();
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->a.left > 0)
		{
			pDoc->a.left -= 20;
			pDoc->a.right -= 20;
		}
		break;
	case VK_RIGHT:
		if (pDoc->a.right <= (pDoc->cr.right - pDoc->cr.left))
		{
			pDoc->a.left += 20;
			pDoc->a.right += 20;
		}
		break;
	case VK_UP:
		if (pDoc->a.top> 0)
		{
			pDoc->a.top -= 20;
			pDoc->a.bottom-= 20;
		}
		break;
	case VK_DOWN:
		if (pDoc->a.bottom <= (pDoc->cr.bottom - pDoc->cr.top))
		{
			pDoc->a.top += 20;
			pDoc->a.bottom += 20;
		}
		break;
	}
	InvalidateRect(NULL, true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CMFCApplication32View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication32Doc* pDoc = GetDocument();
	switch (nChar)
	{
	case 'H':
		if ((pDoc->a.left > 0) && (pDoc->a.top>0))
		{
			pDoc->a.left -= 20;
			pDoc->a.top -= 20;
		}
		break;
	case 'E':
		if (pDoc->a.right <= (pDoc->cr.right - pDoc->cr.left))
		{
			pDoc->a.left += 20;
			pDoc->a.top += 20;
		}
		break;
	}
	InvalidateRect(NULL, true);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCApplication32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication32Doc* pDoc = GetDocument();
	pDoc->a.left = 600;
	pDoc->a.right = 700;
	pDoc->a.top = 300;
	pDoc->a.bottom = 350;
	InvalidateRect(NULL, true);
	CView::OnLButtonDown(nFlags, point);
}
