#pragma once
#include <vector>
#include "CaseEnvironnement.h"

class Environnement {
public:

	virtual int getJewelsLost() = 0;
	virtual void ClearCase(CaseEnvironnement* suckedCase) = 0;
	virtual bool RemoveJewel(CaseEnvironnement* suckedCase) = 0;
	std::vector<CaseEnvironnement*> getAllRooms() { return allRooms; }

	Environnement();
	~Environnement();

protected:

	std::vector<CaseEnvironnement*> allRooms;
	int jewelsLost;
	std::vector<std::vector<CaseEnvironnement*>> cases;
};

