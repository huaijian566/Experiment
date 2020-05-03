
// MFCApplication1View.cpp : CMFCApplication1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCApplication1View ����/����

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View ����

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCApplication1View ���

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View ��Ϣ�������




void CMFCApplication1View::Onopen()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
