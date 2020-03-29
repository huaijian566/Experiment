
// MFCApplication2.2View.cpp : CMFCApplication22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2.2.h"
#endif

#include "MFCApplication2.2Doc.h"
#include "MFCApplication2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication22View

IMPLEMENT_DYNCREATE(CMFCApplication22View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication22View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication22View 构造/析构

CMFCApplication22View::CMFCApplication22View()
{
	// TODO: 在此处添加构造代码
	//ca.SetSize(100);
}

CMFCApplication22View::~CMFCApplication22View()
{
}

BOOL CMFCApplication22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication22View 绘制

void CMFCApplication22View::OnDraw(CDC* pDC)
{
	CMFCApplication22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));

}


// CMFCApplication22View 诊断

#ifdef _DEBUG
void CMFCApplication22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication22Doc* CMFCApplication22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication22Doc)));
	return (CMFCApplication22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication22View 消息处理程序


void CMFCApplication22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication22Doc* pDoc = GetDocument();
	int r = rand() % 50 + 5;
	int r2 = rand() % 30 + 3;
	CRect cr(point.x - r, point.y - r2, point.x + r, point.y + r2);
	pDoc->ca.Add(cr);
	this->Invalidate();
	//CClientDC dc(this);
	//dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
