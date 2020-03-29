
// MFCApplication2.4View.cpp : CMFCApplication24View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2.4.h"
#endif

#include "MFCApplication2.4Doc.h"
#include "MFCApplication2.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication24View

IMPLEMENT_DYNCREATE(CMFCApplication24View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication24View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication24View 构造/析构

CMFCApplication24View::CMFCApplication24View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication24View::~CMFCApplication24View()
{
}

BOOL CMFCApplication24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication24View 绘制

void CMFCApplication24View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication24View 诊断

#ifdef _DEBUG
void CMFCApplication24View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication24Doc* CMFCApplication24View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication24Doc)));
	return (CMFCApplication24Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication24View 消息处理程序


void CMFCApplication24View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication24Doc* pDoc = GetDocument();
	int n = pDoc->A + pDoc->B;
	CString s;
	s.Format(_T("%d"), n);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
