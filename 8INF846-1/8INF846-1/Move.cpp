#include "Move.h"


int Move::doAction()
{
	std::vector<CaseEnvironnement*> adjacentRooms = asp->CurrentRoom()->AdjacentRooms();
	if (std::find(adjacentRooms.begin(), adjacentRooms.end(), caseToAct) == adjacentRooms.end()) {
		return 1;
	}
	asp->CurrentRoom(caseToAct);
	return 0;
}

Move::Move(Aspirateur * _asp, CaseEnvironnement * _caseToAct) : Action(_asp, _caseToAct)
{
}


Move::~Move()
{
}
