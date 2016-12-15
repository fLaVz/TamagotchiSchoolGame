#include "Engine.h"
#include <sstream>

using namespace std;

Engine::Engine() {

	m_gameState = "INIT";

}

void Engine::setGameState(string gameState) {

	m_gameState = gameState;

}

string Engine::getGameState() {

	return m_gameState;
}


void Engine::load() {

	ifstream file("saved/save.dat", ios::in);  // on ouvre le fichier

    if(file) {

    	string tab[10];
    	int i = 0;

      string line;
    	istringstream iss(line);
  		string s;

  		while (getline(iss, s, ' ' ) ) {
    		printf( "`%s'\n", s.c_str() );
    		tab[i] = s.c_str();
  		}

    	file.close();
    }
    else {
    	cerr << "Impossible d'ouvrir le fichier !" << endl;
    }  
}