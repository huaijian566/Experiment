
// MFCexperiment1.h : MFCexperiment1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCexperiment1App:
// �йش����ʵ�֣������ MFCexperiment1.cpp
//

class CMFCexperiment1App : public CWinApp
{
public:
	CMFCexperiment1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCexperiment1App theApp;
