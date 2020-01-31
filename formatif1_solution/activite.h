#ifndef ACTIVITE_H 
#define ACTIVITE_H

#include "..\screen\screen.h"
#include <string>
#include <iostream>
using namespace std;

 

class Activite
{



private:
	string codeActivite;
	string titre;
	string responsable;


public:

	Activite();
	Activite(string codeActivite,string titre,string responsable);


	string getCodeActivite() const;
	string getTitre() const;
	string getResponsable() const;


	void InitialiserActivite(string inTitre, string inCode);
	void AssignerResponsable(string inResponsable);

/*
	void setResponsable(string nomResponsable);
	void setCodeActivite(string codeActivite);
	void setTitre(string titre);*/



};




#endif