#pragma once
#include <vector>
#include "CaseEnvironnement.h"
#include "RobotEnvironnement.h"

class Aspirateur {
public:
	Aspirateur(CaseEnvironnement* ce);
	~Aspirateur();

	void Execute();

	CaseEnvironnement* CurrentRoom() const { return currentRoom; }
	void CurrentRoom(CaseEnvironnement* val) { currentRoom = val; }
	void ConsumeEnergy() { energy++; }
	void ResetEnergy() { energy = 0; }

	//void SuckCase(CaseEnvironnement* suckedCase);
	//bool PickUpJewel(CaseEnvironnement* suckedCase);

private:
	RobotEnvironnement environnement;
	CaseEnvironnement* currentRoom;
	int energy;
	std::vector<int[2]> Goals;
};

