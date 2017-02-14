#pragma once
#include "Environnement.h"
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
	bool RemoveJewel(CaseEnvironnement* suckedCase);
	int getJewelsLost();
	int getAllJewelsLost() { return allJewelsLost; }

private:
	GlobalEnvironnement();
	~GlobalEnvironnement();

	static GlobalEnvironnement* instance;
	//TODO Afficher le nombre total de bijoux perdus.
	int allJewelsLost;
	void oneMoreJewel() { jewelsLost++; allJewelsLost++; }
};

