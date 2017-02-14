#pragma once
#include <vector>
#include <map>
#include "CaseEnvironnement.h"

class Environnement {
public:

	virtual void ClearCase(CaseEnvironnement* suckedCase) = 0;
	virtual void RemoveJewel(CaseEnvironnement* suckedCase) = 0;
	std::map<int,CaseEnvironnement*> getAllRooms() { return allRooms; }
	CaseEnvironnement* getCase(CaseEnvironnement* input);
	Environnement();
	~Environnement();

protected:

	std::map<int,CaseEnvironnement*> allRooms;
	int jewelsLost;
	std::vector<std::vector<CaseEnvironnement*>> cases;
};

