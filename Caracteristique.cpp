#include <iostream>
#include <stdlib.h> // atoi
#include <ctime> 	// time
#include "Caracteristique.h"
//#include "Session.h" // date pour les fonctions de fatigue et experience ?

using namespace std;

	void Caracteristique::set_vie(int i)
	{
		vie = i;
	}
	
	int Caracteristique::get_vie()
	{
		return vie;
	}
	
	void Caracteristique::set_faim(int i)
	{
		faim = i;
	}
	
	int Caracteristique::get_faim()
	{
		return faim;
	}
	
	void Caracteristique::set_proprete(int i)
	{
		proprete = i;
	}
	
	int Caracteristique::get_proprete()
	{
		return proprete;
	}
	
	void Caracteristique::set_humeur(int i)
	{
		humeur = i;
	}
	
	int Caracteristique::get_humeur()
	{
		return humeur;
	}
	
	void Caracteristique::set_fatigue(int i)
	{
		fatigue = i;
	}
	
	int Caracteristique::get_fatigue()
	{
		return fatigue;
	}
	
	void Caracteristique::set_experience(int i)
	{
		experience = i;
	}
	
	int Caracteristique::get_experience()
	{
		return experience;
	}
	
	void Caracteristique::set_multiplicateur(int i)
	{
		multiplicateur = i;
	}
	
	int Caracteristique::get_multiplicateur()
	{
		return multiplicateur;
	}
	
	//Fonction qui réduit la faim
	void Caracteristique::manger()
	{
		int faim = atoi(get_faim());
		set_faim(faim-10);
	}
	
	//Fonction qui augmente la propreté
	void Caracteristique::laver()
	{
		int lave = atoi(get_proprete());
		set_proprete(lave+10);
	}
	
	//Fonction qui augmente la vie
	void Caracteristique::soigner()
	{
		int soin = atoi(get_vie());
		set_vie(soin+10);
	}
	
	//Fonction qui augmente l'humeur et la fatigue
	void Caracteristique::jouer()
	{
		int joue = atoi(get_humeur());
		int fatiguee = atoi(get_fatigue());
		set_humeur(joue+10);
		set_fatigue(fatiguee+10);
	}
	
	/*void Caracteristique::dormir() // fonction qui régénère la fatigue suivant le temps entre deux sessions.
	{
		
	}*/
