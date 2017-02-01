#include "Aspirateur.h"
#include <iostream>
#include <time.h>
#include <thread>

Aspirateur::Aspirateur(CaseEnvironnement* ce)
{
	currentRoom = ce;
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


Aspirateur::~Aspirateur()
{
}
