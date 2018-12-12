#pragma once
#include "KStruct.h"
#include "InputExeptions.h"

// ���������� ���� Redact_k

class CRedact_k : public CDialogEx
{
	DECLARE_DYNAMIC(CRedact_k)

public:
	CRedact_k(CWnd* pParent = NULL);   // ����������� �����������
	CRedact_k(double,double,double,double,CWnd* pParent = NULL);

	virtual ~CRedact_k();

// ������ ����������� ����
	enum { IDD = IDD_REDACT_K };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV
	
	DECLARE_MESSAGE_MAP()
public:
	CString Edit_k1;
	CString Edit_k2;
	CString Edit_k3;
	CString Edit_k4;
	CString Edit_step;
	bool CheckForExp(struct StepK);
	friend int InpStringExp(CString );
	friend int InpDoublExp(CString  );
};
