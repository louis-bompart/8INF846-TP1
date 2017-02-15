#pragma once
#include "Action.h"
#include "Aspirateur.h"
#include "GlobalEnvironnement.h"

class Vacumize :
	public Action
{
public:
	Vacumize(Aspirateur * _asp, CaseEnvironnement * _caseToAct);
	~Vacumize();
	int doAction();
};

