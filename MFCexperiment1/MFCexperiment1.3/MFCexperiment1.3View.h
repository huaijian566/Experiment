
// MFCexperiment1.3View.h : CMFCexperiment13View 类的接口
//

#pragma once


class CMFCexperiment13View : public CView
{
protected: // 仅从序列化创建
	CMFCexperiment13View();
	DECLARE_DYNCREATE(CMFCexperiment13View)

// 特性
public:
	CMFCexperiment13Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCexperiment13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCexperiment1.3View.cpp 中的调试版本
inline CMFCexperiment13Doc* CMFCexperiment13View::GetDocument() const
   { return reinterpret_cast<CMFCexperiment13Doc*>(m_pDocument); }
#endif

