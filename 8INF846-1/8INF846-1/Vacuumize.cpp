#include "Vacuumize.h"

int Vacuumize::doAction() {
	asp->getEnvironnement().ClearCase(asp->CurrentRoom());
	GlobalEnvironnement::GetInstance()->ClearCase(GlobalEnvironnement::GetInstance()->getCase(asp->CurrentRoom()));
	return 0;
}

Vacuumize::Vacuumize(Aspirateur* _asp, CaseEnvironnement* _caseToAct) : Action(_asp,_caseToAct)
{
}


Vacuumize::~Vacuumize()
{
}
