
// MFCexperiment1.2.h : MFCexperiment1.2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCexperiment12App:
// �йش����ʵ�֣������ MFCexperiment1.2.cpp
//

class CMFCexperiment12App : public CWinApp
{
public:
	CMFCexperiment12App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCexperiment12App theApp;
