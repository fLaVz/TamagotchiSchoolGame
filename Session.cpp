#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Session.h"

using namespace std;

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
	
	// fonction qui renvoie la date m/j/a h:min:s
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
	
	// fonction qui compare les jours de deux dates (début,fin)
	int Session::compare_day(string d, string d2)
	{
		string str;
		string str2;
		str = d.substr(3,2);
		str2 = d2.substr(3,2);
		int tmp;
		int tmp2;
		tmp = stoi(str);	//stoi = atoi en plus récent
		tmp2 = stoi(str2);
		if(tmp == tmp2)
		{
			return 0;
		}
		else
		{
			return (tmp2 - tmp);
		}
	}
	
	// fonction qui compare les mois de deux dates (début, fin)
	int Session::compare_month(string m, string m2)
	{
		string str;
		string str2;
		str = m.substr(0,2);
		str2 = m2.substr(0,2);
		int tmp;
		int tmp2;
		tmp = stoi(str);
		tmp2 = stoi(str2);
		if(tmp == tmp2)
		{
			return 0;
		}
		else
		{
			return (tmp2 - tmp);
		}
	}
	
	// fonction qui compare les heures de deux dates (début, fin)
	int Session::compare_hours(string h, string h2)
	{
		string str;
		string str2;
		str = h.substr(11,2);
		str2 = h2.substr(11,2);
		int tmp;
		int tmp2;
		tmp = stoi(str);
		tmp2 = stoi(str2);
		if(tmp == tmp2)
		{
			return 0;
		}
		else
		{
			return (tmp2 - tmp);
		}
	}
	
	// fonction qui compare les minutes de deux dates (début, fin)
	int Session::compare_minutes(string mi, string mi2)
	{
		string str;
		string str2;
		str = mi.substr(14,2);
		str2 = mi2.substr(14,2);
		int tmp;
		int tmp2;
		tmp = stoi(str);
		tmp2 = stoi(str2);
		if(tmp == tmp2)
		{
			return 0;
		}
		else
		{
			return (tmp2 - tmp);
		}
	}
	
	//TODO : faire le mixe des fonctions de comparaison des dates afin de vérifier comment gérer les caractéristiques plus tard. Plus vérifier par rapport aux changements de mois/jour/heure

