#pragma once
#include "MyGridWnd.h"
#include "Project_UNI.h"
#include "Queue.h"
#include <vector>
#include "KStruct.h"
#include "Redact_k.h"
using namespace std;
// диалоговое окно CRedactDialog

class CRedactDialog : public CDialog
{
	DECLARE_DYNAMIC(CRedactDialog)
	int Rwcount; 
	int ChechNum;
	Queue<Student> StInf;
	StepK Kstr;
	vector<int> SearchRez;
	bool flag_k,flag_In,check;
	//Queue<Student> StInf;

public:
	CRedactDialog(CWnd* pParent = NULL);
	CRedactDialog(vector<CString>,int,CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CRedactDialog();

// Данные диалогового окна
	enum { IDD = IDD_REDACT };


protected:
	virtual void DoDataExchange(CDataExchange* pDX); 
	virtual BOOL OnInitDialog();// поддержка DDX/DDV
	void GridRowColSet();
	bool ReadFromRowCol();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab2(NMHDR *pNMHDR, LRESULT *pResult);
	CMyGridWnd m_wndGrid;
	afx_msg void OnBnClickedAddRow();
	afx_msg void OnBnClickedDeleteRow();
	afx_msg void OnBnClickedRaschet();
	afx_msg void OnBnClickedSave();
	
	CString SymbPrinting(vector<CString>);
	bool Chek(vector<CString>);
	bool Chek(vector<double>);
	bool CheckForEXp();
	void ExpSwitch(int,int);
	friend int InpStringExp(CString );
	friend int InpDoublExp(CString  );
	afx_msg void OnBnClickedRedact_k();
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnFind();
};
