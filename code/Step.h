#pragma once
#include "BasicStep.h"
#include "KStruct.h"

// CStep

class CStep : public BasicStep
{
	DECLARE_DYNAMIC(CStep)

	double k1,k2,k3,k4;
	int stepend;

public:
	CStep();
	virtual ~CStep();
	CStep(double ,double ,double,double ,double);

	CString Raschet(double,double);
	double KRaschet(double );
	

protected:
	DECLARE_MESSAGE_MAP()
};

