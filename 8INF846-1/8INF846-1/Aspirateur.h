#pragma once
#include <vector>
#include <queue>
#include "CaseEnvironnement.h"
#include "RobotEnvironnement.h"
#include "Move.h"

class Aspirateur {
public:
	Aspirateur(CaseEnvironnement* ce);
	~Aspirateur();

	void Execute();

	CaseEnvironnement* CurrentRoom() const { return currentRoom; }
	void CurrentRoom(CaseEnvironnement* val) { currentRoom = val; }
	void ConsumeEnergy() { energy++; }
	void ResetEnergy() { energy = 0; }
	RobotEnvironnement getEnvironnement() { return environnement; }
	//void SuckCase(CaseEnvironnement* suckedCase);
	//bool PickUpJewel(CaseEnvironnement* suckedCase);

private:
	RobotEnvironnement environnement;
	CaseEnvironnement* currentRoom;
	int energy;
	//TODO maybe to remove the next line
	//std::vector<int[2]> Goals;
	std::queue<Action *> Goals;
};

