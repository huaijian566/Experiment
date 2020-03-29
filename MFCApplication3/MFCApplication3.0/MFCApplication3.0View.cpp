
// MFCApplication3.0View.cpp : CMFCApplication30View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3.0.h"
#endif

#include "MFCApplication3.0Doc.h"
#include "MFCApplication3.0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication30View

IMPLEMENT_DYNCREATE(CMFCApplication30View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication30View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication30View 构造/析构

CMFCApplication30View::CMFCApplication30View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication30View::~CMFCApplication30View()
{
}

BOOL CMFCApplication30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication30View 绘制

void CMFCApplication30View::OnDraw(CDC* pDC)
{
	CMFCApplication30Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->cr);
}


// CMFCApplication30View 诊断

#ifdef _DEBUG
void CMFCApplication30View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication30View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication30Doc* CMFCApplication30View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication30Doc)));
	return (CMFCApplication30Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication30View 消息处理程序


void CMFCApplication30View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication30Doc* pDoc = GetDocument();
	SetCapture();
	pDoc->cr.left = point.x;
	pDoc->cr.top = point.y;
	//InvalidateRect(NULL, true);
	CString str;
	str.Format(_T("鼠标左键按下的坐标：（%d,%d）"), point.x, point.y);
	CClientDC dc(this);
	dc.TextOutW(point.x, point.y, str);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication30View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication30Doc* pDoc = GetDocument();
	ReleaseCapture();
	pDoc->cr.right = point.x;
	pDoc->cr.bottom = point.y;
	InvalidateRect(NULL, true);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication30View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	CClientDC dc(this);
	//int a = point.x;
	str.Format(_T("当前鼠标的坐标：（%d,%d）"), point.x,point.y);
	dc.TextOutW(20, 20, str);
	CView::OnMouseMove(nFlags, point);
}
