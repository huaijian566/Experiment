
// MFCApplication4.01View.cpp : CMFCApplication401View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.01.h"
#endif

#include "MFCApplication4.01Doc.h"
#include "MFCApplication4.01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication401View

IMPLEMENT_DYNCREATE(CMFCApplication401View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication401View, CView)
	ON_COMMAND(ID_HuaYuan, &CMFCApplication401View::OnHuayuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication401View 构造/析构

CMFCApplication401View::CMFCApplication401View()
{
	// TODO: 在此处添加构造代码
	set = false;
}

CMFCApplication401View::~CMFCApplication401View()
{
}

BOOL CMFCApplication401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication401View 绘制

void CMFCApplication401View::OnDraw(CDC* pDC)
{
	CMFCApplication401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(pDoc->t);
	if (set)
		SetTimer(1,500,NULL);

}


// CMFCApplication401View 诊断

#ifdef _DEBUG
void CMFCApplication401View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication401Doc* CMFCApplication401View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication401Doc)));
	return (CMFCApplication401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication401View 消息处理程序


void CMFCApplication401View::OnHuayuan()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication401Doc* pDoc = GetDocument();
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


void CMFCApplication401View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication401Doc* pDoc = GetDocument();
	pDoc->t.top -= 10;
	pDoc->t.bottom += 10;
	pDoc->t.right += 10;
	pDoc->t.left-= 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
