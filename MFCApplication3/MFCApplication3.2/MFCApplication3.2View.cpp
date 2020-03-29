
// MFCApplication3.2View.cpp : CMFCApplication32View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFCApplication32View 构造/析构

CMFCApplication32View::CMFCApplication32View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication32View::~CMFCApplication32View()
{
}

BOOL CMFCApplication32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication32View 绘制

void CMFCApplication32View::OnDraw(CDC* pDC)
{
	CMFCApplication32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	this->GetClientRect(&pDoc->cr);
	/*pDoc->a.left = pDoc->cr.right / 2 - 50;
	pDoc->a.right = pDoc->cr.right / 2 + 50;
	pDoc->a.top = pDoc->cr.bottom / 2 - 25;
	pDoc->a.bottom = pDoc->cr.bottom / 2 + 25;*/
	pDC->Rectangle(pDoc->a);

}


// CMFCApplication32View 诊断

#ifdef _DEBUG
void CMFCApplication32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication32Doc* CMFCApplication32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication32Doc)));
	return (CMFCApplication32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication32View 消息处理程序


void CMFCApplication32View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication32Doc* pDoc = GetDocument();
	pDoc->a.left = 600;
	pDoc->a.right = 700;
	pDoc->a.top = 300;
	pDoc->a.bottom = 350;
	InvalidateRect(NULL, true);
	CView::OnLButtonDown(nFlags, point);
}
