// Dialog1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "Dialog1.h"
#include "afxdialogex.h"


// Dialog1 对话框

IMPLEMENT_DYNAMIC(Dialog1, CDialogEx)

Dialog1::Dialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, l(0)
	, d(0)
	, x(0)
	, y(0)
{

}

Dialog1::~Dialog1()
{
}

void Dialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, l);
	DDX_Text(pDX, IDC_EDIT2, d);
	DDX_Text(pDX, IDC_EDIT3, x);
	DDX_Text(pDX, IDC_EDIT4, y);
}


BEGIN_MESSAGE_MAP(Dialog1, CDialogEx)
END_MESSAGE_MAP()


// Dialog1 消息处理程序
