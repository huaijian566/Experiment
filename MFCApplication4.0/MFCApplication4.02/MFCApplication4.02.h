
// MFCApplication4.02.h : MFCApplication4.02 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication402App:
// �йش����ʵ�֣������ MFCApplication4.02.cpp
//

class CMFCApplication402App : public CWinApp
{
public:
	CMFCApplication402App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication402App theApp;
