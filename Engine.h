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

	int update(Tamagotchi & t, text &life, text &faim, text &proprete, text &fatigue, text &humeur, sf::Time &elapsed, sf::Clock &clock);
	bool isDead(Tamagotchi &t);
	void checkDiff(double diff, Tamagotchi &t);

	int eat(Tamagotchi &t);
	int wash(Tamagotchi &t);
	int play(Tamagotchi &t);
	int sleep(Tamagotchi &t);



};
#endif
