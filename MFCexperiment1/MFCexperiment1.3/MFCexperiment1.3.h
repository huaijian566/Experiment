
// MFCexperiment1.3.h : MFCexperiment1.3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCexperiment13App:
// �йش����ʵ�֣������ MFCexperiment1.3.cpp
//

class CMFCexperiment13App : public CWinApp
{
public:
	CMFCexperiment13App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCexperiment13App theApp;
