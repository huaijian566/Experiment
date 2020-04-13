
// MFCApplication7.1View.h : CMFCApplication71View 类的接口
//

#pragma once


class CMFCApplication71View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication71View();
	DECLARE_DYNCREATE(CMFCApplication71View)

// 特性
public:
	CMFCApplication71Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication71View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowdialog();
};

#ifndef _DEBUG  // MFCApplication7.1View.cpp 中的调试版本
inline CMFCApplication71Doc* CMFCApplication71View::GetDocument() const
   { return reinterpret_cast<CMFCApplication71Doc*>(m_pDocument); }
#endif

