
// MFCApplication6.2View.cpp : CMFCApplication62View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication6.2.h"
#endif

#include "MFCApplication6.2Doc.h"
#include "MFCApplication6.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication62View

IMPLEMENT_DYNCREATE(CMFCApplication62View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication62View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication62View 构造/析构

CMFCApplication62View::CMFCApplication62View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication62View::~CMFCApplication62View()
{
}

BOOL CMFCApplication62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication62View 绘制

void CMFCApplication62View::OnDraw(CDC* pDC)
{
	CMFCApplication62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr(100,100,800,130);
	pDC->Rectangle(cr);
	pDC->TextOutW(350, 105, pDoc->L);

}


// CMFCApplication62View 诊断

#ifdef _DEBUG
void CMFCApplication62View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication62Doc* CMFCApplication62View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication62Doc)));
	return (CMFCApplication62Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication62View 消息处理程序


void CMFCApplication62View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication62Doc* pDoc = GetDocument();
	char ch[100];
	int i = 0;
	//int length;
	ch[i] = nChar;
	pDoc->s.Format(_T("%c"), ch[i]); 
	pDoc->L = pDoc->L + pDoc->s;
	if (pDoc->a)
	{

	}
	i++;
	//dc.TextOutW(250,105,s);
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCApplication62View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication62Doc* pDoc = GetDocument();
	pDoc->p = point;
	pDoc->a = true;
	CView::OnLButtonDown(nFlags, point);
}
