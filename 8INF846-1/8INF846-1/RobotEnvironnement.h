#pragma once
#include "Environnement.h"
#include "GlobalEnvironnement.h"
#include <map>

class RobotEnvironnement : public Environnement
{
public:
	void ClearCase(CaseEnvironnement* suckedCase);
	void RemoveJewel(CaseEnvironnement* suckedCase);

	RobotEnvironnement();
	~RobotEnvironnement();

	void UpdateData();
};

