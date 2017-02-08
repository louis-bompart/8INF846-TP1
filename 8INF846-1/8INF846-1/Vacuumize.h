#pragma once
#include "Action.h"
#include "Aspirateur.h"
#include "GlobalEnvironnement.h"

class Vacuumize :
	public Action
{
public:
	Vacuumize(Aspirateur * _asp, CaseEnvironnement * _caseToAct);
	~Vacuumize();
	int doAction();
};

