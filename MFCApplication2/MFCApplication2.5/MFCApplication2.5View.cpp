
// MFCApplication2.5View.cpp : CMFCApplication25View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2.5.h"
#endif

#include "MFCApplication2.5Doc.h"
#include "MFCApplication2.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication25View

IMPLEMENT_DYNCREATE(CMFCApplication25View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication25View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication25View 构造/析构

CMFCApplication25View::CMFCApplication25View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication25View::~CMFCApplication25View()
{
}

BOOL CMFCApplication25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication25View 绘制

void CMFCApplication25View::OnDraw(CDC* pDC)
{
	CMFCApplication25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);
}


// CMFCApplication25View 诊断

#ifdef _DEBUG
void CMFCApplication25View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication25Doc* CMFCApplication25View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication25Doc)));
	return (CMFCApplication25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication25View 消息处理程序


void CMFCApplication25View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication25Doc* pDoc = GetDocument();
	CClientDC dc(this);
	
	if(pDoc->A.left<point.x&&point.x<pDoc->A.right&&pDoc->A.top<point.y&&point.y<pDoc->A.bottom)
	{
		int a2 = pDoc->a;
		CString s;
		s.Format(_T("%d"), a2);
		dc.TextOutW(250, 250, s);
	}
	else if (pDoc->B.left<point.x&&point.x<pDoc->B.right&&pDoc->B.top<point.y&&point.y<pDoc->B.bottom)
	{
		int b2 = pDoc->b;
		CString c;
		c.Format(_T("%d"), b2);
		dc.TextOutW(400, 250, c);
	}
	else
	{
		CString n = _T("点击无效");
		dc.TextOutW(200, 400, n);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication25View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication25Doc* pDoc = GetDocument();
	CClientDC dc(this);

	if (pDoc->C.left<point.x&&point.x<pDoc->C.right&&pDoc->C.top<point.y&&point.y<pDoc->C.bottom)
	{
		int c = pDoc->a+pDoc->b;
		CString s;
		s.Format(_T("%d"), c);
		dc.TextOutW(550, 250, s);
	}
	CView::OnRButtonDown(nFlags, point);
}
