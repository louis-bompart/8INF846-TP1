#include "Aspirateur.h"
#include <iostream>
#include <time.h>
#include <thread>

Aspirateur::Aspirateur(CaseEnvironnement* ce) :
	energy(0),
	currentRoom(ce),
	oldScore(1),
	epsilon(0.05),
	maxEnergy(5),
	deltaScore(0),
	currentScore(0),
	nbPlanBeforeUpdate(0)
{
}

void Aspirateur::Execute()
{
	int actionsTillUpdate = 5;
	//PlanSinceUpdate>PlanBeforeUpdate to initialize the robotEnvironnement asap
	int nbPlanSinceUpdate = nbPlanBeforeUpdate+1;
	bool firstLesson = true;
	bool isLearning = true;
	while (true) {

		if (Goals.empty()) {
			//Beliefs' update, as soon as we completed our current intentions' plan
			if (nbPlanSinceUpdate > nbPlanBeforeUpdate) {
				environnement.UpdateData();
				nbPlanSinceUpdate = 0;
			}

			//Desires' update, if learning is not yet completed
			if (isLearning)
			{
				if (Heuristic::GetInstance()->getScore() != 0) {
					actionsTillUpdate--;
					float maxScore = maxEnergy*Heuristic::maxScore;
					currentScore += 1 - Heuristic::GetInstance()->getScore() / maxScore;
					Heuristic::GetInstance()->resetScore();
				}
				if (actionsTillUpdate <= 0) {
					//Avg of score of the five intentions' plan with a specified depth (aka energy)
					currentScore /= 5;

					deltaScore = oldScore - currentScore;
					//If the score is 'epsilon*100' % worst than the previous one, then we stop learning and return to the previous depth.
					if (deltaScore < epsilon || firstLesson) {
						firstLesson = false;
						maxEnergy++;
						oldScore = currentScore;
						currentScore = 0;
					}
					else {
						maxEnergy--;
						isLearning = false;
					}
					actionsTillUpdate = 5;
				}
			}

			//Intentions' update
			nbPlanSinceUpdate++;
			Goals = pathToActions(DepthLimitedSearch(maxEnergy));
		}
		else {
			//If the plan is not completed, then do the next action
			Goals.front()->doAction();
			Goals.pop();
		}
		//Because our robot is not Flash Gordon.
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

std::deque<CaseEnvironnement*> Aspirateur::DepthLimitedSearch(int energyToConsume)
{
	Plan whereToGo;
	whereToGo.path.push_back(environnement.getCase(currentRoom));
	// energyToConsume + 1 : the +1 is to avoid consuming energy to move to the current case.
	whereToGo = RecursiveDLS(whereToGo, energyToConsume + 1);
	return whereToGo.path;
}

Plan Aspirateur::RecursiveDLS(Plan whereToGo, int energyToConsume)
{
	// create the bestPlan to compare.
	Plan bestPlan = whereToGo;
	//remove the energy for this case.
	//--energyToConsume;
	//EmptyCase is about the same as JewelOnly, because the robot ignore Jewels if possible
	energyToConsume -= Heuristic::EmptyCase;
	if (whereToGo.path.back()->Poussiere() == 1) {

		if (whereToGo.path.back()->Jewels() == 1) {
			//--energyToConsume;
			energyToConsume -= Heuristic::JewelAndPoussiere;
		}
		energyToConsume -= Heuristic::PoussiereOnly;
	}
	// search for the next case if there is enough energy
	for each (CaseEnvironnement* neighboor in whereToGo.path.back()->AdjacentRooms())
	{
		if (std::find(whereToGo.path.begin(), whereToGo.path.end(), neighboor) == whereToGo.path.end()) {
			// summ of the energy needed
			int energyNeeded = (neighboor->Jewels() + 1) * neighboor->Poussiere() + 1;
			//walk to the neighboor
			if (energyToConsume - energyNeeded >= 0) {
				Plan newWay = whereToGo;
				// summ of the points for the case
				int points = 0;
				if (neighboor->Jewels() == 1)
					if (neighboor->Poussiere() == 1)
						points = Heuristic::JewelAndPoussiere;
					else
						points = Heuristic::JewelOnly;
				else
					if (neighboor->Poussiere() == 1)
						points = Heuristic::PoussiereOnly;
					else
						points = Heuristic::EmptyCase;
				newWay.value += points;
				newWay.path.push_back(neighboor);
				Plan onTheWay = RecursiveDLS(newWay, energyToConsume);
				if (onTheWay.value >= bestPlan.value)
					bestPlan = onTheWay;
			}
		}
	}
	return bestPlan;
}
std::queue<Action*> Aspirateur::pathToActions(std::deque<CaseEnvironnement*> path)
{
	std::queue<Action*> actions;
	while (!path.empty()) {
		CaseEnvironnement * position = path.front();
		path.pop_front();
		if (position->Poussiere() == 1) {
			if (position->Jewels() == 1) {
				actions.push(new PickUp(this, position));
			}
			actions.push(new Vacumize(this, position));
		}
		if (!path.empty())
			actions.push(new Move(this, path.front()));
	}
	return actions;
}

Aspirateur::~Aspirateur()
{
}
