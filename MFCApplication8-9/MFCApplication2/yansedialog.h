#pragma once


// yansedialog �Ի���

class yansedialog : public CDialogEx
{
	DECLARE_DYNAMIC(yansedialog)

public:
	yansedialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~yansedialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int r;
	int g;
	int b;
};
