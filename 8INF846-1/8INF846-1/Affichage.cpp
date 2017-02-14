#include <chrono>
#include <iostream>
#include <thread>

#include "Affichage.h"


Affichage::Affichage(GlobalEnvironnement* env, Aspirateur* asp)
{
	this->env = env;
	this->asp = asp;
}


Affichage::~Affichage()
{
}

void Affichage::Execute() {

	while (true) {

		for (unsigned int i = 0; i < env->Cases().size(); i++) {
			for (unsigned int j = 0; j < env->Cases()[i].size(); j++) {
				std::cout << " " << env->Cases()[i][j]->Poussiere() << "|" << env->Cases()[i][j]->Jewels() << ((asp->CurrentRoom()->ID() == env->Cases()[i][j]->ID()) ? "*" : " ");
			}
			std::cout << std::endl;
		}
		std::cout << "Bijoux aspires: " << env->getAllJewelsLost() << std::endl;
		std::cout << "Energie totale consommee: " << asp->getEnergyConsumed() << std::endl;
		std::cout << "Energie avant rafraichissement: " << asp->getMaxEnergy() << std::endl;
		std::cout << "Difference de score depuis le dernier apprentissage: " << asp->getDeltaScore() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		system("cls");
	}
}
