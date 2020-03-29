
// MFCApplication4.1View.h : CMFCApplication41View 类的接口
//

#pragma once


class CMFCApplication41View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication41View();
	DECLARE_DYNCREATE(CMFCApplication41View)

// 特性
public:
	CMFCApplication41Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFCApplication4.1View.cpp 中的调试版本
inline CMFCApplication41Doc* CMFCApplication41View::GetDocument() const
   { return reinterpret_cast<CMFCApplication41Doc*>(m_pDocument); }
#endif

