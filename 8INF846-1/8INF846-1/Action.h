#pragma once

#include "CaseEnvironnement.h"
class Aspirateur;
class Action
{
public:
	Action(Aspirateur* _asp, CaseEnvironnement* _caseToAct);
	~Action();
	virtual int doAction();
	CaseEnvironnement* getCaseToAct() const { return caseToAct; }
protected:
	Aspirateur* asp;
	CaseEnvironnement* caseToAct;
};

