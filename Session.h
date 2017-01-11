#include <string>

class Session
{
	std::string debut; 		// date de début de session
	std::string fin; 		// date de fin de session 
	std::string derniere;	// date de la dernière session
	
	
	public:
	Session();
	void set_debut(std::string);
	std::string get_debut();
	void set_fin(std::string);
	std::string get_fin();
	void set_derniere(std::string);
	std::string get_derniere();
	std::string get_time();
	double Diff_time(std::string , std::string);
};
