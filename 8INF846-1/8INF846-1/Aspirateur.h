#pragma once
#include <vector>
#include <queue>
#include "CaseEnvironnement.h"
#include "RobotEnvironnement.h"
#include "Move.h"
#include "PickUp.h"
#include "Vacumize.h"

struct Plan {
	int value;
	std::queue<CaseEnvironnement*> path;
};
typedef Plan Plan;

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
	std::queue<CaseEnvironnement *> DepthLimitedSearch(int* valueTab, int energyToConsume);
	Plan RecursiveDLS(Plan whereToGo, int* valueTab, int energyToConsume);
	std::queue<Action *> pathToActions(std::queue<CaseEnvironnement *> path);

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

