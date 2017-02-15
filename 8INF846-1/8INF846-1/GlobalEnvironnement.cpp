#include "GlobalEnvironnement.h"
GlobalEnvironnement* GlobalEnvironnement::instance;

GlobalEnvironnement::GlobalEnvironnement(): allJewelsLost(0)
{
}

GlobalEnvironnement::~GlobalEnvironnement()
{
}

void GlobalEnvironnement::Execute()
{
	while (true) {
		int random = rand() % 3;
		int randomDust;
		int randomJewels;
		//Randomly add dust
		for (int i = 0; i < random; i++) {
			randomDust = rand() % getAllRooms().size();
			getAllRooms()[randomDust]->Poussiere(1);
		}
		//Randomly add jewel
		random = rand() % 2;
		for (int i = 0; i < random; i++) {
			randomJewels = rand() % getAllRooms().size();
			getAllRooms()[randomJewels]->Jewels(1);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
}

void GlobalEnvironnement::ClearCase(CaseEnvironnement * suckedCase)
{
	if(suckedCase->Poussiere()!=0)
	{
		if (suckedCase->Jewels() != 0) {
			Heuristic::GetInstance()->updateScore(Heuristic::JewelSucked);
			allJewelsLost++;
		}
		else
			Heuristic::GetInstance()->updateScore(Heuristic::PoussiereCleared);
	}
	else {
		if (suckedCase->Jewels() == 0) 
			Heuristic::GetInstance()->updateScore(Heuristic::JewelSucked);
	}
	suckedCase->Poussiere(0);
}
void GlobalEnvironnement::RemoveJewel(CaseEnvironnement * suckedCase)
{
	Heuristic::GetInstance()->updateScore(Heuristic::JewelPicked);
	bool toReturn = suckedCase->Jewels() == 1;
	suckedCase->Jewels(0);
}
