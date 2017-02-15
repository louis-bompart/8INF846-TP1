#pragma once
#include "Environnement.h"
#include "Heuristic.h"
#include <thread>
#include <chrono>

class GlobalEnvironnement : public Environnement
{
public:
	std::vector<std::vector<CaseEnvironnement*>> Cases() const { return cases; }
	void Execute();
	static GlobalEnvironnement* GetInstance() {
		if (!instance) {
			instance = new GlobalEnvironnement();
		}
		return instance;
	}

	void ClearCase(CaseEnvironnement* suckedCase);
	void RemoveJewel(CaseEnvironnement* suckedCase);
	int getAllJewelsLost() { return allJewelsLost; }

private:
	GlobalEnvironnement();
	~GlobalEnvironnement();
	static GlobalEnvironnement* instance;
	int allJewelsLost;
};

