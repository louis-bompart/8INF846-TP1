#include "GlobalEnvironnement.h"
GlobalEnvironnement* GlobalEnvironnement::instance;

void GlobalEnvironnement::Execute()
{
	while (true) {
		int random = rand() % 3;
		int randomDust;
		int randomJewels;
		for (int i = 0; i < random; i++) {
			randomDust = rand() % getAllRooms().size();
			getAllRooms()[randomDust]->Poussiere(1);
		}
		random = rand() % 2;
		for (int i = 0; i < random; i++) {
			randomJewels = rand() % getAllRooms().size();
			getAllRooms()[randomJewels]->Jewels(1);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}
}

GlobalEnvironnement::GlobalEnvironnement(): allJewelsLost(0)
{
}

GlobalEnvironnement::~GlobalEnvironnement()
{
}

void GlobalEnvironnement::ClearCase(CaseEnvironnement * suckedCase)
{
	suckedCase->Poussiere(0);
	RemoveJewel(suckedCase) ? oneMoreJewel() : NULL;
}
bool GlobalEnvironnement::RemoveJewel(CaseEnvironnement * suckedCase)
{
	bool toReturn = suckedCase->Jewels() == 1;
	suckedCase->Jewels(0);
	return toReturn;
}

int GlobalEnvironnement::getJewelsLost()
{
	int temp = jewelsLost;
	//allJewelsLost += jewelsLost;
	jewelsLost = 0;
	return temp;
}
