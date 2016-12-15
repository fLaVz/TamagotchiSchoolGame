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
	
	/*
	// fonction qui renvoie l'heure courante
	string Session::time()
	{
		time_t timer;
		time(&timer);
		return ctime(&timer);
		
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
	
	
	
	*/
