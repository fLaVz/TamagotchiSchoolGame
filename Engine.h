#ifndef Engine_H
#define Engine_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Tamagotchi.h"
#include "Session.h"


//CETTE CLASSE CONTIENT LES PARAMETRES DU JEU

class Engine {

	std::string m_gameState;
	Session s;
	

public: 

	Engine();

	/////////// MUTATEURS ET ACCESSEURS /////////////
	void setGameState(std::string gameState);
	std::string getGameState();
	/////////////////////////////////////////////////

	void load(Tamagotchi & t);
	void save(Tamagotchi t);


	void action(std::string act);
	void update(Tamagotchi t);
	

};
#endif
