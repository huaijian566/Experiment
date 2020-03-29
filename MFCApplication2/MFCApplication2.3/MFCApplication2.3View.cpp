
// MFCApplication2.3View.cpp : CMFCApplication23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2.3.h"
#endif

#include "MFCApplication2.3Doc.h"
#include "MFCApplication2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication23View

IMPLEMENT_DYNCREATE(CMFCApplication23View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication23View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication23View 构造/析构

CMFCApplication23View::CMFCApplication23View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication23View::~CMFCApplication23View()
{
}

BOOL CMFCApplication23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication23View 绘制

void CMFCApplication23View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication23View 诊断

#ifdef _DEBUG
void CMFCApplication23View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication23Doc* CMFCApplication23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication23Doc)));
	return (CMFCApplication23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication23View 消息处理程序


void CMFCApplication23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s = _T("左键正被按下");
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication23View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s = _T("左键正在抬起");
	dc.TextOutW(200, 200, s);
	CView::OnLButtonUp(nFlags, point);
}
