

class Caracteristique
{
	int vie;
	int faim;
	int proprete;
	int humeur;
	int fatigue;
	int experience;
	int multiplicateur;		//multiplicateur de gain ou perte de statistique par rapport au tempérament
	
	public:
	void set_vie(int);
	int get_vie();
	void set_faim(int);
	int get_faim();
	void set_proprete(int);
	int get_proprete();
	void set_humeur(int);
	int get_humeur();
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
	void fatigue();
	
};
