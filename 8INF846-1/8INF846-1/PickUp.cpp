#include "PickUp.h"

PickUp::PickUp(Aspirateur* _asp, CaseEnvironnement* _caseToAct) : Action(_asp,_caseToAct)
{
}


PickUp::~PickUp()
{
}

int PickUp::doAction() 
{
	Action::doAction();
	asp->getEnvironnement().RemoveJewel(caseToAct);
	GlobalEnvironnement::GetInstance()->RemoveJewel(GlobalEnvironnement::GetInstance()->getCase(caseToAct));
	return 0;
}
