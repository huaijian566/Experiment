
// MFCApplication4.1.h : MFCApplication4.1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication41App:
// �йش����ʵ�֣������ MFCApplication4.1.cpp
//

class CMFCApplication41App : public CWinApp
{
public:
	CMFCApplication41App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication41App theApp;
