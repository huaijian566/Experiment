
// MFCApplication7.1View.cpp : CMFCApplication71View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCApplication71View ����/����

CMFCApplication71View::CMFCApplication71View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication71View::~CMFCApplication71View()
{
}

BOOL CMFCApplication71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication71View ����

void CMFCApplication71View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCApplication71View ���

#ifdef _DEBUG
void CMFCApplication71View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication71Doc* CMFCApplication71View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication71Doc)));
	return (CMFCApplication71Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication71View ��Ϣ�������


void CMFCApplication71View::OnShowdialog()
{
	// TODO: �ڴ���������������
	MyDialog d;
	Invalidate();
	int t = d.DoModal();
	if (t == IDOK)
	{
		CString s =_T( "�����˳��Ի���");
		GetDC()->TextOutW(300, 300, s);
	}
}
