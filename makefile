game:		main.o Engine.o button.o Tamagotchi.o Session.o text.o
			g++ *.o -o game -lsfml-graphics -lsfml-window -lsfml-system

main.o:		main.cpp Engine.h button.h Tamagotchi.h text.h
			g++ -c main.cpp -I SFML/include

text.o:		text.cpp text.h
			g++ -c text.cpp -I SFML/include

Tamagotchi.o:	Tamagotchi.cpp Tamagotchi.h
			g++ -c Tamagotchi.cpp -I SFML/include

Engine.o:	Engine.cpp Engine.h Tamagotchi.h
			g++ -c Engine.cpp -I SFML/include

button.o:	button.cpp button.h
			g++ -c button.cpp -I SFML/include

Session.o: 	Session.cpp Session.h
			g++ -c Session.cpp -I SFML/include

clean:	
			rm -f *.o

mrproper: 	clean
			rm -f game