
// Project_UNIDlg.h : файл заголовка
//

#pragma once
#include <vector>
#include <cstring>
#include "Queue.h"
#include "KStruct.h"
#include <string>
using namespace std;

// диалоговое окно CProject_UNIDlg
class CProject_UNIDlg : public CDialogEx
{
// Создание
public:
	CProject_UNIDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_PROJECT_UNI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	vector<CString> buff;
	vector<CString> StudentInf;
	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnAboutbox();
	void SymbReading(char*);
	int leksema(int ,int ,char* );
};
