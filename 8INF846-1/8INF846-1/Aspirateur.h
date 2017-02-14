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
#include "Heuristic.h"

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

	RobotEnvironnement getEnvironnement() { return environnement; }

	CaseEnvironnement* CurrentRoom() const { return currentRoom; }
	void CurrentRoom(CaseEnvironnement* val) { currentRoom = val; }

	std::deque<CaseEnvironnement *> DepthLimitedSearch(int energyToConsume);
	Plan RecursiveDLS(Plan whereToGo, int energyToConsume);
	std::queue<Action *> pathToActions(std::deque<CaseEnvironnement *> path);

	int getMaxEnergy() { return maxEnergy; }

	int getEnergyConsumed() { return energy; }
	void ConsumeEnergy() { energy++; }
	void ResetEnergy() { energy = 0; }

	float getDeltaScore() { return deltaScore; }
	float getCurrentScore() { return currentScore; }

private:
	RobotEnvironnement environnement;
	CaseEnvironnement* currentRoom;
	std::queue<Action *> Goals;

	int energy;
	int maxEnergy;

	int const nbPlanBeforeUpdate;

	float oldScore;
	float currentScore;
	float epsilon;
	float deltaScore;
};

