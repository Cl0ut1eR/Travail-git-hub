#ifndef EleveH 
#define EleveH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include "activite.h"
using namespace std;

class Eleve
{
private:
	string codeEleve;
	string nomEleve;
	string prenomEleve;
	Activite* activiteInscrite = NULL;
public:
	Eleve();
	Eleve(string CodeEleve, string NomEleve, string PrenomEleve);

	string	getCodeEleve();
	string	getNom();
	string	getPrenom();
	Activite * getActiviteInscrite();
	void	InscrireEleve(string inCodeEleve, string inNomEleve, string inPrenomEleve);
	void	InscrireEleveAUneActivite(Activite *inActiviteInscrite);


};






#endif

