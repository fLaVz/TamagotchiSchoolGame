#ifndef Engine_H
#define Engine_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Tamagotchi.h"
#include "Session.h"
#include "text.h"


//CETTE CLASSE CONTIENT LES PARAMETRES DU JEU

class Engine {

	int nightMode;
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


	int getNightMode();
	void update(Tamagotchi & t, text &life, text &faim, text &proprete, text &fatigue, text &humeur, sf::Time elapsed);

	

};
#endif
