// MDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "MDialog.h"
#include "afxdialogex.h"


// MDialog �Ի���

IMPLEMENT_DYNAMIC(MDialog, CDialogEx)

MDialog::MDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(_T(""))
	, b(0)
	, c(_T(""))
{

}

MDialog::~MDialog()
{
}

void MDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
}


BEGIN_MESSAGE_MAP(MDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// MDialog ��Ϣ�������


void MDialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	CString s;
	s.Format(_T("%d"), b);
	c = a + s;
	UpdateData(false);
}
