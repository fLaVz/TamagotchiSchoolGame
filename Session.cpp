#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Session.h"

using namespace std;

	Session::Session()
	{
		debut = fin = derniere = get_time();
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
	
	// Fonction qui renvoie la date m/j/a h:min:s
	string Session::get_time()
	{
		time_t rawtime;
		struct tm * timeinfo;
		char buffer [80];
		string s;

		time (&rawtime);
		timeinfo = localtime (&rawtime);

		strftime (buffer,80,"%x %X",timeinfo);
		s = buffer;
		return s;
	}
	
	// Fonction qui compare les jours de deux dates (début,fin)
	int Session::compare_day(string d, string d2)
	{
		string str;
		string str2;
		str = d.substr(3,2);
		str2 = d2.substr(3,2);
		int tmp;
		int tmp2;
		tmp = atoi(str.c_str());	//stoi = atoi en plus récent
		tmp2 = atoi(str2.c_str());
		if(tmp == tmp2)
		{
			return 0;
		}
		else
		{
			return (tmp2 - tmp);
		}
	}
	
	// Fonction qui compare les mois de deux dates (début, fin)
	int Session::compare_month(string m, string m2)
	{
		string str;
		string str2;
		str = m.substr(0,2);
		str2 = m2.substr(0,2);
		int tmp;
		int tmp2;
		tmp = atoi(str.c_str());
		tmp2 = atoi(str2.c_str());
		if(tmp == tmp2)
		{
			return 0;
		}
		else
		{
			return (tmp2 - tmp);
		}
	}
	
	// Fonction qui compare les heures de deux dates (début, fin)
	int Session::compare_hours(string h, string h2)
	{
		string str;
		string str2;
		str = h.substr(9,2);
		str2 = h2.substr(9,2);
		int tmp;
		int tmp2;
		tmp = atoi(str.c_str());
		tmp2 = atoi(str2.c_str());
		if(tmp == tmp2)
		{
			return 0;
		}
		else
		{
			return (tmp2 - tmp);
		}
	}
	
	// Fonction qui compare les minutes de deux dates (début, fin)
	int Session::compare_minutes(string mi, string mi2)
	{
		string str;
		string str2;
		str = mi.substr(12,2);
		str2 = mi2.substr(12,2);
		int tmp;
		int tmp2;
		tmp = atoi(str.c_str());
		tmp2 = atoi(str2.c_str());
		if(tmp == tmp2)
		{
			return 0;
		}
		else if ((tmp2 - tmp) < 0)
		{
			return (-1 * (tmp2-tmp));
		} 
		else
		{
			return (tmp2 - tmp);
		}
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

