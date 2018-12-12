// Step.cpp: файл реализации
//

#include "stdafx.h"
#include "Project_UNI.h"
#include "Step.h"


// CStep

IMPLEMENT_DYNAMIC(CStep, BasicStep)

	CStep::CStep()
{
	k1=1;
	k2=1.2;
	k3=1.4;
	k4=1.6;
	stepend=55.3;
}

CStep::~CStep()
{
}
CStep::CStep(double _k1,double _k2,double _k3,double _k4,double _stepend)
{
	k1=_k1;
	k2=_k2;
	k3=_k3;
	k4=_k4;
	stepend=_stepend;
}


CString CStep::Raschet(double nadbavka,double srball)
{
	double k=KRaschet(srball);
	CString str;
	double rez= stepend*k+nadbavka;
	str.Format(_T("%.2f"), rez);
	return str;
}

BEGIN_MESSAGE_MAP(CStep, BasicStep)
END_MESSAGE_MAP()

double CStep::KRaschet(double srb)
{
	if(srb>=5 && srb<=6)
		return k1;
	if(srb>6 && srb<=7)
		return k2;
	if(srb>7 && srb<=8)
		return k3;
	if(srb>8 && srb<=10)
		return k4;
	
}

// обработчики сообщений CStep

