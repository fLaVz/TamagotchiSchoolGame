#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "button.h"
#include "Tamagotchi.h"
#include "text.h"

using namespace std;
using namespace sf;

int main() {

    // Initialisation du jeu et de sa gestion
    Engine game;
    Tamagotchi t;
    
    string name;
    cout << "Entrez le nom de votre Tamagotchi ! " << endl;
    cin >> name;
    t.set_nom(name);



    // Initialisation de la fenetre de rendu
    RenderWindow window(VideoMode(1280, 720), "TAMAGOTCHI v1.0");
    
    // Initialisation des boutons
    button backGround("backGround", Vector2f(0, 0));
    button newgame("newgame", Vector2f(280, 300));
    button cont("continue", Vector2f(700, 300));
    button food("eat", Vector2f(50, 550));
    button goSleep("sleep", Vector2f(250, 550));
    button play("play", Vector2f(450, 550));
    button wash("wash", Vector2f(650, 550));
    button proceed("continue", Vector2f(500, 300));
    button dayBackGround("daybackGround", Vector2f(0, 0));
    button nightBackGround("nightbackGround", Vector2f(0, 0));

    // Initialisation des images par rapport aux points d'etats
    button coeur("coeur", Vector2f(1130, 200));
    button fourk("fork", Vector2f(1130, 250));
    button shower("shower", Vector2f(1130, 300));
    button zzz("zzz", Vector2f(1130, 350));
    button feel("feel", Vector2f(1130, 400));

    button tama("tama", Vector2f(400, 350));
      
    //button newgamepause("newgame", Vector2f(250, 450));

    // Initialisation des texts afichés a l'écran avec leur couleurs
    Color red = Color::Red;
    Color green = Color::Green;
    Color white = Color::White;

    text life("100", green, 1200, 200);
    text faim("0", red, 1200, 250);
    text proprete("100", white, 1200, 300);
    text fatigue("0", white, 1200, 350);
    text humeur("100", white, 1200, 400);


    // Initialisation de la gestion du temps
    Clock clock;


    // manger dormir jouer laver


    /////////////////PARTIE INTERFACE GRAPHIQUE/////////////////////

    // Boucle de jeu avec un gamestate pour gerer l'interface graphique
    while(window.isOpen())
    {
    
        Event event;                            // Traite les évènements
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed) {    // Si on click sur la croix rouge
                game.save(t);
                window.close();
            }
            if(event.type == Event::KeyPressed) {
                // Si la touche echap est préssée et qu'on est dans une partie
                if(event.key.code == Keyboard::Escape && game.getGameState() == "RUN")
                    game.setGameState("PAUSE");

            }
        }

        window.clear();
        
        // Recupération du temps écoulé a chaque tour de boucle
        Time elapsed = clock.getElapsedTime();

        if(game.getGameState() == "MENU1") {

            backGround.drawButton(window);
            newgame.drawButton(window);
            cont.drawButton(window);

            if(newgame.isClicked(window)) {
                
                game.setGameState("RUN");
            }else if(cont.isClicked(window)) {
                game.load(t);
                //game.update(t, life, faim, proprete, fatigue, humeur, elapsed);
                game.setGameState("RUN");
            }
        }   


        if(game.getGameState() == "RUN") {

            dayBackGround.drawButton(window);
            tama.drawButton(window);

            // Affichage des différents éléments d'information du tamagotchi
            life.drawText(window);
            faim.drawText(window);
            proprete.drawText(window);
            fatigue.drawText(window);
            humeur.drawText(window);

            // Affichage des images descriptives
            coeur.drawButton(window);
            fourk.drawButton(window);
            shower.drawButton(window);
            zzz.drawButton(window);
            feel.drawButton(window);

            // Affichage des boutons d'action
            food.drawButton(window);
            goSleep.drawButton(window);
            play.drawButton(window);
            wash.drawButton(window);

            //***************************** ACTIONS
            // Si donner a manger et cliqué, et que le temps écoulé est superieur a 5 secondes
            if(food.isClicked(window) && elapsed.asSeconds() > 5) {

                game.eat(t);
                elapsed = clock.restart();
                game.setGameState("WAIT");

            }else if(goSleep.isClicked(window) && elapsed.asSeconds() > 5) {

                game.sleep(t);
                elapsed = clock.restart();
                game.setGameState("SLEEP");

            }else if(play.isClicked(window) && elapsed.asSeconds() > 5) {
                game.play(t);
                elapsed = clock.restart();
                game.setGameState("WAIT");

            }else if(wash.isClicked(window) && elapsed.asSeconds() > 5) {
                game.wash(t);
                elapsed = clock.restart();
                game.setGameState("WAIT");

            }
        }

        //************************ PROCEED
        if(game.getGameState() == "WAIT") {

                backGround.drawButton(window);
                proceed.drawButton(window);

                // Aurait pu etre géré avec clock mais fait de facon a economiser des ressources -> rallonge le code
                if(proceed.isClicked(window)) {
                    
                    game.save(t);
                    game.setGameState("RUN");
                }
        }

        //**************************** SLEEP MODE
        if(game.getGameState() == "SLEEP") {

            nightBackGround.drawButton(window);
            tama.drawButton(window);

            if(elapsed.asSeconds() > 10) {
                game.setGameState("RUN");
            }

        }
        //************************ UPDATE APP
        int r = game.update(t, life, faim, proprete, fatigue, humeur, elapsed, clock);
        if(r == 1) {
            cout << "GAAAAAAAAAAME OVERRRRRR" << endl;
            window.close();
        }



        window.display();
    }
    ////////////////FIN INTERFACE GRAPHIQUE///////////////////
    
	return 0;
}

