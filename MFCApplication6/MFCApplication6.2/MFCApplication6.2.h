
// MFCApplication6.2.h : MFCApplication6.2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication62App:
// �йش����ʵ�֣������ MFCApplication6.2.cpp
//

class CMFCApplication62App : public CWinApp
{
public:
	CMFCApplication62App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication62App theApp;
