
// MFCApplication4.1View.cpp : CMFCApplication41View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.1.h"
#endif

#include "MFCApplication4.1Doc.h"
#include "MFCApplication4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication41View

IMPLEMENT_DYNCREATE(CMFCApplication41View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication41View, CView)
	ON_COMMAND(ID_ShowName, &CMFCApplication41View::OnShowname)
END_MESSAGE_MAP()

// CMFCApplication41View 构造/析构

CMFCApplication41View::CMFCApplication41View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication41View::~CMFCApplication41View()
{
}

BOOL CMFCApplication41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication41View 绘制

void CMFCApplication41View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication41View 诊断

#ifdef _DEBUG
void CMFCApplication41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication41Doc* CMFCApplication41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication41Doc)));
	return (CMFCApplication41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication41View 消息处理程序


void CMFCApplication41View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("黄景瑜");
	CClientDC dc(this);
	dc.TextOutW(200,200,s);
}
