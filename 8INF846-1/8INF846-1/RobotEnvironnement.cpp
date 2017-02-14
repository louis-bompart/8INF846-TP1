#include "RobotEnvironnement.h"



RobotEnvironnement::RobotEnvironnement()
{
}


RobotEnvironnement::~RobotEnvironnement()
{
}

void RobotEnvironnement::ClearCase(CaseEnvironnement * suckedCase)
{
	suckedCase->Poussiere(0);
	RemoveJewel(suckedCase);
}

bool RobotEnvironnement::RemoveJewel(CaseEnvironnement * suckedCase)
{
	suckedCase->Jewels(0);
	return true;
}

void RobotEnvironnement::UpdateData() {
	std::map<int,CaseEnvironnement*> globalCases = GlobalEnvironnement::GetInstance()->getAllRooms();
	for each (std::pair<const int,CaseEnvironnement*> pair in allRooms)
	{
		CaseEnvironnement * kaze = pair.second;
		kaze->Jewels(globalCases.at(pair.first)->Jewels());
		kaze->Poussiere(globalCases.at(pair.first)->Poussiere());
	}
}