
// MFCApplication4.1View.cpp : CMFCApplication41View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCApplication41View ����/����

CMFCApplication41View::CMFCApplication41View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication41View::~CMFCApplication41View()
{
}

BOOL CMFCApplication41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication41View ����

void CMFCApplication41View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCApplication41View ���

#ifdef _DEBUG
void CMFCApplication41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication41Doc* CMFCApplication41View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication41Doc)));
	return (CMFCApplication41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication41View ��Ϣ�������


void CMFCApplication41View::OnShowname()
{
	// TODO: �ڴ���������������
	CString s = _T("�ƾ��");
	CClientDC dc(this);
	dc.TextOutW(200,200,s);
}
