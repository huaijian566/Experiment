// Dialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "Dialog.h"
#include "afxdialogex.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// Dialog 对话框

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// Dialog 消息处理程序


void Dialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ifstream ifs("F:\abc.txt");
	string s;
	// ifs >> s;
	CString ss;
	while (ifs >> s)
	{
		ss += CString(s.c_str());
	}
	CImage img;
	img.Load(ss);
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}

	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(),img.GetHeight());
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
