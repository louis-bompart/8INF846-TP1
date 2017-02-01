#include <time.h> 
#include <thread>

#include "Environnement.h"

Environnement::Environnement()
{
    int taille = 5;
    CaseEnvironnement* aCase;
    std::vector<CaseEnvironnement*> ligne;

    for (unsigned int i = 0; i < taille; i++) {
        for (unsigned int j = 0; j < taille; j++) {
			aCase = new CaseEnvironnement();
			allRooms.push_back(aCase);
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
				adjRooms.push_back(cases[i + 1 ][j]);
			}
			if (j < taille - 1) {
				adjRooms.push_back(cases[i][j +1]);
			}
			if (j > 0) {
				adjRooms.push_back(cases[i][j - 1]);
			}
			if (i > 0) {
				adjRooms.push_back(cases[i-1][j]);
			}
			cases[i][j]->AdjacentRooms(adjRooms);
		}
	}
}


void Environnement::Execute()
{
	while (true) {
		srand(time(NULL));
		int random = rand() % 3;
		int randomDust;
		int randomJewels;
		for (int i = 0; i < random; i++) {
			randomDust = rand() % allRooms.size();
			allRooms[randomDust]->Poussiere(allRooms[randomDust]->Poussiere() + 1);
		}
		random = rand() % 1;
		for (int i = 0; i < random; i++) {
			randomJewels = rand() % allRooms.size();
			allRooms[randomJewels]->Poussiere(allRooms[randomDust]->Poussiere() + 1);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}


Environnement::~Environnement()
{
}
