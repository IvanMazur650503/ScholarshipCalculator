
// Project_UNI.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CProject_UNIApp:
// � ���������� ������� ������ ��. Project_UNI.cpp
//

class CProject_UNIApp : public CWinApp
{
public:
	CProject_UNIApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CProject_UNIApp theApp;