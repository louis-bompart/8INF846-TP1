#include <time.h> 
#include <thread>

#include "Environnement.h"

CaseEnvironnement * Environnement::getCase(CaseEnvironnement * input)
{
	
	return allRooms.at(input->ID());
}

Environnement::Environnement() : jewelsLost(0)
{
	int taille(5);
	int caseCurrentID(0);
	CaseEnvironnement* aCase;
	std::vector<CaseEnvironnement*> ligne;
	srand(time(NULL));

	for (unsigned int i = 0; i < taille; i++) {
		for (unsigned int j = 0; j < taille; j++) {
			aCase = new CaseEnvironnement(caseCurrentID);
			allRooms.emplace(caseCurrentID,aCase);
			++caseCurrentID;
			ligne.push_back(aCase);
		}
		cases.push_back(ligne);
		ligne.clear();
	}
	std::vector<CaseEnvironnement*> adjRooms;
	for (int i = 0; i < taille; i++) {
		for (unsigned int j = 0; j < taille; j++) {
			adjRooms = cases[i][j]->AdjacentRooms();
			if (i < taille - 1) {
				adjRooms.push_back(cases[i + 1][j]);
			}
			if (j < taille - 1) {
				adjRooms.push_back(cases[i][j + 1]);
			}
			if (j > 0) {
				adjRooms.push_back(cases[i][j - 1]);
			}
			if (i > 0) {
				adjRooms.push_back(cases[i - 1][j]);
			}
			cases[i][j]->AdjacentRooms(adjRooms);
		}
	}
}

Environnement::~Environnement()
{
}
