// Redact_k.cpp: файл реализации
//
#pragma once
#include "stdafx.h"
#include "Project_UNI.h"
#include "Redact_k.h"
#include "afxdialogex.h"
#include "Step.h"
#include "KStruct.h"

// диалоговое окно Redact_k

IMPLEMENT_DYNAMIC(CRedact_k, CDialogEx)

CRedact_k::CRedact_k(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRedact_k::IDD, pParent)
	, Edit_k1(_T(""))
	, Edit_k2(_T(""))
	, Edit_k3(_T(""))
	, Edit_k4(_T(""))
	, Edit_step(_T(""))
{
	
	
}


CRedact_k::~CRedact_k()
{
}

void CRedact_k::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITK1, Edit_k1);
	DDX_Text(pDX, IDC_EDIT3, Edit_k2);
	DDX_Text(pDX, IDC_EDIT2, Edit_k3);
	DDX_Text(pDX, IDC_EDIT4, Edit_k4);
	DDX_Text(pDX, IDC_EDIT5, Edit_step);
}


BEGIN_MESSAGE_MAP(CRedact_k, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений Redact_k


bool CRedact_k::CheckForExp(struct StepK temp)
{
	bool flag;
	int tmp;
	try
	{
	int _k1=InpDoublExp(Edit_k1);
	int _k2=InpDoublExp(Edit_k2);
	int _k3=InpDoublExp(Edit_k3);
	int _k4=InpDoublExp(Edit_k4);
	int _step=InpDoublExp(Edit_step);
	if(_k1!=100 || _k2!=100 || _k3!=100 || _k4!=100 || _step!=100)
		throw InputExeptions(4);
	}
	catch(InputExeptions &e)
	{
		e.ErrorDescr();
		return false;
	}

	return true;
}