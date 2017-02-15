#include "Action.h"
#include "Aspirateur.h"

Action::Action(Aspirateur * _asp, CaseEnvironnement * _caseToAct): asp(_asp), caseToAct(_caseToAct)
{
}

Action::~Action()
{
}

int Action::doAction()
{
	asp->ConsumeEnergy();
	return 0;
}
