// MyDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication7.1.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog �Ի���

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
	, l(_T(""))
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, s);
	DDX_Text(pDX, IDC_EDIT6, l);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	//ON_EN_CHANGE(IDC_EDIT6, &MyDialog::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// MyDialog ��Ϣ�������




void MyDialog::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString w;
	this->UpdateData(true);
	w = s;
	s = l;
	l = w;
	this->UpdateData(false);
}
