#include <chrono>
#include <iostream>
#include <thread>

#include "Affichage.h"


Affichage::Affichage(Environnement* env, Aspirateur* asp)
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
				std::cout << " " << env->Cases()[i][j]->Poussiere() << "|" << env->Cases()[i][j]->Jewels() << ((asp->CurrentRoom() == env->Cases()[i][j]) ? "*" : " ");
			}
			std::cout << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		system("cls");
	}
}
