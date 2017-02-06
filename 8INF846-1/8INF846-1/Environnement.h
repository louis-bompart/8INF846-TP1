#pragma once
#include <vector>
#include <map>
#include "CaseEnvironnement.h"

class Environnement {
public:

	virtual int getJewelsLost() = 0;
	virtual void ClearCase(CaseEnvironnement* suckedCase) = 0;
	virtual bool RemoveJewel(CaseEnvironnement* suckedCase) = 0;
	std::map<int,CaseEnvironnement*> getAllRooms() { return allRooms; }

	Environnement();
	~Environnement();

protected:

	std::map<int,CaseEnvironnement*> allRooms;
	int jewelsLost;
	std::vector<std::vector<CaseEnvironnement*>> cases;
};

