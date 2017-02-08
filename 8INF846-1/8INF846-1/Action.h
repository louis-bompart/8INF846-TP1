#pragma once

#include "CaseEnvironnement.h"
class Aspirateur;
class Action
{
public:
	Action(Aspirateur* _asp, CaseEnvironnement* _caseToAct);
	~Action();
	virtual int doAction()=0;
protected:
	Aspirateur* asp;
	CaseEnvironnement* caseToAct;
};

