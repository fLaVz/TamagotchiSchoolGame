#include <iostream>
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
