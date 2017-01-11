#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include "Session.h"

using namespace std;

	Session::Session()
	{
		debut = fin = get_time();
	}

	void Session::set_debut(string s)
	{
		debut = s;
	}
	
	string Session::get_debut()
	{
		return debut;
	}
	
	void Session::set_fin(string s)
	{
		fin = s;
	}
	
	string Session::get_fin()
	{
		return fin;
	}
	
	void Session::set_derniere(string s)
	{
		derniere = s;
	}
	
	string Session::get_derniere()
	{
		return derniere;
	}
	
	
	// Fonction qui renvoie la date a-m-j h:min:s
	string Session::get_time()
	{
		time_t rawtime;
		struct tm * timeinfo;
		char buffer [80];
		string s;

		time (&rawtime);
		timeinfo = localtime (&rawtime);

		strftime (buffer,80,"%F %T",timeinfo);
		s = buffer;
		return s;
	}
	
	// Fonction qui calcule la différence entre deux temps donnés
	double Session::Diff_time(string fin, string debut)
	{
		struct tm tm1;
		struct tm tm2;
		 
		char buf1[255], buf2[255];
		double dif;
		 
		strptime(fin.c_str(), "%Y-%m-%d %H:%M:%S", &tm1);
		strftime(buf1, sizeof(buf1), "%d %b %Y %H:%M:%S", &tm1);
		puts(buf1);
		 
		strptime(debut.c_str(), "%Y-%m-%d %H:%M:%S", &tm2);
		strftime(buf2, sizeof(buf2), "%d %b %Y %H:%M:%S", &tm2);
		puts(buf2);
		time_t  T1= mktime(&tm1);
		time_t T2 = mktime(&tm2);
		dif = difftime(T2,T1);
		return dif;
	}

	
	
	
	
	
	
	
	
	//TODO : faire le mixe des fonctions de comparaison des dates afin de vérifier comment gérer les caractéristiques plus tard. Plus vérifier par rapport aux changements de mois/jour/heure
	
	/*
	//Fonction qui gère les caractéristiques suivant le temps entre deux sessions
	void Session::up_caracteristics(string start, string end)
	{
		if(compare_day(start,end) >= 1 || compare_day(start,end) <= -1 || compare_month(start,end) >= 1 || compare_month(start,end) <= -1)
		{
			Tamagotchi::set_vie(0);
		}
		if(compare_hours(start,end) >= 12 || compare_hours(start,end) <= -12)
		{
			int vie = Tamagotchi::get_vie();
			Tamagotchi::set_vie(vie-60);
			int faim = Tamagotchi::get_faim();
			Tamagotchi::set_faim(faim+60);
			int humeur = Tamagotchi::get_humeur();
			Tamagotchi::set_humeur(humeur-60);
		}
		if((compare_hours(start,end) >=6 && compare_hours(start,end) < 12) || (compare_hours(start,end) <= -6 && compare_hours(start,end) > -12))
		{
			int vie = Tamagotchi::get_vie();
			Tamagotchi::set_vie(vie-30);
			int faim = Tamagotchi::get_faim();
			Tamagotchi::set_faim(faim+30);
			int humeur = Tamagotchi::get_humeur();
			Tamagotchi::set_humeur(humeur-30);
		}
		if(compare_hours(start,end) < 6 || compare_hours(start,end) > -6)
		{
			int vie = Tamagotchi::get_vie();
			Tamagotchi::set_vie(vie-10);
			int faim = Tamagotchi::get_faim();
			Tamagotchi::set_faim(faim+10);
			int humeur = Tamagotchi::get_humeur();
			Tamagotchi::set_humeur(humeur-10);
		}
	}
	
	*/

