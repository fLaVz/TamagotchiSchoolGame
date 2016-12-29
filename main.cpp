#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "button.h"
#include "Tamagotchi.h"


using namespace std;
using namespace sf;


int main()
{

    // Initialisation du jeu
    Engine game;
    Tamagotchi t;
    
    
    //Initialisation de la fenetre de rendu
    RenderWindow window(VideoMode(1280, 720), "TAMAGOTCHI v1.0");
    
    //Initialisation des boutons
    button backGround("background", Vector2f(0, 0));
    button newgame("newgame", Vector2f(280, 300));
    button cont("continue", Vector2f(700, 300));
    button food("eat", Vector2f(50, 500));
    button goSleep("sleep", Vector2f(350, 500));
    button goOut("out", Vector2f(650, 500));
    button proceed("continue", Vector2f(500, 300));
    
/*
    button perso("perso", Vector2f(300, 250));
    button pvp("pvp", Vector2f(150, 250));
    button pvia("pvia", Vector2f(450, 250));
    button save("save", Vector2f(100, 350));
    button load("load", Vector2f(450, 450));
   
    button newgamepause("newgame", Vector2f(250, 450));
    */


    ///////////PARTIE INTERFACE GRAPHIQUE/////////////////////

    // Boucle de jeu avec un gamestate pour gerer ou non l'interface graphique
    while(window.isOpen())
    {
    
        Event event;                            // Traite les évènements
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)     // Si on click sur la croix rouge
                window.close(); 
            if(event.type == Event::KeyPressed) {
                // Si la touche echap est préssée et qu'on est dans une partie
                if(event.key.code == Keyboard::Escape && game.getGameState() == "RUN")
                    game.setGameState("PAUSE");

            }
        }

        window.clear();
        backGround.drawButton(window);

        if(game.getGameState() == "MENU1") {
            newgame.drawButton(window);
            cont.drawButton(window);

            if(newgame.isClicked(window)) {
                game.setGameState("RUN");
            }else if(cont.isClicked(window)) {
                game.load();
                game.setGameState("RUN");
            }
        }   


        if(game.getGameState() == "RUN") {

            food.drawButton(window);
            goSleep.drawButton(window);
            goOut.drawButton(window);

            if(food.isClicked(window)) {

                t.set_vie(t.get_vie() + 20);
                cout << "Action effectue ! " << endl;
                game.setGameState("WAIT");

            }else if(goSleep.isClicked(window)) {

            }else if(goOut.isClicked(window)) {

            }
        }

        if(game.getGameState() == "WAIT") {
            
            proceed.drawButton(window);
            if(proceed.isClicked(window))
                game.setGameState("RUN");
        }



        
        window.display();
    }
    ////////////////FIN INTERFACE GRAPHIQUE///////////////////
    
	return 0;
}

