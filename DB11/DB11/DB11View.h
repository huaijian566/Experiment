
// DB11View.h : CDB11View 类的接口
//

#pragma once

class CDB11Set;

class CDB11View : public CRecordView
{
protected: // 仅从序列化创建
	CDB11View();
	DECLARE_DYNCREATE(CDB11View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB11_FORM };
#endif
	CDB11Set* m_pSet;

// 特性
public:
	CDB11Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDB11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString age;
	CString phoneNum;
};

#ifndef _DEBUG  // DB11View.cpp 中的调试版本
inline CDB11Doc* CDB11View::GetDocument() const
   { return reinterpret_cast<CDB11Doc*>(m_pDocument); }
#endif

