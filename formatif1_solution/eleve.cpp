#include "eleve.h"
#include <conio.h>
Eleve::Eleve()
{
	codeEleve = "";
	nomEleve = "inconu";
	prenomEleve = "";
	activiteInscrite = NULL;
}
Eleve::Eleve(string inCodeEleve, string inNomEleve, string inPrenomEleve)
{
	codeEleve = inCodeEleve;
	nomEleve = inNomEleve;
	prenomEleve = inPrenomEleve;
	activiteInscrite = NULL;
}


string Eleve::getCodeEleve()
{
	return codeEleve;
}
string Eleve::getNom()
{
	return nomEleve;
}
string Eleve::getPrenom()
{
	return prenomEleve;
}
Activite *Eleve::getActiviteInscrite()
{
	return activiteInscrite;
}

void Eleve:: InscrireEleve(string inCodeEleve, string inNomEleve, string inPrenomEleve)
{

	codeEleve= inCodeEleve;
	nomEleve= inNomEleve;
	prenomEleve= inPrenomEleve;

}
void Eleve::InscrireEleveAUneActivite(Activite* inActivite)
{
	if (inActivite != NULL)
	{
		activiteInscrite = inActivite;
	}
}
