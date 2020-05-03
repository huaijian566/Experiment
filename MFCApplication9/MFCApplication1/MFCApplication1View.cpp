
// MFCApplication1View.cpp : CMFCApplication1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	//ON_COMMAND(ID_FILE_OPEN, &CMFCApplication1View::OnFileOpen)
	ON_COMMAND(ID_open, &CMFCApplication1View::Onopen)
	ON_COMMAND(ID_FILE_SAVE, &CMFCApplication1View::OnFileSave)
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 绘制

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 消息处理程序




void CMFCApplication1View::Onopen()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication1Doc* pDoc = GetDocument();
	CFileDialog f(true);
	int r = f.DoModal();
	CClientDC dc(this);
	if (r == IDOK)
	{
	  pDoc-> filename = f.GetPathName();
		ifstream ifs(pDoc->filename);
		dc.TextOutW(200, 200, pDoc->filename);

	}
}


void CMFCApplication1View::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication1Doc* pDoc = GetDocument();
	CFileDialog f2(false);
	int r = f2.DoModal();
	if (r == IDOK)
	{
		ofstream ofs (f2.GetPathName());
		CString s = pDoc->filename;
		ofs <<CT2A(s.GetString()) << endl;
	}
}
