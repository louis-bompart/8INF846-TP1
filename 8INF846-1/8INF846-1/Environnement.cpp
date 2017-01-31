#include "Environnement.h"


Environnement::Environnement()
{
    int taille = 8;
    CaseEnvironnement* aCase = new CaseEnvironnement();
    std::vector<CaseEnvironnement> ligne;

    for (int i = 0; i < taille; i++) {
        for (int i = 0; i < taille; i++) {
            ligne.push_back(*aCase);
        }
        cases.push_back(ligne);
        ligne.clear();
    }
}

void Environnement::Execute()
{

}


Environnement::~Environnement()
{
}
