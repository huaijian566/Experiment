#pragma once


// MDialog �Ի���

class MDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MDialog)

public:
	MDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString a;
	int b;
	CString c;
	afx_msg void OnBnClickedButton1();
};
