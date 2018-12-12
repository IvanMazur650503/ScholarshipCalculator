
// Project_UNIDlg.cpp : файл реализации
//
#pragma once
#include "stdafx.h"
#include "Project_UNI.h"
#include "Project_UNIDlg.h"
#include "afxdialogex.h"
#include "RedactDialog.h"
#include "Redact_k.h"
#include "Queue.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CProject_UNIDlg




CProject_UNIDlg::CProject_UNIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProject_UNIDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProject_UNIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProject_UNIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDS_ABOUTBOX, &CProject_UNIDlg::OnAboutbox)
	ON_COMMAND(ID_FILE_NEW, &CProject_UNIDlg::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CProject_UNIDlg::OnFileOpen)
END_MESSAGE_MAP()


// обработчики сообщений CProject_UNIDlg

BOOL CProject_UNIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CProject_UNIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CProject_UNIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CProject_UNIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CProject_UNIDlg::OnFileNew()
{
	// TODO: добавьте свой код обработчика команд

	CRedactDialog dlg;

	dlg.DoModal();
}


void CProject_UNIDlg::OnFileOpen()
{
	// TODO: добавьте свой код обработчика команд
	CString m_Text;
	int i=0,j=0;
	CFileDialog fd(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT| WS_VISIBLE | DS_CENTER, NULL);
	CStdioFile File;
	
	if(fd.DoModal() == IDOK)
	{
		
		try
		{
			File.Open(fd.GetPathName(), CFile :: modeReadWrite  ) ;
		}
		catch(CFileException* pe)
		{
			AfxMessageBox("File could not be opened, cause = %d\n",pe->m_cause);
			pe->Delete();
			return;
		}
		
			if(File.GetLength()== NULL)
			{
				AfxMessageBox("ERROR TO OPEN THE FILE.TRY AGAIN");
				File.Close();
				return;
			}
			
			do{

				CString& ref=m_Text;
				if(!File.ReadString(ref)) break;
				buff.push_back(m_Text);i++;

			}while(1);

			File.Close();	

		int size=buff.size();

		for(int i=0;i<buff.size();i++)
		{
			char* tmp=buff[i].GetBuffer();
			SymbReading(tmp);
		}
		buff.clear();

		CRedactDialog dlg(StudentInf,size);

		StudentInf.clear();
		dlg.DoModal();
	}


}

//void CProject_UNIDlg::OnFileSaveAs()
//{
//	// TODO: добавьте свой код обработчика команд
//	CFileDialog dl(FALSE,NULL,(LPCSTR)".txt",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | WS_VISIBLE | DS_CENTER,(LPCSTR)"Текстовый документ (*.txt)|*.txt|");
//
//	if(dl.DoModal()==IDOK)
//	{
//		CStdioFile File;
//		File.Open(dl.GetPathName(),CFile::modeCreate | CFile::modeWrite);
//		File.Close();
//	}
//	
//}

void CProject_UNIDlg::SymbReading(char* str)
{
	char* arr=str;
	CString cstr="";
	int i=0,j=0,n1=0,flag=0,length;
	length=strlen(arr);

	for(i;i<length+1; i++)
	{
		if((*(arr+i)>='А' && *(arr+i)<='Я') || (*(arr+i)>='а' && *(arr+i)<='я'))
		{
			n1=i;j=i+1;
			do {

				if(*(arr+j)=='\0') {flag=1;break;}
				if(*(arr+j)=='-' || *(arr+j)==',' || *(arr+j)==';' || *(arr+j)==' ') break;
				j++;
			}while(1);
			if(!flag)
				i=leksema(j,n1,arr);
		}

		if(*(arr+i)<57 && *(arr+i)>=48)
		{
			n1=i;j=i;
			do
			{
				j++;
				if(*(arr+j)=='\0') 
				{j--;break;}
				if(*(arr+j)=='-' || *(arr+j)==',' || *(arr+j)==';' || *(arr+j)==' ') break;
			}while(1);

			i=leksema(j,n1,arr);
		}
		if((*(arr+i)=='-' && *(arr+i+1)==';') || (*(arr+i)==' ' && *(arr+i+1)==';') || (*(arr+i)==';' && *(arr+i+1)==';') || (*(arr+i)==',' && *(arr+i+1)==';'))
			StudentInf.push_back(cstr);
	}
}

int CProject_UNIDlg::leksema(int j,int n1,char* arr)
{
	int n2=0,x=0;
	char* rez;
	n2=j;
	if((n2-n1+1)==1) return n2+1;
	rez=(char*)calloc(n2-n1,sizeof(char));
	while(n1<n2)
	{
		*(rez+x)=*(arr+n1);n1++;x++;
	}
	*(rez+x)='\0';
	CString tmp=LPCSTR(rez);
	StudentInf.push_back(tmp);
	return	n2;
}

void CProject_UNIDlg::OnAboutbox()
{
	// TODO: добавьте свой код обработчика команд
	CAboutDlg dlg;
	dlg.DoModal();
}
