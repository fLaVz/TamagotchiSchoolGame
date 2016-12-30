#ifndef Engine_H
#define Engine_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Tamagotchi.h"


//CETTE CLASSE CONTIENT LES PARAMETRES DU JEU

class Engine {

	std::string m_gameState;
	

public: 

	Engine();

	/////////// MUTATEURS ET ACCESSEURS /////////////
	void setGameState(std::string gameState);
	std::string getGameState();
	/////////////////////////////////////////////////

	void load();

	void action(std::string act);
	

};
#endif
