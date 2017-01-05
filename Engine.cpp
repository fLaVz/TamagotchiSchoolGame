#include "Engine.h"
#include <sstream>

using namespace std;

Engine::Engine() {

	m_gameState = "MENU1";

}

void Engine::setGameState(string gameState) {

	m_gameState = gameState;

}

string Engine::getGameState() {

	return m_gameState;
}


void Engine::action(string act) {


}


void Engine::load() {

  string chaine[10];
  int num[10];

	/*ifstream file("saved/save.dat", ios::in);  // on ouvre le fichier

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
    } */ 
}
/*

Schema pour la sauvegarde fichier :

cf Tamagotchi.h -> meme architecture string + int




*/

void Engine::save(Tamagotchi t) {

  string path = "saved/save.dat";

  ofstream file(path.c_str(), ios::out | ios::trunc);

      if(file) {

        file << "[STRING]" << endl;
        file << t.get_nom() << endl;
        file << t.get_type() << endl;
        file << t.get_genre() << endl;
        file << t.get_temperament() << endl;
        file << t.get_date() << endl;

        file << "[INT]" << endl;
        file << t.get_vie() << endl;
        file << t.get_faim() << endl;
        file << t.get_proprete() << endl;
        file << t.get_humeur() << endl;
        file << t.get_fatigue() << endl;
        file << t.get_experience() << endl;
        file << t.get_multiplicateur() << endl;
        
        }else {
          cout << "Ouverture impossible !" << endl;
        }

        file.close();

  cout << "game succesfully saved !" << endl;

}