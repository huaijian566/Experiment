
// MFCApplication7.1.h : MFCApplication7.1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication71App:
// �йش����ʵ�֣������ MFCApplication7.1.cpp
//

class CMFCApplication71App : public CWinApp
{
public:
	CMFCApplication71App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication71App theApp;
