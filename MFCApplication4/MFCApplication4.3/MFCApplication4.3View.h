
// MFCApplication4.3View.h : CMFCApplication43View 类的接口
//

#pragma once


class CMFCApplication43View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication43View();
	DECLARE_DYNCREATE(CMFCApplication43View)

// 特性
public:
	CMFCApplication43Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHuaxian();
	afx_msg void OnHuajuxing();
	afx_msg void OnHuatuoyuan();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication4.3View.cpp 中的调试版本
inline CMFCApplication43Doc* CMFCApplication43View::GetDocument() const
   { return reinterpret_cast<CMFCApplication43Doc*>(m_pDocument); }
#endif

