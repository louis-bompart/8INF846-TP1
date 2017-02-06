#include "Aspirateur.h"
#include <iostream>
#include <time.h>
#include <thread>

Aspirateur::Aspirateur(CaseEnvironnement* ce)
{
	currentRoom = ce;
	energy = 0;
}

void Aspirateur::Execute()
{
	while (true) {
		srand(time(NULL));
		std::vector<CaseEnvironnement*> adjRooms = currentRoom->AdjacentRooms();
		int random = rand() % (adjRooms.size());
		currentRoom = adjRooms[random];
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
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
