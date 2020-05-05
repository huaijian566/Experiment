
// DB11View.h : CDB11View ��Ľӿ�
//

#pragma once

class CDB11Set;

class CDB11View : public CRecordView
{
protected: // �������л�����
	CDB11View();
	DECLARE_DYNCREATE(CDB11View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB11_FORM };
#endif
	CDB11Set* m_pSet;

// ����
public:
	CDB11Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDB11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString age;
	CString phoneNum;
};

#ifndef _DEBUG  // DB11View.cpp �еĵ��԰汾
inline CDB11Doc* CDB11View::GetDocument() const
   { return reinterpret_cast<CDB11Doc*>(m_pDocument); }
#endif

