
// MFCApplication7.1View.cpp : CMFCApplication71View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication7.1.h"
#endif

#include "MFCApplication7.1Doc.h"
#include "MFCApplication7.1View.h"
#include "MyDialog.h";
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication71View

IMPLEMENT_DYNCREATE(CMFCApplication71View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication71View, CView)
	ON_COMMAND(ID_SHOWDIALOG, &CMFCApplication71View::OnShowdialog)
END_MESSAGE_MAP()

// CMFCApplication71View 构造/析构

CMFCApplication71View::CMFCApplication71View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication71View::~CMFCApplication71View()
{
}

BOOL CMFCApplication71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication71View 绘制

void CMFCApplication71View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication71View 诊断

#ifdef _DEBUG
void CMFCApplication71View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication71Doc* CMFCApplication71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication71Doc)));
	return (CMFCApplication71Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication71View 消息处理程序


void CMFCApplication71View::OnShowdialog()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog d;
	Invalidate();
	int t = d.DoModal();
	if (t == IDOK)
	{
		CString s =_T( "你已退出对话框");
		GetDC()->TextOutW(300, 300, s);
	}
}
