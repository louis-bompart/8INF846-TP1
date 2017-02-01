#pragma once
#include "Environnement.h"
#include "Aspirateur.h"

class Affichage
{
public:
	Affichage(Environnement* env, Aspirateur* asp);
	~Affichage();

	void Execute();

private: 
	Environnement* env;
	Aspirateur* asp;
};

