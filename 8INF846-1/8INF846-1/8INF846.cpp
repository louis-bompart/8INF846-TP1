#include <iostream>
#include <chrono>
#include <thread>
#include "GlobalEnvironnement.h"
#include "Aspirateur.h"
#include "Affichage.h"

int main()
{
	GlobalEnvironnement* env = GlobalEnvironnement::GetInstance();
    Aspirateur* asp = new Aspirateur(env->Cases()[0][0]);
	Affichage* aff = new Affichage(env, asp);

    std::thread thread_env;
    std::thread thread_asp;
	std::thread thread_aff;

	thread_env = std::thread(&GlobalEnvironnement::Execute, env);
	thread_asp = std::thread(&Aspirateur::Execute, asp);
	thread_aff = std::thread(&Affichage::Execute, aff);

	thread_env.join();
	thread_asp.join();
	thread_aff.join();

	/*
    while (true) {

        thread_env = std::thread(&Environnement::Execute, env);
        thread_asp = std::thread(&Aspirateur::Execute, asp);

        thread_env.join();
        thread_asp.join();
		
		for (unsigned int i = 0; i < env->Cases().size(); i++) {
			for (unsigned int j = 0; j < env->Cases()[i].size(); j++) {
				std::cout << " " << env->Cases()[i][j]->Poussiere() << "|" << env->Cases()[i][j]->Jewels() << ((asp->CurrentRoom() == env->Cases()[i][j]) ? "*" : " ");
			}
			std::cout << std::endl;
		}
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls");
    }*/

    system("PAUSE");
    return 0;
}

