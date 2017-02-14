#include "Aspirateur.h"
#include <iostream>
#include <time.h>
#include <thread>

Aspirateur::Aspirateur(CaseEnvironnement* ce) : energy(0), currentRoom(ce), oldScore(0), epsilon(0.05), maxEnergy(1), deltaScore(0)
{
}

void Aspirateur::Execute()
{
	int actionsTillUpdate = 5;
	float score = 0;
	bool isLearning = true;
	//srand(time(NULL));
	while (true) {

		if (Goals.empty()) {
			//Beliefs' update
			environnement.UpdateData();

			//Desires' update
			if (isLearning)
			{
				actionsTillUpdate--;
				score += GlobalEnvironnement::GetInstance()->getJewelsLost() / maxEnergy;
				if (actionsTillUpdate < 0) {
					score /= 5;
					deltaScore = score - oldScore;
					if (deltaScore < epsilon) {
						maxEnergy++;
						oldScore = score;
					}
					else {
						maxEnergy--;
						isLearning = false;
					}
					actionsTillUpdate = 5;
				}
			}

			//Intentions' update
			Goals = pathToActions(DepthLimitedSearch(heuristic, maxEnergy));
		}
		else {
			Goals.front()->doAction();
			Goals.pop();
		}
		//std::vector<CaseEnvironnement*> adjRooms = currentRoom->AdjacentRooms();
		//int random = rand() % (adjRooms.size());
		//Goals.push(new Move(this, adjRooms[random]));
		/*srand(time(NULL));
		std::vector<CaseEnvironnement*> adjRooms = currentRoom->AdjacentRooms();
		int random = rand() % (adjRooms.size());*/
		//currentRoom = adjRooms[random];
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

std::deque<CaseEnvironnement*> Aspirateur::DepthLimitedSearch(int valueTab[4], int energyToConsume)
{
	Plan whereToGo;
	whereToGo.path.push_back(environnement.getCase(currentRoom));
	// energyToConsume + 1 : the +1 is to avoid consuming energy to move to the current case.
	whereToGo = RecursiveDLS(whereToGo, valueTab, energyToConsume + 1);
	return whereToGo.path;
}

Plan Aspirateur::RecursiveDLS(Plan whereToGo, int valueTab[4], int energyToConsume)
{
	// create the bestPlan to compare.
	Plan bestPlan = whereToGo;
	//remove the energy for this case.
	--energyToConsume;
	if (whereToGo.path.back()->Jewels() == 1) {
		--energyToConsume;
	}
	if (whereToGo.path.back()->Poussiere() == 1) {
		--energyToConsume;
	}
	// search for the next case if there is enough energy
	for each (CaseEnvironnement* voisin in whereToGo.path.back()->AdjacentRooms())
	{
		if (std::find(whereToGo.path.begin(), whereToGo.path.end(), voisin) == whereToGo.path.end()) {
			// summ of the energy needed
			int energyNeeded = voisin->Jewels() + voisin->Poussiere() + 1;
			//walk to the neighboor
			if (energyToConsume - energyNeeded >= 0) {
				Plan newWay = whereToGo;
				// summ of the points for the case
				int points = 0;
				if (voisin->Jewels() == 1)
					if (voisin->Poussiere() == 1)
						points = valueTab[3];
					else
						points = valueTab[2];
				else
					if (voisin->Poussiere() == 1)
						points = valueTab[1];
					else
						points = valueTab[0];
				newWay.value += points;
				newWay.path.push_back(voisin);
				Plan onTheWay = RecursiveDLS(newWay, valueTab, energyToConsume);
				if (onTheWay.value >= bestPlan.value)
					bestPlan = onTheWay;
			}
		}
	}
	return bestPlan;
}
std::queue<Action*> Aspirateur::pathToActions(std::deque<CaseEnvironnement*> path)
{
	std::queue<Action*> toDo;
	while (!path.empty()) {
		CaseEnvironnement * position = path.front();
		path.pop_front();
		if (position->Jewels() == 1) {
			toDo.push(new PickUp(this, position));
		}
		if (position->Poussiere() == 1) {
			toDo.push(new Vacumize(this, position));
		}
		if (!path.empty())
			toDo.push(new Move(this, path.front()));
	}
	return toDo;
}
//
//void Aspirateur::SuckCase(CaseEnvironnement * suckedCase)
//{
//	suckedCase->Poussiere = 0;
//	Environnement::GetInstance()->SuckCase(suckedCase);
//}
//
//bool Aspirateur::PickUpJewel(CaseEnvironnement * suckedCase)
//{
//	suckedCase->Jewels = 0;
//	Environnement::GetInstance()->PickUpJewel(suckedCase);
//	return true;
//}


Aspirateur::~Aspirateur()
{
}
