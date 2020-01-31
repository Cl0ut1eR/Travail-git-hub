#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "..\screen\screen.h"
using namespace std;

#include "activite.h" 
#include "eleve.h" 

const int maxActivites = 10;
const int maxEleves = 25;

Activite lesActivites[maxActivites];

int nombreActivitesReelles = 0;
int nombreElevesReels = 0;

char AfficherMenu();
//partie 1
void AjouterActivite();
void AfficherLesActivites();
void Afficher(Activite);

//partie 2
Eleve TabEleves[maxEleves];
void AjouterLesEleves();
void AfficherLesEleves();
void InscrireUnEleve(string, string, string);
void Afficher(Eleve);

//partie 3
void InscrireEleveActivite();
int RechercherEleve(string eleveVoulu);
int RechercherActivite(string activiteVoulu);
void AfficherLesInscriptions();


int main()
{
	char choix = ' ';
	while (choix != '0')
	{
		choix = AfficherMenu();
		switch (choix)
		{
		case '1': AjouterActivite();
			break;
		case '2': AfficherLesActivites();
			break;
		case '3': AjouterLesEleves();
			break;
		case '4': AfficherLesEleves();
			break;
		case '5': InscrireEleveActivite();
			break;
		case '6': AfficherLesInscriptions();
			break;
		}
	}
}

//----------------------------------------------------------------------------------------
char AfficherMenu()
{
	char choix;
	ClrScr();
	Gotoxy(15, 4);
	cout << "1- Ajouter une activite";
	Gotoxy(15, 6);
	cout << "2- Afficher toutes les activites";
	Gotoxy(15, 8);
	cout << "3- Ajouter des eleves";
	Gotoxy(15, 10);
	cout << "4- Afficher les eleves";
	Gotoxy(15, 12);
	cout << "5- Inscrire un eleve a une activite";
	Gotoxy(15, 14);
	cout << "6- Afficher les inscriptions d'une activite";
	Gotoxy(15, 16);
	cout << "0- Arreter";
	Gotoxy(15, 18);
	cout << "Choix: ";
	cin >> choix;
	return choix;
}

//----------------------------------------------------------------------------------------

void Afficher(Activite inActivite)
{
	//if (inNewSection)
	//{
	//	cout << "\n\n";
	//}
	//cout << inTitre + " : " + inValue + "\n";

	cout << "Titre : " + inActivite.getTitre() + "\n";
	cout << "Responsable : " + inActivite.getResponsable() + "\n";
	cout << "Numero : " + inActivite.getCodeActivite()+"\n\n";
}

void Afficher(Eleve inEleve)
{
	cout << "Numero " + std::string(inEleve.getCodeEleve()) + "\n";
	cout << "Nom " + std::string(inEleve.getNom()) + "\n";
	cout << "Prenom " + std::string(inEleve.getPrenom()) + "\n\n";
}

//----------------------------------------------------------------------------------------
void AjouterActivite()
{
	string code;
	string titre;
	string responsable;
	ClrScr();
	cout << "Code activite: ";
	cin >> code;
	cout << "Titre: ";
	cin >> titre;
	cout << "Responsable: ";
	cin >> responsable;
	//ajoutez les instructions permettant d'inscrire la nouvelle activité dans le tableau des activités
	//utilisez nombreActivitesReelles comme indice pour le tableau

	/*lesActivites[nombreActivitesReelles].setCodeActivite(code);
	lesActivites[nombreActivitesReelles].setResponsable(responsable);
	lesActivites[nombreActivitesReelles].setTitre(titre);*/
	lesActivites[nombreActivitesReelles].AssignerResponsable(responsable);
	lesActivites[nombreActivitesReelles].InitialiserActivite(titre,code);
	

	nombreActivitesReelles++;
}

//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
void AfficherLesActivites()
{
	ClrScr();

	//for (int i = 0; i < nombreActivitesReelles; i++)
	//{

	//	Afficher("activite "+std::to_string(i+1), lesActivites[i].getTitre(), true);
	//	Afficher("responsable", lesActivites[i].getResponsable(), false);
	//	Afficher("numero", lesActivites[i].getCodeActivite(), false);

	//}

		for (int i = 0; i < nombreActivitesReelles; i++)
	{

			Afficher(lesActivites[i]);

	}




	_getch();
}

//----------------------------------------------------------------------------------------
void AjouterLesEleves()
{
	InscrireUnEleve("111", "Laroche", "Arthur");
	InscrireUnEleve("222", "Cailloux", "Fred");
	InscrireUnEleve("333", "Cailloux", "Delima");
	InscrireUnEleve("444", "Laroche", "Bertha");
	InscrireUnEleve("555", "Cailloux", "Agathe");
	InscrireUnEleve("666", "Laroche", "Boumboum");
	InscrireUnEleve("777", "Mirock", "Pierre");
	InscrireUnEleve("888", "Roche", "Onezime");
	InscrireUnEleve("999", "Roche", "Alfreda");
	InscrireUnEleve("112", "Cailloux", "Dino");
}

//----------------------------------------------------------------------------------------
void AfficherLesEleves()
{
	ClrScr();

	for (int i = 0; i < nombreElevesReels; i++)
	{
		Afficher(TabEleves[i]);
	}
	_getch();
}
//----------------------------------------------------------------------------------------
void InscrireUnEleve(string inCode, string inNom, string inPrenom)
{

	TabEleves[nombreElevesReels].InscrireEleve(inCode, inNom, inPrenom);
		nombreElevesReels++;
}

//----------------------------------------------------------------------------------------
void InscrireEleveActivite()
{
	string eleve;
	string activite;
	int cptEleve;
	int cptActivite;
	ClrScr();
	cout << "Code de l'eleve a inscrire: ";
	cin >> eleve;
	cptEleve = RechercherEleve(eleve);
	Afficher(TabEleves[cptEleve]);
	cout << "Activite desiree: ";
	cin >> activite;
	cptActivite = RechercherActivite(activite);
	Afficher(lesActivites[cptActivite]);

	TabEleves[cptEleve].InscrireEleveAUneActivite(&lesActivites[cptActivite]);


	_getch();
}

//----------------------------------------------------------------------------------------
int RechercherEleve(string inCodeVoulu)
{
	int cptEleve = -1;
	bool trouve = false;
	while (trouve == false && cptEleve < maxEleves)
	{
		cptEleve++;
		if (TabEleves[cptEleve].getCodeEleve() == inCodeVoulu)
		{
			trouve = 1;
		}
		

	}

	if (trouve == 0)
	{
		cptEleve = -1;
	}
	return cptEleve;
}

//----------------------------------------------------------------------------------------
int RechercherActivite(string inCodeActiviteVoulue)
{
	bool trouve = false;
	int cptActivite = -1;
	while (trouve == false && cptActivite < maxActivites/*nombreActivites*/)
	{
		cptActivite++;
		if (lesActivites[cptActivite].getCodeActivite() == inCodeActiviteVoulue)
		{
			trouve = 1;
		}
		

	}
	if (trouve == 0)
	{
		cptActivite = -1;
	}
	return cptActivite;
}
//----------------------------------------------------------------------------------------
void AfficherLesInscriptions()
{
	string activite;
	ClrScr();
	cout << "Code de l'activite: ";
	cin >> activite;
	
	if (RechercherActivite(activite) != -1)
	{

		for (int i = 0; i < nombreElevesReels; i++)
		{
			Activite* activiteChoisie = TabEleves[i].getActiviteInscrite();
			if (activiteChoisie !=NULL && TabEleves[i].getActiviteInscrite()->getCodeActivite() == activite)
			{
				Afficher(TabEleves[i]);
			}
		}
	}

	_getch();
}







