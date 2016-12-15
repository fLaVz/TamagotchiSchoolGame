game:		main.o Engine.o button.o
			g++ *.o -o game -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o:		main.cpp Engine.h
			g++ -c main.cpp -I SFML/include

Engine.o:	Engine.cpp Engine.h
			g++ -c Engine.cpp -I SFML/include

button.o:	button.cpp button.h
			g++ -c button.cpp -I SFML/include

clean:	
			rm -f *.o

mrproper: 	clean
			rm -f game