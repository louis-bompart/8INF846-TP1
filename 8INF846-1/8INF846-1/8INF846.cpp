#include <iostream>
#include <chrono>
#include <thread>
#include "Environnement.h"
#include "Aspirateur.h"

int main()
{
    Environnement* env = new Environnement();
    Aspirateur* asp = new Aspirateur();
    std::thread thread_env;
    std::thread thread_asp;

    while (true) {
        thread_env = std::thread(&Environnement::Execute, env);
        thread_asp = std::thread(&Aspirateur::Execute, asp);

        for (unsigned int i = 0; i < env->Cases().size(); i++) {
            for (unsigned int j = 0; j < env->Cases()[i].size(); j++) {
                std::cout << "*" ;
            }
            std::cout << std::endl;
        }

        thread_env.join();
        thread_asp.join();

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        system("cls");
    }

    system("PAUSE");
    return 0;
}

