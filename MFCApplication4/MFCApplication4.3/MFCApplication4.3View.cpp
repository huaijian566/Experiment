
// MFCApplication4.3View.cpp : CMFCApplication43View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.3.h"
#endif

#include "MFCApplication4.3Doc.h"
#include "MFCApplication4.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication43View

IMPLEMENT_DYNCREATE(CMFCApplication43View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication43View, CView)
	ON_COMMAND(ID_HuaXian, &CMFCApplication43View::OnHuaxian)
	ON_COMMAND(ID_HuaJuXing, &CMFCApplication43View::OnHuajuxing)
	ON_COMMAND(ID_HuaTuoYuan, &CMFCApplication43View::OnHuatuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication43View 构造/析构

CMFCApplication43View::CMFCApplication43View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication43View::~CMFCApplication43View()
{
}

BOOL CMFCApplication43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication43View 绘制

void CMFCApplication43View::OnDraw(CDC* pDC)
{
	CMFCApplication43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (pDoc->a)
	{
		pDC->MoveTo(pDoc->p1);
		pDC->LineTo(pDoc->p2);
	}
	if (pDoc->b)
	{
		CRect cr ;
		cr.left = pDoc->p1.x;
		cr.top = pDoc->p1.y;
		cr.right = pDoc->p2.x;
		cr.bottom = pDoc->p2.y;
		pDC->Rectangle(cr);
	}
	if (pDoc->c)
	{
		CRect cr;
		cr.left = pDoc->p1.x;
		cr.top = pDoc->p1.y;
		cr.right = pDoc->p2.x;
		cr.bottom = pDoc->p2.y;
		pDC->Ellipse(cr);
	}

}


// CMFCApplication43View 诊断

#ifdef _DEBUG
void CMFCApplication43View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication43Doc* CMFCApplication43View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication43Doc)));
	return (CMFCApplication43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication43View 消息处理程序


void CMFCApplication43View::OnHuaxian()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication43Doc* pDoc = GetDocument();
	pDoc->a = true;
	pDoc->b = false;
	pDoc->c = false;
}


void CMFCApplication43View::OnHuajuxing()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication43Doc* pDoc = GetDocument();
	pDoc->a = false;
	pDoc->b = true;
	pDoc->c = false;
}


void CMFCApplication43View::OnHuatuoyuan()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication43Doc* pDoc = GetDocument();
	pDoc->a = false;
	pDoc->b = false;
	pDoc->c = true;
}


void CMFCApplication43View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication43Doc* pDoc = GetDocument();
	pDoc->p1 = point;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication43View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication43Doc* pDoc = GetDocument();
	pDoc->p2 = point;
	
	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication43View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
}
