#include "Move.h"

int Move::doAction()
{
	Action::doAction();
	Heuristic::GetInstance()->updateScore(Heuristic::Moved);
	std::vector<CaseEnvironnement*> adjacentRooms = asp->CurrentRoom()->AdjacentRooms();
	asp->CurrentRoom(caseToAct);
	return 0;
}

Move::Move(Aspirateur * _asp, CaseEnvironnement * _caseToAct) : Action(_asp, _caseToAct)
{
}

Move::~Move()
{
}
