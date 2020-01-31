#include "activite.h"

Activite::Activite()
{
	codeActivite = "";
	titre = "";
	responsable = "";
}

Activite::Activite(string incodeActivite, string intitre, string inresponsable)
{
	codeActivite = incodeActivite;
	titre = intitre;
	responsable = inresponsable;
}



#pragma region  Set

//void Activite:: setResponsable(string inNomResponsable)
//{
//	responsable = inNomResponsable;
//}
//
//void Activite:: setCodeActivite(string inCodeActivite)
//{
//	codeActivite = inCodeActivite;
//}
//
//void Activite:: setTitre(string inTitre)
//{
//	titre = inTitre;
//}

void Activite ::InitialiserActivite(string inTitre, string inCode)
{
	titre = inTitre;
	codeActivite = inCode;
}

void Activite::AssignerResponsable(string inResponsable)
{
	responsable = inResponsable;
}

#pragma endregion


#pragma region Get

	string Activite:: getCodeActivite() const
	{
		return codeActivite;
	}

	string Activite::getTitre() const
	{
		return titre;
	}

	string Activite::getResponsable() const
	{
		return responsable;
	}



#pragma endregion