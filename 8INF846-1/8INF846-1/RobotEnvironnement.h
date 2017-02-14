#pragma once
#include "Environnement.h"
#include "GlobalEnvironnement.h"
#include <map>

class RobotEnvironnement : public Environnement
{
public:
	int getJewelsLost() { return jewelsLost; }
	void ClearCase(CaseEnvironnement* suckedCase);
	bool RemoveJewel(CaseEnvironnement* suckedCase);

	RobotEnvironnement();
	~RobotEnvironnement();

	void UpdateData();
};

