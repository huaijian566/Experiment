
// MFCApplication4.2.h : MFCApplication4.2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication42App:
// �йش����ʵ�֣������ MFCApplication4.2.cpp
//

class CMFCApplication42App : public CWinApp
{
public:
	CMFCApplication42App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication42App theApp;
