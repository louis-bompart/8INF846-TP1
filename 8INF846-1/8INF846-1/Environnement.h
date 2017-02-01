#pragma once
#include <vector>
#include "CaseEnvironnement.h"


class Environnement {
public:
    Environnement();
    ~Environnement();

    std::vector<std::vector<CaseEnvironnement*>> Cases() const
    {
        return cases;
    }
    void Execute();

private:
    std::vector<std::vector<CaseEnvironnement*>> cases;
	std::vector<CaseEnvironnement*> allRooms;
};

