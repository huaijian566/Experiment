
// MFCexperiment1.2View.h : CMFCexperiment12View 类的接口
//

#pragma once


class CMFCexperiment12View : public CView
{
protected: // 仅从序列化创建
	CMFCexperiment12View();
	DECLARE_DYNCREATE(CMFCexperiment12View)

// 特性
public:
	CMFCexperiment12Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCexperiment12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCexperiment1.2View.cpp 中的调试版本
inline CMFCexperiment12Doc* CMFCexperiment12View::GetDocument() const
   { return reinterpret_cast<CMFCexperiment12Doc*>(m_pDocument); }
#endif

