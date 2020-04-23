
// MFCApplication2View.cpp : CMFCApplication2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"
#include "Dialog1.h"
#include "yansedialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_OPENDIALOG, &CMFCApplication2View::OnOpendialog)
	ON_COMMAND(ID_yansezhi, &CMFCApplication2View::Onyansezhi)
END_MESSAGE_MAP()

// CMFCApplication2View 构造/析构

CMFCApplication2View::CMFCApplication2View()
{
	// TODO: 在此处添加构造代码
	set1 = false;
	set2 = true;
	set3 = false;
}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View 绘制

void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(pDoc->a);
	
	
}


// CMFCApplication2View 诊断

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View 消息处理程序


void CMFCApplication2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication2Doc* pDoc = GetDocument();
	set1 = true;
	pDoc->a.left = point.x;
	pDoc->a.top = point.y;

	for (int i = 0; i < pDoc->ca.GetSize(); i++)
	{
		if ((point.x > pDoc->ca[i].left) && (point.x < pDoc->ca[i].right) && (point.y > pDoc->ca[i].top) && (point.y < pDoc->ca[i].bottom))

		{
			CDC* pDC = GetDC();
			int color = RGB(0, 0, 0);
			CPen newPen(PS_DOT, 1, color);
			CPen*oldPen = pDC->SelectObject(&newPen);
			pDC->Rectangle(pDoc->ca[i]);
			pDC->SelectObject(oldPen);
			pDC->Ellipse(pDoc->ca[i]);
			k = i;

		}
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication2Doc* pDoc = GetDocument();
	set1 = false;
	pDoc->a.right = point.x;
	pDoc->a.bottom = point.y;
	//InvalidateRect(NULL, true);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication2Doc* pDoc = GetDocument();
	if (set1)
	{
		pDoc->a.right = point.x;
		pDoc->a.bottom = point.y;
	}
	if(set2)
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication2View::OnOpendialog()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication2Doc* pDoc = GetDocument();
	Dialog1 dlg;
	int t = dlg.DoModal();
	set2 = false;
	if (t == IDOK)
	{
		int L, D;
		L = dlg.l;
		D = dlg.d;
		CRect cr(dlg.x, dlg.y, dlg.x + L, dlg.y + D);
		pDoc->ca.Add(cr);
		for (int i = 0; i < pDoc->ca.GetSize(); i++)
		{
			
			GetDC()->Ellipse(cr);
		}
	}
}


void CMFCApplication2View::Onyansezhi()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication2Doc* pDoc = GetDocument();
	yansedialog dlg;
	int t = dlg.DoModal();
	//set2 = false;
	if (t == IDOK)
	{
			CDC* pDC = GetDC();
			int color = RGB(dlg.r,dlg.g,dlg.b);
			CBrush newBrush(color);
			CBrush*oldBrush = pDC->SelectObject(&newBrush);
			pDC->Ellipse(pDoc->ca[k]);
			pDC->SelectObject(oldBrush);
			//GetDC()->Ellipse(cr);
		
	}
}
