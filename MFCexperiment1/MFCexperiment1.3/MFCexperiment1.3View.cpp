
// MFCexperiment1.3View.cpp : CMFCexperiment13View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCexperiment1.3.h"
#endif

#include "MFCexperiment1.3Doc.h"
#include "MFCexperiment1.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCexperiment13View

IMPLEMENT_DYNCREATE(CMFCexperiment13View, CView)

BEGIN_MESSAGE_MAP(CMFCexperiment13View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCexperiment13View 构造/析构

CMFCexperiment13View::CMFCexperiment13View()
{
	// TODO: 在此处添加构造代码

}

CMFCexperiment13View::~CMFCexperiment13View()
{
}

BOOL CMFCexperiment13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCexperiment13View 绘制

void CMFCexperiment13View::OnDraw(CDC* /*pDC*/)
{
	CMFCexperiment13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCexperiment13View 诊断

#ifdef _DEBUG
void CMFCexperiment13View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexperiment13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexperiment13Doc* CMFCexperiment13View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexperiment13Doc)));
	return (CMFCexperiment13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCexperiment13View 消息处理程序


void CMFCexperiment13View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCexperiment13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	 pDoc->count++;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFCexperiment13View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCexperiment13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int c = pDoc->count;
	CString s;
	s.Format(_T("%d"),c );
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
