#include <string>

class Session
{
	string debut; 		// date de début de session
	string fin; 		// date de fin de session 
	string derniere;	// date de la dernière session
	
	public:
	void set_debut(string);
	string get_debut();
	void set_fin(string);
	string get_fin();
	void set_derniere(string);
	string get_derniere();
};