// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MyDialog.h"
#include "afxdialogex.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()



/*void MyDialog::foo(CImage& img, int &sx, int &sy, int &w, int &h)
{
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
}*/


// MyDialog 消息处理程序


void MyDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog f(true);
	int r = f.DoModal();
	CClientDC dc(this);
	if (r == IDOK)
	{
		CString filename = f.GetPathName();
		ifstream ifs(filename);
		string s;
		//CString ss;
		while (ifs >> s)
		{
			//ss+= CString(s.c_str());
			CImage img;
			img.Load(CString(s.c_str()));
			CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
			//pDC->SetStretchBltMode(HALFTONE);
			//img.Draw(pDC->m_hDC, sx, sy, w, h);
			img.Draw(GetDC()->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
			ReleaseDC(pDC);
		}
			
			/*int w, h, sx, sy;
	//foo(img, sx, sy, w, h);

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
			}*/

			//CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
			//pDC->SetStretchBltMode(HALFTONE);
			//img.Draw(pDC->m_hDC, sx, sy, w, h);
			//img.Draw(dc.m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
			//ReleaseDC(pDC);
	}
	/*ifstream ifs(_T("F:\abc.txt"));
	 string s;
	// ifs >> s;
	 CString ss;
	 while (ifs >> s)
	 {
	 ss+= CString(s.c_str());
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
	 //img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(),img.GetHeight());
	 //pDC->SetStretchBltMode(HALFTONE);
	 img.Draw(pDC->m_hDC, sx, sy, w, h);
	// ReleaseDC(pDC);*/
}
