
// MFCApplication4.01View.h : CMFCApplication401View 类的接口
//

#pragma once


class CMFCApplication401View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication401View();
	DECLARE_DYNCREATE(CMFCApplication401View)

// 特性
public:
	CMFCApplication401Doc* GetDocument() const;

// 操作
public:
	bool set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication401View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHuayuan();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCApplication4.01View.cpp 中的调试版本
inline CMFCApplication401Doc* CMFCApplication401View::GetDocument() const
   { return reinterpret_cast<CMFCApplication401Doc*>(m_pDocument); }
#endif

