
// DB11Set.cpp : CDB11Set ���ʵ��
//

#include "stdafx.h"
#include "DB11.h"
#include "DB11Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB11Set ʵ��

// ���������� 2020��5��5��, 21:32

IMPLEMENT_DYNAMIC(CDB11Set, CRecordset)

CDB11Set::CDB11Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDB11Set::GetDefaultConnect()
{
	return _T("DBQ=F:\\\x6000\x5065\\DOCUMENTS\\Database1.mdb;DefaultDir=F:\\\x6000\x5065\\DOCUMENTS;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=D:\\Documents\\\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CDB11Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CDB11Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);

}
/////////////////////////////////////////////////////////////////////////////
// CDB11Set ���

#ifdef _DEBUG
void CDB11Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB11Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

