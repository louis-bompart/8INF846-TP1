#pragma once
#include <vector>

class CaseEnvironnement {
public:
    CaseEnvironnement(int _id);
    ~CaseEnvironnement();

    int Poussiere() const
    {
        return poussiere;
    }
    void Poussiere(int val)
    {
        poussiere = val;
    }
    int Jewels() const
    {
        return jewels;
    }
    void Jewels(int val)
    {
        jewels = val;
    }
	int ID() const
	{
		return id;
	}

	std::vector<CaseEnvironnement*> AdjacentRooms() const { return adjacentRooms; }
	void AdjacentRooms(std::vector<CaseEnvironnement*> val) { adjacentRooms = val; }

private:
	std::vector<CaseEnvironnement*> adjacentRooms;
    int poussiere;
    int jewels;
	int id;
};

