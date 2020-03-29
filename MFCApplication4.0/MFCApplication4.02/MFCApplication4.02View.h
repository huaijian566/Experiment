
// MFCApplication4.02View.h : CMFCApplication402View 类的接口
//

#pragma once


class CMFCApplication402View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication402View();
	DECLARE_DYNCREATE(CMFCApplication402View)

// 特性
public:
	CMFCApplication402Doc* GetDocument() const;

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
	virtual ~CMFCApplication402View();
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

#ifndef _DEBUG  // MFCApplication4.02View.cpp 中的调试版本
inline CMFCApplication402Doc* CMFCApplication402View::GetDocument() const
   { return reinterpret_cast<CMFCApplication402Doc*>(m_pDocument); }
#endif

