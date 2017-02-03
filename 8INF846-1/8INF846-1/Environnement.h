#pragma once
#include <vector>
#include "CaseEnvironnement.h"


class Environnement {
public:
	static Environnement* GetInstance() {
		if (instance == nullptr) {
			instance = new Environnement();
		}
		return instance;
	}

	std::vector<std::vector<CaseEnvironnement*>> Cases() const
	{
		return cases;
	}
	void Execute();

private:
	std::vector<std::vector<CaseEnvironnement*>> cases;
	std::vector<CaseEnvironnement*> allRooms;
	static Environnement* instance;

	Environnement();
	~Environnement();
};

