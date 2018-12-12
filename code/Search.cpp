// Search.cpp: файл реализации
//
#pragma once
#include "stdafx.h"
#include "Project_UNI.h"
#include "Search.h"
#include "afxdialogex.h"
using namespace std;

// диалоговое окно CSearch

IMPLEMENT_DYNAMIC(CSearch, CDialogEx)

CSearch::CSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSearch::IDD, pParent)
	, SearchEd1(_T(""))
	, SearchEd2(_T(""))
	, SearchEd3(_T(""))
	, SearchEd4(_T(""))
	, SearchEd5(_T(""))
{
	
}


CSearch::~CSearch()
{

}


void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, SearchEd1);
	DDX_Text(pDX, IDC_EDIT6, SearchEd2);
	DDX_Text(pDX, IDC_EDIT7, SearchEd3);
	DDX_Text(pDX, IDC_EDIT8, SearchEd4);
	DDX_Text(pDX, IDC_EDIT9, SearchEd5);
}


BEGIN_MESSAGE_MAP(CSearch, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений CSearch

void CSearch::DataUp()
{
	Inf.fname=SearchEd1;
	Inf.lname=SearchEd2;
	Inf.Secname=SearchEd3;
	Inf.Groupnumber=SearchEd4;
	Inf.Srball=SearchEd5;
}

bool CSearch::CheckForExp()
{
	bool flag;
	int tmp,_k1=100,_k2=100,_k3=100,_k4=100,_step=100;
	try
	{
		if(!Inf.fname.IsEmpty())
			 _k1=InpStringExp(Inf.fname);
		if(!Inf.lname.IsEmpty())
			 _k2=InpStringExp(Inf.lname);
		if(!Inf.Secname.IsEmpty())
			 _k3=InpStringExp(Inf.Secname);
		if(!Inf.Groupnumber.IsEmpty())
			 _k4=InpDoublExp(Inf.Groupnumber);
		if(!Inf.Srball.IsEmpty())
			 _step=InpDoublExp(Inf.Srball);
		if(_k1!=100 || _k2!=100 || _k3!=100 || _k4!=100 || _step!=100)
			throw InputExeptions(6);
	}
	catch(InputExeptions &e)
	{
		e.ErrorDescr();
		return false;
	}

	return true;
}

bool CSearch::Check(vector<int> temp,int check)
{
	for(int i=0;i<temp.size();i++)
	{
		if(temp[i]==check)
			return true;
	}

	return false;
}

void CSearch::SearchFun(Queue<Student> *tmp,vector<int>* SearchRez)
{
	int contrl=1;
	if(!(*SearchRez).empty())
		(*SearchRez).clear();

	for(Queue<Student>::Iterator iter = (*tmp).Begin();iter != (*tmp).End();iter++,contrl++)
	{
		if(!Inf.fname.IsEmpty())
			if(iter.ptr->node.fname==Inf.fname)
				if(!Check((*SearchRez),contrl))
					(*SearchRez).push_back(contrl);
		if(!Inf.lname.IsEmpty())
			if(iter.ptr->node.lname==Inf.lname)
				if(!Check((*SearchRez),contrl))
					(*SearchRez).push_back(contrl);
		if(!Inf.Secname.IsEmpty())
			if(iter.ptr->node.Secname==Inf.Secname)
				if(!Check((*SearchRez),contrl))
					(*SearchRez).push_back(contrl);
		if(!Inf.Groupnumber.IsEmpty())
			if(iter.ptr->node.Groupnumber==Inf.Groupnumber)
				if(!Check((*SearchRez),contrl))
					(*SearchRez).push_back(contrl);
		if(!Inf.Srball.IsEmpty())
			if(iter.ptr->node.Srball==Inf.Srball)
				if(!Check((*SearchRez),contrl))
					(*SearchRez).push_back(contrl);
	}
}