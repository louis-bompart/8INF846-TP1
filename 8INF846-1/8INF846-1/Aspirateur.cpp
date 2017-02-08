#include "Aspirateur.h"
#include <iostream>
#include <time.h>
#include <thread>

Aspirateur::Aspirateur(CaseEnvironnement* ce) : energy(0), currentRoom(ce)
{
}

void Aspirateur::Execute()
{
	srand(time(NULL));
	while (true) {
		std::vector<CaseEnvironnement*> adjRooms = currentRoom->AdjacentRooms();
		int random = rand() % (adjRooms.size());
		Goals.push(new Move(this, adjRooms[random]));
		/*srand(time(NULL));
		std::vector<CaseEnvironnement*> adjRooms = currentRoom->AdjacentRooms();
		int random = rand() % (adjRooms.size());*/
		//currentRoom = adjRooms[random];
		Goals.front()->doAction();
		Goals.pop();
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
