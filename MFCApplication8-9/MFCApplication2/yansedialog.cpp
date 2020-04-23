// yansedialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "yansedialog.h"
#include "afxdialogex.h"


// yansedialog 对话框

IMPLEMENT_DYNAMIC(yansedialog, CDialogEx)

yansedialog::yansedialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, r(0)
	, g(0)
	, b(0)
{

}

yansedialog::~yansedialog()
{
}

void yansedialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, r);
	DDX_Text(pDX, IDC_EDIT2, g);
	DDX_Text(pDX, IDC_EDIT3, b);
}


BEGIN_MESSAGE_MAP(yansedialog, CDialogEx)
END_MESSAGE_MAP()


// yansedialog 消息处理程序
