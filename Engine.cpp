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


void Engine::load(Tamagotchi & t) {

  string chaine[10];
  int num[10];

	ifstream file("saved/save.dat", ios::in);  // on ouvre le fichier

    if(file) {
      string line;
      
      for(int i = 0; i < 5; i++) {
        getline(file, line);
        chaine[i] = line;
      }
      
      for(int i = 0; i < 7; i++) {
        getline(file, line);
        int tmp = atoi(line.c_str());
        num[i] = tmp;
      }
      file.close();
    }
    else {
    	cerr << "Impossible d'ouvrir le fichier !" << endl;
    }


    t.set_nom(chaine[0]);
    t.set_type(chaine[1]);
    t.set_genre(chaine[2]);
    t.set_temperament(chaine[3]);
    t.set_date(chaine[4]);

    t.set_vie(num[0]);
    t.set_faim(num[1]);
    t.set_proprete(num[2]);
    t.set_humeur(num[3]);
    t.set_fatigue(num[4]);
    t.set_experience(num[5]);
    t.set_multiplicateur(num[6]);

    cout << "Game successfully loaded" << endl;
}

void Engine::save(Tamagotchi t) {

  string path = "saved/save.dat";

  ofstream file(path.c_str(), ios::out | ios::trunc);

      if(file) {

        //file << "[STRING]" << endl;
        file << t.get_nom() << endl;
        file << t.get_type() << endl;
        file << t.get_genre() << endl;
        file << t.get_temperament() << endl;
        file << t.get_date() << endl;

        //file << "[INT]" << endl;m
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


void Engine::update(Tamagotchi & t, text & life) {

  int tmp = t.get_vie();

  stringstream flux;
  flux << tmp;

  string conv = flux.str();

  life.addText(conv);


}