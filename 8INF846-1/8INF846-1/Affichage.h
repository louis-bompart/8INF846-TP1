#pragma once
#include "GlobalEnvironnement.h"
#include "Aspirateur.h"

class Affichage
{
public:
	Affichage(GlobalEnvironnement* env, Aspirateur* asp);
	~Affichage();

	void Execute();

private: 
	GlobalEnvironnement* env;
	Aspirateur* asp;
};

