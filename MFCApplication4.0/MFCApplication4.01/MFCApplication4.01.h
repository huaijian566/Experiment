
// MFCApplication4.01.h : MFCApplication4.01 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication401App:
// �йش����ʵ�֣������ MFCApplication4.01.cpp
//

class CMFCApplication401App : public CWinApp
{
public:
	CMFCApplication401App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication401App theApp;
