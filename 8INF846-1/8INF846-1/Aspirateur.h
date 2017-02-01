#pragma once
#include <vector>
#include "CaseEnvironnement.h"

class Aspirateur {
public:
    Aspirateur(CaseEnvironnement* ce);
    ~Aspirateur();

    void Execute();

	CaseEnvironnement* CurrentRoom() const { return currentRoom; }
	void CurrentRoom(CaseEnvironnement* val) { currentRoom = val; }

private:
    CaseEnvironnement* currentRoom;
    std::vector<int[2]> Goals;
};

