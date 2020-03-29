
// MFCexperiment1.2View.cpp : CMFCexperiment12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCexperiment1.2.h"
#endif

#include "MFCexperiment1.2Doc.h"
#include "MFCexperiment1.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCexperiment12View

IMPLEMENT_DYNCREATE(CMFCexperiment12View, CView)

BEGIN_MESSAGE_MAP(CMFCexperiment12View, CView)
END_MESSAGE_MAP()

// CMFCexperiment12View 构造/析构

CMFCexperiment12View::CMFCexperiment12View()
{
	// TODO: 在此处添加构造代码

}

CMFCexperiment12View::~CMFCexperiment12View()
{
}

BOOL CMFCexperiment12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCexperiment12View 绘制

void CMFCexperiment12View::OnDraw(CDC* pDC)
{
	CMFCexperiment12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(200, 200, pDoc->s);
	int b = pDoc->a;
	CString c;
	c.Format(_T("%d"), b);
	pDC->TextOutW(300, 200, c);

}


// CMFCexperiment12View 诊断

#ifdef _DEBUG
void CMFCexperiment12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexperiment12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexperiment12Doc* CMFCexperiment12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexperiment12Doc)));
	return (CMFCexperiment12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCexperiment12View 消息处理程序
