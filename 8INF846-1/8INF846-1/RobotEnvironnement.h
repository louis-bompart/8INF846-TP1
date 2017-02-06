#pragma once
#include "Environnement.h"
class RobotEnvironnement : private Environnement
{
public:
	int getJewelsLost() { return jewelsLost; }
	void ClearCase(CaseEnvironnement* suckedCase);
	bool RemoveJewel(CaseEnvironnement* suckedCase);

	RobotEnvironnement();
	~RobotEnvironnement();

	void UpdateData() {}
};

