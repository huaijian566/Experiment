
// MFCApplication2.1.h : MFCApplication2.1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication21App:
// �йش����ʵ�֣������ MFCApplication2.1.cpp
//

class CMFCApplication21App : public CWinApp
{
public:
	CMFCApplication21App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication21App theApp;
