#include <iostream>
#include <stdlib.h> // atoi
#include "Caracteristique.h"

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
	
	void Caracteristique::manger()
	{
		int faim = atoi(get_faim());
		return set_faim(faim+10);
	}
	
	void Caracteristique::laver()
	{
		int lave = atoi(get_proprete());
		return set_proprete(lave+10);
	}
	
	void Caracteristique::soigner()
	{
		int soin = atoi(get_vie());
		return set_vie(soin+10);
	}
	
	void Caracteristique::jouer()
	{
		int joue = atoi(get_humeur());
		fatigue();
		
	}
	
	void Caracteristique::fatigue()
	{
		
	}
