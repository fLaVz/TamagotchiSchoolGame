#ifndef Tamagotchi_H
#define Tamagotchi_H


#include <iostream>
#include <stdlib.h>
#include <ctime>

class Tamagotchi 
{
	std::string nom;
	std::string type;
	std::string genre;
	std::string temperament; 		//Temperament qui influe le multiplicateur de la classe Caracteristique
	std::string date;

	int vie;
	int faim;
	int proprete;
	std::string humeur;
	int fatigue;
	int experience;
	int multiplicateur;
	
	public:

	Tamagotchi();

	void set_nom(std::string m_nom);
	std::string get_nom();
	void set_type(std::string m_type);
	std::string get_type();
	void set_genre(std::string m_genre);
	std::string get_genre();
	void set_temperament(std::string m_temp);
	std::string get_temperament();
	void set_date(std::string m_date);
	std::string get_date();


	void set_vie(int);
	int get_vie();
	void set_faim(int);
	int get_faim();
	void set_proprete(int);
	int get_proprete();
	void set_humeur(int);
	std::string get_humeur();
	void set_fatigue(int);
	int get_fatigue();
	void set_experience(int);
	int get_experience();
	void set_multiplicateur(int);
	int get_multiplicateur();
	
	void manger();
	void laver();
	void soigner();
	void jouer();
	//void dormir();
};
#endif