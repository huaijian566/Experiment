
// MFCexperiment1View.cpp : CMFCexperiment1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCexperiment1.h"
#endif

#include "MFCexperiment1Doc.h"
#include "MFCexperiment1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCexperiment1View

IMPLEMENT_DYNCREATE(CMFCexperiment1View, CView)

BEGIN_MESSAGE_MAP(CMFCexperiment1View, CView)
END_MESSAGE_MAP()

// CMFCexperiment1View 构造/析构

CMFCexperiment1View::CMFCexperiment1View()
{
	// TODO: 在此处添加构造代码

}

CMFCexperiment1View::~CMFCexperiment1View()
{
}

BOOL CMFCexperiment1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCexperiment1View 绘制

void CMFCexperiment1View::OnDraw(CDC* pDC)
{
	CMFCexperiment1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s = _T("我是张三");
	CString c;
	int a = 666;
	c.Format(_T("%d"), a);
	pDC->TextOutW(200, 200, s);
	pDC->TextOutW(300, 200, c);

}


// CMFCexperiment1View 诊断

#ifdef _DEBUG
void CMFCexperiment1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexperiment1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexperiment1Doc* CMFCexperiment1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexperiment1Doc)));
	return (CMFCexperiment1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCexperiment1View 消息处理程序
