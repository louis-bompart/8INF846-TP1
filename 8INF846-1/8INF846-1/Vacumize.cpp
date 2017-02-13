#include "Vacumize.h"

int Vacumize::doAction() {
	asp->getEnvironnement().ClearCase(asp->CurrentRoom());
	GlobalEnvironnement::GetInstance()->ClearCase(GlobalEnvironnement::GetInstance()->getCase(asp->CurrentRoom()));
	return 0;
}

Vacumize::Vacumize(Aspirateur* _asp, CaseEnvironnement* _caseToAct) : Action(_asp,_caseToAct)
{
}


Vacumize::~Vacumize()
{
}
