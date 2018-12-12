#pragma once
#include "Step.h"

// CNadbavka

class CNadbavka : public CStep
{
	DECLARE_DYNAMIC(CNadbavka)

public:
	CNadbavka();
	virtual ~CNadbavka();

	void Raschet();

protected:
	DECLARE_MESSAGE_MAP()
};


