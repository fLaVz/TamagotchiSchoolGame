#include "Tamagotchi.h"

using namespace std;

Tamagotchi::Tamagotchi() {

	nom = "name";
	type = "type";
	genre = "gender";
	temperament = "temp";
	date = "default";

	vie = 100;
	faim = 0;
	proprete = 100;
	humeur = "default";
	fatigue = 0;
	experience = 0;
	multiplicateur = 1;
}


	void Tamagotchi::set_nom(string s)
	{
		nom = s;
	}
	
	
	string Tamagotchi::get_nom()
	{
		return nom;
	}
	
	void Tamagotchi::set_type(string s)
	{
		type = s;
	}
	
	string Tamagotchi::get_type()
	{
		return type;
	}
	
	void Tamagotchi::set_genre(string s)
	{
		genre = s;
	}
	
	string Tamagotchi::get_genre()
	{
		return genre;
	}
	
	void Tamagotchi::set_temperament(string s)
	{
		temperament = s;
	}
	
	string Tamagotchi::get_temperament()
	{
		return temperament;
	}
	
	
	void Tamagotchi::set_date(string s)
	{
		date = s;
	}
	
	string Tamagotchi::get_date()
	{
		return date;
	}
	
	void Tamagotchi::set_vie(int i)
	{
		vie = i;
		cout << "vie : " << vie << endl;
	}
	
	int Tamagotchi::get_vie()
	{
		return vie;
	}
	
	void Tamagotchi::set_faim(int i)
	{
		faim = i;
	}
	
	int Tamagotchi::get_faim()
	{
		return faim;
	}
	
	void Tamagotchi::set_proprete(int i)
	{
		proprete = i;
	}
	
	int Tamagotchi::get_proprete()
	{
		return proprete;
	}
	
	void Tamagotchi::set_humeur(int i)
	{
		humeur = i;
	}
	
	string Tamagotchi::get_humeur()
	{
		return humeur;
	}
	
	void Tamagotchi::set_fatigue(int i)
	{
		fatigue = i;
	}
	
	int Tamagotchi::get_fatigue()
	{
		return fatigue;
	}
	
	void Tamagotchi::set_experience(int i)
	{
		experience = i;
	}
	
	int Tamagotchi::get_experience()
	{
		return experience;
	}
	
	void Tamagotchi::set_multiplicateur(int i)
	{
		multiplicateur = i;
	}
	
	int Tamagotchi::get_multiplicateur()
	{
		return multiplicateur;
	}
	
	//Fonction qui réduit la faim
	void Tamagotchi::manger()
	{
		int faim = get_faim();
		set_faim(faim-10);
	}
	
	//Fonction qui augmente la propreté
	void Tamagotchi::laver()
	{
		int lave = get_proprete();
		set_proprete(lave+10);
	}
	
	//Fonction qui augmente la vie
	void Tamagotchi::soigner()
	{
		int soin = get_vie();
		set_vie(soin+10);
	}
	
	//Fonction qui augmente l'humeur et la fatigue
	void Tamagotchi::jouer()
	{
		//int joue = atoi(get_humeur());
		int fatiguee = get_fatigue();
		//set_humeur(joue+10);
		set_fatigue(fatiguee+10);
	}
	
	/*void Tamagotchi::dormir() // fonction qui régénère la fatigue suivant le temps entre deux sessions?
	{
		
	}
	
	bool Tamagotchi::mort()
	{
		if(get_vie() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	*/
