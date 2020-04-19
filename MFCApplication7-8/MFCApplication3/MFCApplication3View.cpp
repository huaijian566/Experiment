
// MFCApplication3View.cpp : CMFCApplication3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3View

IMPLEMENT_DYNCREATE(CMFCApplication3View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication3View, CView)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFCApplication3View 构造/析构

CMFCApplication3View::CMFCApplication3View()
{
	// TODO: 在此处添加构造代码
	b = false; c = false;
	//t.left = 0; t.right = 100; t.top = 0; t.bottom = 100;
}

CMFCApplication3View::~CMFCApplication3View()
{
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication3View 绘制

void CMFCApplication3View::OnDraw(CDC* pDC)
{
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	GetClientRect(&rect);
	if (pDoc->a)
	{
		pDoc->t.left = rect.right / 4 - 50;
		pDoc->t.right = rect.right / 4 + 50;
		pDoc->t.top = rect.bottom / 2 - 50;
		pDoc->t.bottom = rect.bottom / 2 + 50;
	}
	pDC->Ellipse(pDoc->t);
	SetTimer(0,300, NULL);
}


// CMFCApplication3View 诊断

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View 消息处理程序


void CMFCApplication3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication3Doc* pDoc = GetDocument();
	
	if (b&&!c)
	{
		pDoc->t.right += 30;
		pDoc->t.left += 30;
		Invalidate();
		if (pDoc->t.right >= rect.right)c = true;
	}
	
	if (b&&c)
	{
		
		pDoc->t.right -= 30;
		pDoc->t.left -= 30;
		Invalidate();
		if (pDoc->t.left <= rect.left)c = false;
	}

		CView::OnTimer(nIDEvent);
}


void CMFCApplication3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication3Doc* pDoc = GetDocument();
	pDoc->a = false;
	b = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	b = false;
	CView::OnLButtonDblClk(nFlags, point);
}
