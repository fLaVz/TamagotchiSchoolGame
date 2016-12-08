#ifndef jeu_H
#define jeu_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

//CETTE CLASSE CONTIENT LES PARAMETRES DU JEU

class Engine {

	string m_gameState;

public: 

	Engine();

	/////////// MUTATEURS ET ACCESSEURS /////////////
	void setGameState(string gameState);
	string getGameState();
	/////////////////////////////////////////////////
	
	void loadGame();
	

};
#endif
