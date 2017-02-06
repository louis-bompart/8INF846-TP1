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