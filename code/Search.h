#pragma once
#include "Queue.h"
#include <vector>
#include "KStruct.h"
#include "InputExeptions.h"
using namespace std;

// диалоговое окно CSearch

class CSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CSearch)

public:
	CSearch(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CSearch();
	void DataUp();
	bool CheckForExp();
	bool Check(vector<int>,int);
	friend int InpStringExp(CString );
	friend int InpDoublExp(CString  );
	void SearchFun(Queue<Student>*,vector<int>*);
	friend class CRedactDialog;
// Данные диалогового окна
	enum { IDD = IDD_SEARCH_DIALOG};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	CString SearchEd1;
	CString SearchEd2;
	CString SearchEd3;
	CString SearchEd4;
	CString SearchEd5;
	Search Inf;
};
