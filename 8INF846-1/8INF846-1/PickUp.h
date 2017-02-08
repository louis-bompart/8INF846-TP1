#pragma once
#include "Action.h"
#include "Aspirateur.h"
#include "GlobalEnvironnement.h"

class PickUp :
	public Action
{
public:
	PickUp(Aspirateur* _asp, CaseEnvironnement* _caseToAct);
	~PickUp();
	int doAction();
};

