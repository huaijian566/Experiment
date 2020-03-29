
// MFCApplication4.2View.cpp : CMFCApplication42View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.2.h"
#endif

#include "MFCApplication4.2Doc.h"
#include "MFCApplication4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication42View

IMPLEMENT_DYNCREATE(CMFCApplication42View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication42View, CView)
END_MESSAGE_MAP()

// CMFCApplication42View 构造/析构

CMFCApplication42View::CMFCApplication42View()
{
	// TODO: 在此处添加构造代码
	BITMAP bm;
	b.LoadBitmapW(IDB_BITMAP1);
	b.GetBitmap(&bm);
	w = bm.bmWidth;
	h = bm.bmHeight;
}

CMFCApplication42View::~CMFCApplication42View()
{
}

BOOL CMFCApplication42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication42View 绘制

void CMFCApplication42View::OnDraw(CDC* pDC)
{
	CMFCApplication42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC M;
	M.CreateCompatibleDC(NULL);
	M.SelectObject(b);
	pDC->BitBlt(0, 0, w, h, &M, 0, 0, SRCCOPY);

}


// CMFCApplication42View 诊断

#ifdef _DEBUG
void CMFCApplication42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication42Doc* CMFCApplication42View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication42Doc)));
	return (CMFCApplication42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication42View 消息处理程序
