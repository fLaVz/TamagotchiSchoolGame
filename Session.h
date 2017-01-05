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
	int compare_day(std::string, std::string);
	int compare_month(std::string, std::string);
	int compare_hours(std::string, std::string);
	int compare_minutes(std::string, std::string);
	//void up_caracteristics(std::string, std::string)
};
