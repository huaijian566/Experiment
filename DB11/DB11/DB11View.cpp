
// DB11View.cpp : CDB11View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DB11.h"
#endif

#include "DB11Set.h"
#include "DB11Doc.h"
#include "DB11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB11View

IMPLEMENT_DYNCREATE(CDB11View, CRecordView)

BEGIN_MESSAGE_MAP(CDB11View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDB11View 构造/析构

CDB11View::CDB11View()
	: CRecordView(IDD_DB11_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phoneNum(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CDB11View::~CDB11View()
{
}

void CDB11View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL CDB11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB11View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB11Set;
	CRecordView::OnInitialUpdate();

}


// CDB11View 打印

BOOL CDB11View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDB11View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDB11View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDB11View 诊断

#ifdef _DEBUG
void CDB11View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB11View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB11Doc* CDB11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB11Doc)));
	return (CDB11Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB11View 数据库支持
CRecordset* CDB11View::OnGetRecordset()
{
	return m_pSet;
}



// CDB11View 消息处理程序
