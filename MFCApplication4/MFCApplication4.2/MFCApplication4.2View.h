
// MFCApplication4.2View.h : CMFCApplication42View 类的接口
//

#pragma once


class CMFCApplication42View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication42View();
	DECLARE_DYNCREATE(CMFCApplication42View)

// 特性
public:
	CMFCApplication42Doc* GetDocument() const;

// 操作
public:
	CBitmap b;
	int w,h;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication42View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication4.2View.cpp 中的调试版本
inline CMFCApplication42Doc* CMFCApplication42View::GetDocument() const
   { return reinterpret_cast<CMFCApplication42Doc*>(m_pDocument); }
#endif

