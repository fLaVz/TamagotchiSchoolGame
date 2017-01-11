#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "button.h"
#include "Tamagotchi.h"
#include "text.h"

using namespace std;
using namespace sf;

int main()
{

    // Initialisation du jeu et de sa gestion
    Engine game;
    Tamagotchi t;
    
    // Initialisation de la fenetre de rendu
    RenderWindow window(VideoMode(1280, 720), "TAMAGOTCHI v1.0");
    
    // Initialisation des boutons
    button backGround("background", Vector2f(0, 0));
    button newgame("newgame", Vector2f(280, 300));
    button cont("continue", Vector2f(700, 300));
    button food("eat", Vector2f(50, 500));
    button goSleep("sleep", Vector2f(350, 500));
    button goOut("out", Vector2f(650, 500));
    button proceed("continue", Vector2f(500, 300));
    button dayBackGround("day", Vector2f(0, 0));
    button nightBackGround("night", Vector2f(0, 0));
      
    //button newgamepause("newgame", Vector2f(250, 450));

    // Initialisation des texts afichés a l'écran avec leur couleurs
    Color red = Color::Red;
    Color green = Color::Green;
    Color white = Color::White;

    text life("Vie :", green, 1000, 200);
    text faim("Faim :", red, 1000, 250);
    text proprete("Proprete :", white, 1000, 300);
    text fatigue("Fatigue :", white, 1000, 350);
    text humeur("Humeur :", white, 1000, 400);


    // Initialisation de la gestion du temps
    Clock clock;


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
                game.update(t, life, faim, proprete, fatigue, humeur, elapsed);
                game.setGameState("RUN");
            }else if(cont.isClicked(window)) {
                game.load(t);
                game.update(t, life, faim, proprete, fatigue, humeur, elapsed);
                game.setGameState("RUN");
            }
        }   


        if(game.getGameState() == "RUN") {

            dayBackGround.drawButton(window);

            if(game.getNightMode() == 1)
                nightBackGround.drawButton(window);

            // Affichage des différents éléments d'information du tamagotchi
            life.drawText(window);
            faim.drawText(window);
            proprete.drawText(window);
            fatigue.drawText(window);
            humeur.drawText(window);

            // Affichage des boutons d'action
            food.drawButton(window);
            goSleep.drawButton(window);
            goOut.drawButton(window);

            // Si donner a manger et cliqué, et que le temps écoulé est superieur a 5 secondes
            if(food.isClicked(window) && elapsed.asSeconds() > 5) {

                t.set_vie(t.get_vie() + 20);
                elapsed = clock.restart();
                game.setGameState("WAIT");

            }else if(goSleep.isClicked(window) && elapsed.asSeconds() > 5) {

                
                elapsed = clock.restart();

            }else if(goOut.isClicked(window) && elapsed.asSeconds() > 60) {

            }
        }

        if(game.getGameState() == "WAIT") {
            
            proceed.drawButton(window);

            if(proceed.isClicked(window)) {
                game.update(t, life, faim, proprete, fatigue, humeur, elapsed);
                game.save(t);
                game.setGameState("RUN");
            }
        }
        
        window.display();
    }
    ////////////////FIN INTERFACE GRAPHIQUE///////////////////
    
	return 0;
}

