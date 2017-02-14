#pragma once
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include "CaseEnvironnement.h"
#include "RobotEnvironnement.h"
#include "Move.h"
#include "PickUp.h"
#include "Vacumize.h"

struct Plan {
	int value;
	std::deque<CaseEnvironnement*> path;
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
	std::deque<CaseEnvironnement *> DepthLimitedSearch(int valueTab[4], int energyToConsume);
	Plan RecursiveDLS(Plan whereToGo, int valueTab[4], int energyToConsume);
	std::queue<Action *> pathToActions(std::deque<CaseEnvironnement *> path);
	int getMaxEnergy() { return maxEnergy; }
	int getEnergyConsumed() { return energy; }
	float getDeltaScore() { return deltaScore; }


	//void SuckCase(CaseEnvironnement* suckedCase);
	//bool PickUpJewel(CaseEnvironnement* suckedCase);

private:
	RobotEnvironnement environnement;
	CaseEnvironnement* currentRoom;
	int energy;
	int maxEnergy;
	float oldScore;
	float epsilon;
	float deltaScore;
	//TODO maybe to remove the next line
	//std::vector<int[2]> Goals;
	std::queue<Action *> Goals;
	int heuristic[4] =
	{
		//Empty case
		0,
		//Poussiere only
		2,
		//Jewel only
		0,
		//Jewel and Poussiere
		1
	};
	
};

