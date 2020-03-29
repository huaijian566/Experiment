
// MFCApplication4.02View.cpp : CMFCApplication402View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.02.h"
#endif

#include "MFCApplication4.02Doc.h"
#include "MFCApplication4.02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication402View

IMPLEMENT_DYNCREATE(CMFCApplication402View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication402View, CView)
	ON_COMMAND(ID_HuaYuan, &CMFCApplication402View::OnHuayuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication402View 构造/析构

CMFCApplication402View::CMFCApplication402View()
{
	// TODO: 在此处添加构造代码
	set = false;
}

CMFCApplication402View::~CMFCApplication402View()
{
}

BOOL CMFCApplication402View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication402View 绘制

void CMFCApplication402View::OnDraw(CDC* pDC)
{
	CMFCApplication402Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//int red = 0, green = 0, blue = 0;
	int color = RGB(pDoc->red, pDoc -> green, pDoc -> blue);
	int width = 2;
	CPen newPen(PS_SOLID, width, color);
	CPen*oldPen = pDC->SelectObject(&newPen);
	if (set)
		SetTimer(1, 500, NULL);
	pDC->Ellipse(pDoc->t);
	//pDC->SelectObject(oldPen);
	
}


// CMFCApplication402View 诊断

#ifdef _DEBUG
void CMFCApplication402View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication402View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication402Doc* CMFCApplication402View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication402Doc)));
	return (CMFCApplication402Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication402View 消息处理程序


void CMFCApplication402View::OnHuayuan()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication402Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	pDoc->t.left = cr.right / 2 - 10;
	pDoc->t.right = cr.right / 2 + 10;
	pDoc->t.top = cr.bottom / 2 - 10;
	pDoc->t.bottom = cr.bottom / 2 + 10;
	//CClientDC dc(this);
	//dc.Ellipse(t);
	set = true;
	Invalidate();
}


void CMFCApplication402View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication402Doc* pDoc = GetDocument();
	pDoc->t.top -= 10;
	pDoc->t.bottom += 10;
	pDoc->t.right += 10;
	pDoc->t.left -= 10;
	pDoc->red += 100;
	pDoc->green += 2000;
	pDoc->blue += 30;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
