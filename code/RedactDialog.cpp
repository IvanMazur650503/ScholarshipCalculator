// RedactDialog.cpp: файл реализации
//
#pragma once
#include "stdafx.h"
#include "Project_UNI.h"
#include "RedactDialog.h"
#include "afxdialogex.h"
#include "MyGridWnd.h"
#include "InputExeptions.h"
#include "Step.h"
#include <afx.h>
#include "Search.h"
#include <string>
#include "InputExeptions.h"




// диалоговое окно CRedactDialog

IMPLEMENT_DYNAMIC(CRedactDialog, CDialog)

CRedactDialog::CRedactDialog(vector<CString> StudentInf,int size,CWnd* pParent /*=NULL*/)
	: CDialog(CRedactDialog::IDD, pParent)
{
	Student tmp;
	for(int i=0;i<StudentInf.size();i+=6)
	{
		
		tmp.fname=StudentInf[i];
		tmp.lname=StudentInf[i+1];
		tmp.Secname=StudentInf[i+2];
		tmp.Groupnumber=StudentInf[i+3];
		tmp.Srball=StudentInf[i+4];
		tmp.nadbavka=StudentInf[i+5];
		if(StudentInf[i+6].IsEmpty())
			{
				tmp.Step='\0';i++;}
		else
		{
			tmp.Step=StudentInf[i+6];
			i++;
		}
		StInf.Push(tmp);
	}
	flag_k=false;
	flag_In=false;
	ChechNum=Rwcount=size;
}


CRedactDialog::CRedactDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CRedactDialog::IDD, pParent)
{

	flag_In=true;
	flag_k=false;
	check=false;	
	ChechNum=Rwcount=5;
}


CRedactDialog::~CRedactDialog()
{
}

void CRedactDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRedactDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CRedactDialog::OnBnClickedSave)
	ON_COMMAND(ID_ADD_ROW, &CRedactDialog::OnBnClickedAddRow )
	ON_COMMAND(ID_FILE_SAVE, &CRedactDialog::OnBnClickedSave )
	ON_COMMAND(ID_DELETE_ROW, &CRedactDialog::OnBnClickedDeleteRow)
	ON_COMMAND(ID_RASCHET, &CRedactDialog::OnBnClickedRaschet)
	ON_COMMAND(ID_REDACT_K, &CRedactDialog::OnBnClickedRedact_k)
	ON_COMMAND(ID_REFRESH, &CRedactDialog::OnBnClickedRefresh)
	ON_COMMAND(ID_FIND, &CRedactDialog::OnFind)
END_MESSAGE_MAP()


// обработчики сообщений CRedactDialog

BOOL CRedactDialog :: OnInitDialog () 
{
	CDialog :: OnInitDialog ();

	// Пожалуйста, обратитесь к документации MFC по
	// SubclassDlgItem для получения информации об этом вызове. Эта
	// убедитесь, что наша C ++-сетка 
	// класс окна подклассы создаваемого окна 
	// с помощью User Control.
	m_wndGrid.SubclassDlgItem (IDC_CUSTOM_GRID, this);

	// Инициализация сетки. Для сетей на основе CWnd этот вызов
	// существенный. Для сеток, основанных на представлении, эта инициализация
	// сделано в OnInitialUpdate.
	m_wndGrid.Initialize ();

	m_wndGrid.GetParam () -> EnableUndo (FALSE);

	m_wndGrid.SetRowCount (Rwcount);
	m_wndGrid.SetColCount (7);


	m_wndGrid.SetStyleRange(CGXRange(0,1),CGXStyle().SetValue("Фамилия") );
	m_wndGrid.SetStyleRange(CGXRange(0,2),CGXStyle().SetValue("Имя"));
	m_wndGrid.SetStyleRange(CGXRange(0,3),CGXStyle().SetValue("Отчество"));
	m_wndGrid.SetStyleRange(CGXRange(0,4),CGXStyle().SetValue("Группа"));
	m_wndGrid.SetStyleRange(CGXRange(0,5),CGXStyle().SetValue("Средний балл"));
	m_wndGrid.SetStyleRange(CGXRange(0,6),CGXStyle().SetValue("Надбавка"));
	m_wndGrid.SetStyleRange(CGXRange(0,7),CGXStyle().SetValue("Степендия"));




	m_wndGrid.GetParam () -> EnableUndo (TRUE);

	if(!flag_In)
		GridRowColSet();
	return TRUE; // возвращаем TRUE, если вы не установили
	// сосредоточиться на контроле
	// ИСКЛЮЧЕНИЕ: Страницы свойств OCX должны возвращать FALSE
}

void CRedactDialog::OnBnClickedAddRow()
{

	Rwcount++;
	m_wndGrid.SetRowCount (Rwcount);
}

void CRedactDialog::OnBnClickedDeleteRow()
{
	try
	{
		Rwcount--;
		if(Rwcount<ChechNum)
		{
			throw InputExeptions(5);Rwcount++;
		}
		m_wndGrid.SetRowCount (Rwcount);
	}
	catch(InputExeptions &exp)
	{
		exp.ErrorDescr();
		return;
	}
}

bool CRedactDialog::CheckForEXp()
{
		int size,tmp;
		bool flag=false;
		Queue<Student>::Iterator iter=StInf.Begin();
		for(size=0;iter!=StInf.End();size++,iter++)
		{
		}
	
		for(int i=1;i<=size;i++) 
			for(int j=1;j<7;j++)
			{
				if(j>=1 && j<=3)
				{
					tmp=InpStringExp(m_wndGrid.GetValueRowCol(i,j));
					if(tmp!=100)
					{
						flag=true;
						ExpSwitch(tmp,j);
					}
				}
				else
				{
					tmp=InpDoublExp(m_wndGrid.GetValueRowCol(i,j));
					if(tmp!=100)
					{
						flag=true;
						ExpSwitch(tmp,j);
					}
				}
			}

			return flag;	
}

void CRedactDialog::ExpSwitch(int ch,int colnum)
{
	if(colnum>=1 && colnum<=3)
		switch(ch)
	{;
		case 1: {try{
			throw InputExeptions(1);
				}
				catch(InputExeptions &e)
				{
					e.ErrorDescr();
					break;
				}
				};
		case 0:{try{
			throw InputExeptions(0);
			   }
			   catch(InputExeptions &e)
			   {
				   e.ErrorDescr();
				   break;
			   }
			   };
	};
	if(colnum==4)
		switch(ch)
	{
		case 0:{try{
			throw InputExeptions(0);
			   }
			   catch(InputExeptions &e)
			   {
				   e.ErrorDescr();
				   break;
			   }
			   };
		case 1:{try{
			throw InputExeptions(2);
			   }
			   catch(InputExeptions &e)
			   {
				   e.ErrorDescr();
				   break;
			   }
			   };
	};
	if(colnum==5 || colnum==6)
		switch(ch)
	{
		case 0:{try{
			throw InputExeptions(0);
			   }
			   catch(InputExeptions &e)
			   {
				   e.ErrorDescr();
				   break;
			   }
			   };
		case 1:{try{
			throw InputExeptions(3);
			   }
			   catch(InputExeptions &e)
			   {
				   e.ErrorDescr();
				   break;
			   }
			   };
	};
}

void CRedactDialog::OnBnClickedRaschet()
{
	CStep obj1;
	CStep obj2(Kstr.K1,Kstr.K2,Kstr.K3,Kstr.K4,Kstr.stepend);

	if(flag_In && !check)
		check=ReadFromRowCol();

	if(CheckForEXp())
	{
		StInf.Clear();
		ReadFromRowCol();
		GridRowColSet();
		return;
	}
	else
	{
		StInf.Clear();
		ReadFromRowCol();
	}
	Queue<Student>::Iterator iter=StInf.Begin();

	for(;iter != StInf.End();iter++)
	{
		struct Student tmp=*iter;
		if(flag_k)
			tmp.Step=obj2.Raschet(atof(tmp.nadbavka),atof(tmp.Srball));
		else
			tmp.Step=obj1.Raschet(atof(tmp.nadbavka),atof(tmp.Srball));
		
		
		iter.ptr->node.Step=tmp.Step;
	}
	
	GridRowColSet();
}

void CRedactDialog::GridRowColSet()
{
	int l =1;
	Queue<Student>::Iterator iter=StInf.Begin();
	if(StInf.GetSize()!=0){
	for(;iter != StInf.End();iter++)
	{
		struct Student tmp=*iter;

		m_wndGrid.SetStyleRange(CGXRange(l,1),CGXStyle().SetValue(tmp.fname));
		m_wndGrid.SetStyleRange(CGXRange(l,2),CGXStyle().SetValue(tmp.lname));
		m_wndGrid.SetStyleRange(CGXRange(l,3),CGXStyle().SetValue(tmp.Secname));
		m_wndGrid.SetStyleRange(CGXRange(l,4),CGXStyle().SetValue(tmp.Groupnumber));
		m_wndGrid.SetStyleRange(CGXRange(l,5),CGXStyle().SetValue(tmp.Srball));
		m_wndGrid.SetStyleRange(CGXRange(l,6),CGXStyle().SetValue(tmp.nadbavka));
		if(tmp.Step)
			m_wndGrid.SetStyleRange(CGXRange(l,7),CGXStyle().SetValue(tmp.Step));
		l++;
	}
	Rwcount=l;
	m_wndGrid.SetRowCount (Rwcount);
	}
}

bool CRedactDialog::ReadFromRowCol()
{
	vector<CString> buff;
	Student tmp;
	for(int i=1;i<=Rwcount;i++)
	{
		buff.clear();
		buff.push_back(tmp.fname=(m_wndGrid.GetValueRowCol(i,1)));
		buff.push_back(tmp.lname=(m_wndGrid.GetValueRowCol(i,2)));
		buff.push_back(tmp.Secname=(m_wndGrid.GetValueRowCol(i,3)));
		buff.push_back(tmp.Groupnumber=(m_wndGrid.GetValueRowCol(i,4)));
		buff.push_back(tmp.Srball=(m_wndGrid.GetValueRowCol(i,5)));
		buff.push_back(tmp.nadbavka=(m_wndGrid.GetValueRowCol(i,6)));
		buff.push_back(tmp.Step=(m_wndGrid.GetValueRowCol(i,7)));
		if(!Chek(buff))
			continue;
		StInf.Push(tmp);
	};
	try
	{
	if(StInf.GetSize()==0)
		throw InputExeptions(7);
	}
	catch(InputExeptions &e)
	{
		e.ErrorDescr();
		return false;
	}
	return true;
}

void CRedactDialog::OnBnClickedSave()
{
	if(flag_In && !check)
	{
		check=ReadFromRowCol();
		if(!check)
			return;
	}
	if(CheckForEXp())
	{
		OnBnClickedRefresh();
		return;
	}
	else
	{
		StInf.Clear();
		if(!ReadFromRowCol())
			return;
	}

	vector<CString> buff;
	vector<CString> buffer;
	for(int i=1;i<=Rwcount;i++)
	{
	buff.clear();
	buff.push_back(m_wndGrid.GetValueRowCol(i,1));
	buff.push_back(m_wndGrid.GetValueRowCol(i,2));
	buff.push_back(m_wndGrid.GetValueRowCol(i,3));
	buff.push_back(m_wndGrid.GetValueRowCol(i,4));
	buff.push_back(m_wndGrid.GetValueRowCol(i,5));
	buff.push_back(m_wndGrid.GetValueRowCol(i,6));
	buff.push_back(m_wndGrid.GetValueRowCol(i,7));
	if(!Chek(buff))
		continue;
	buffer.push_back(SymbPrinting(buff));
	};

	CDialog::OnOK();

	CFileDialog dl(FALSE,NULL,(LPCSTR)".txt",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | WS_VISIBLE | DS_CENTER,(LPCSTR)"Текстовый документ (*.txt)|*.txt|");

	if(dl.DoModal()==IDOK)
	{

		CStdioFile File;
		try
		{
			File.Open(dl.GetPathName(),CFile::modeCreate | CFile::modeWrite);
		}
		catch(CFileException* pe)
		{
			AfxMessageBox("File could not be opened, cause = %d\n",pe->m_cause);
			pe->Delete();
			return;
		};
		
		for(int i=0;i<buffer.size();i++)
		{
			File.Write(buffer[i],strlen(buffer[i]));
			File.Write("\n",1);
		}

		File.Close();
	}
	StInf.Clear();
}

bool CRedactDialog::Chek(vector<CString> Buff)
{
	bool flag=false;
	for(int i=0;i<Buff.size();i++)
	{
		if(Buff[i].IsEmpty())
			flag=true;
		if(flag)
			continue;
		else
			return true;
	}
	return false;
}

bool CRedactDialog::Chek(vector<double> Buff)
{
	bool flag=false;
	for(int i=0;i<Buff.size();i++)
	{
		if(Buff[i]==0)
			flag=true;
		else
			flag=false;
		if(flag)
			continue;
		else
			return true;
	}
	return false;
}

CString CRedactDialog::SymbPrinting(vector<CString> RowColInf)
{
	vector<CString> temp;
	CString str;
	string  rez=RowColInf[0].GetBuffer();
	//int j=rez.length();

	for(int i=1;i<RowColInf.size();i++)
	{
		rez+='-';
		rez+=RowColInf[i].GetBuffer();
		//j=rez.length();
	}
	rez+=';';
	str=rez.c_str();
	return str;
}

void CRedactDialog::OnBnClickedRedact_k()
{
	CRedact_k dlg;
	vector<double> buff;
	do {
	if(dlg.DoModal()==IDOK)
	{
		buff.push_back(Kstr.K1=atof(dlg.Edit_k1));
		buff.push_back(Kstr.K2=atof(dlg.Edit_k2));
		buff.push_back(Kstr.K3=atof(dlg.Edit_k3));
		buff.push_back(Kstr.K4=atof(dlg.Edit_k4));
		buff.push_back(Kstr.stepend=atof(dlg.Edit_step));
		if(!Chek(buff))
			continue;
		flag_k=true;
	}
	}while(!dlg.CheckForExp(Kstr));
}

void CRedactDialog::OnBnClickedRefresh()
{
	StInf.Clear();
	ReadFromRowCol();
	GridRowColSet();
}

void CRedactDialog::OnFind()
{
	CSearch dlg;
	vector<double> buff;
	if(dlg.DoModal()==IDOK)
	{
		do 
		{
			dlg.DataUp();	
			if(dlg.CheckForExp())
				break;
			else
				return;
		}while(1);

		dlg.SearchFun(&StInf,&SearchRez);

		if(SearchRez.empty())
		{
			if(IDOK==AfxMessageBox(_T("Совпадений нет!")))
				return;
		}
		ROWCOL a,b;
		for(int i=0;i<SearchRez.size();i++)
		{
			a=SearchRez[i];
			for(int j=1;j<=7;j++)
			{
				b=j;
				m_wndGrid.SelectRange(CGXRange(a,j),true);
			}	
		}
	}
}

