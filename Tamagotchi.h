#include <string>
#include "Caracteristique.h"

using namespace std;

class Tamagotchi 
{
	string nom;
	string type;
	string genre;
	string temperament; 		//Temperament qui influe le multiplicateur de la classe Caracteristique
	Caracteristique carac;
	string date;
	
	public:
	void set_nom(string);
	string get_nom();
	void set_type(string);
	string get_type();
	void set_genre(string);
	string get_genre();
	void set_temperament(string);
	string get_temperament();
	void set_carac(caracteristique);
	Caracteristique get_carac();
	void set_date(string);
	string get_date();
};

