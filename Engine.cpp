#include "Engine.h"
#include <sstream>

using namespace std;
using namespace sf;

Engine::Engine() {

	m_gameState = "MENU1";

}

void Engine::setGameState(string gameState) {

	m_gameState = gameState;

}

string Engine::getGameState() {

	return m_gameState;
}

void Engine::checkDiff(double diff, Tamagotchi &t) {

  if(diff <= 7200) {
    cout << "Not enough time between 2 sessions to affect the stats" << endl;
  }
  else if(diff >= 7200){

    int cmp = (diff/7200)*10;

    t.set_vie(t.get_vie() - cmp);
    t.set_faim(t.get_faim() + cmp);
    t.set_proprete(t.get_proprete() - cmp);
    t.set_humeur(t.get_humeur() - cmp);
    t.set_fatigue(t.get_fatigue() + cmp);

  }
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

    ifstream filedate("saved/date.dat", ios::in);
    string linedate;

    if(filedate) {
      getline(filedate, linedate, '\n');
      filedate.close();
    }

    double diff = s.Diff_time(linedate, s.get_time());

    cout << "Diftime : " << diff << endl;

    checkDiff(diff, t);

 
    cout << "Game successfully loaded" << endl;
}




void Engine::save(Tamagotchi t) {

  // Sauvegarde des infos du tama

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

    // Sauvegarde de la date

    string pathdate = "saved/date.dat";

    ofstream filedate(pathdate.c_str(), ios::out | ios::trunc);

    if(filedate) {
      filedate << s.get_time();
    }

  cout << "game succesfully saved !" << endl;

}


int Engine::update(Tamagotchi & t, text &life, text &faim, text &proprete, text &fatigue, text &humeur, Time &elapsed, Clock &clock) {

  int tmp = t.get_vie();
  stringstream flux;
  flux << tmp;
  string conv = flux.str();
  life.addText(conv);

  // Reinitialise les flux
  flux.str("");

  tmp = t.get_faim();
  flux << tmp;
  conv = flux.str();
  faim.addText(conv);

  flux.str("");

  tmp = t.get_proprete();
  flux << tmp;
  conv = flux.str();
  proprete.addText(conv);

  flux.str("");

  tmp = t.get_fatigue();
  flux << tmp;
  conv = flux.str();
  fatigue.addText(conv);

  flux.str("");

  tmp = t.get_humeur();
  flux << tmp;
  conv = flux.str();
  humeur.addText(conv);

  flux.str("");

  



  // Acces en fonction du temps
  if(elapsed.asSeconds() > 10) {
    t.set_faim(t.get_faim() + 10);
    t.set_proprete(t.get_proprete() - 10); 
    t.set_humeur(t.get_humeur() - 10);

    elapsed = clock.restart();
    save(t);
  }

  /*if(elapsed.asSeconds() > 15) {
    t.set_proprete(t.get_proprete() - 10);
    elapsed = clock.restart();
    save(t);
  }  

  if(elapsed.asSeconds() > 15) {
    t.set_humeur(t.get_humeur() - 10);
    elapsed = clock.restart();
    save(t);
  }

  if(elapsed.asSeconds() > 1) {
    t.set_vie(t.get_vie() - 20);
    elapsed = clock.restart();
    save(t);
  }*/

  if(isDead(t)) {
    return 1;
  }

  return 0;
}





int Engine::eat(Tamagotchi &t) {

  if(t.get_vie() >= 100) {
    cout << "Full life" << endl;
  }else {
    t.set_vie(t.get_vie() + 10);
  }

  cout << "FAIMMMMMMMM" << t.get_faim() << endl; 

  if(t.get_faim() < 20) {
    return 0;
  }else if(t.get_faim() >= 20) {
    t.set_faim(t.get_faim() - 20);
  }else{
    return 1;
  }

  return 0;
}

int Engine::wash(Tamagotchi &t) {

  if(t.get_proprete() <= 80) {
    t.set_proprete(t.get_proprete() + 20);
  }else {
    t.set_humeur(t.get_humeur() - 40);
    cout << "Already clean, but bored by the shower ):" << endl;
  }
}


int Engine::play(Tamagotchi &t) {
  if(t.get_humeur() <= 80) {

    t.set_humeur(t.get_humeur() + 20);
    t.set_faim(t.get_faim() + 20);
  }else {
    t.set_vie(t.get_vie() - 40);
    cout << "Already enough happy !, but it hurts !" << endl;
  }


}


int Engine::sleep(Tamagotchi &t) {

  if(t.get_fatigue() >= 20) {
    t.set_fatigue(t.get_fatigue() - 20);
  }else{
    cout << "Not tired" << endl;
  }

}



bool Engine::isDead(Tamagotchi  &t) {

  if(t.get_vie() == 0
    || t.get_faim() == 100
    || t.get_proprete() == 0
    || t.get_humeur() == 0) {

    return true;
  }


  return false;
}