#pragma once
#include "Action.h"
#include "Aspirateur.h"
#include "CaseEnvironnement.h"
#include <algorithm>

class Move : public Action
{
public:
	int doAction();
	Move(Aspirateur * _asp, CaseEnvironnement * _caseToAct);
	~Move();
};

