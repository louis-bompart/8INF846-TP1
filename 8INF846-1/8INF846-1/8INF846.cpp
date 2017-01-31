#include <iostream>
#include "Environnement.h"

int main()
{
    Environnement* env = new Environnement();
    while (true) {
        std::cout << "*************************" << std::endl;

        for (int i = 0; i < env->getEnv().size(); i++) {
            for (int i = 0; env->getEnv().size(); i++) {
                std::cout << "*" ;
            }
            std::cout << std::endl
        }

        system("cls");
    }

    system("PAUSE");
    return 0;
}

