#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "button.h"

using namespace std;
using namespace sf;


int main()
{

    // Initialisation du jeu
    Engine game;
    
    
    //Initialisation de la fenetre de rendu
    RenderWindow window(VideoMode(800, 600), "TAMAGOTCHI v1.0");
   // window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    
    //Initialisation des boutons
    button backGround("background", Vector2f(0, 0));
    /*
    button newgame("newgame", Vector2f(50, 150));
    button loadGame("load", Vector2f(50, 250));
    button leave("leave", Vector2f(50, 350));
    button classic("classic", Vector2f(300, 150));
    button perso("perso", Vector2f(300, 250));
    button pvp("pvp", Vector2f(150, 250));
    button pvia("pvia", Vector2f(450, 250));
    button save("save", Vector2f(100, 350));
    button load("load", Vector2f(450, 450));
    button cont("cont", Vector2f(450, 350));
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


        


       
        
        window.display();
    }
    ////////////////FIN INTERFACE GRAPHIQUE///////////////////
    
	return 0;
}

