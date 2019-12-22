#pragma once
#include <iostream>
#include <vector>
#include "stdafx.h"
#include "Ausgaben.h"

using namespace std;
	 

class Rechnung{
private:
	unsigned int persID;
	unsigned int monat;
	vector<Ausgaben> AusgabenModel;
public:
	
	//Konstruktor
	Rechnung(unsigned int persID, unsigned int monat, unsigned int kategorie, float verbrauch);
//	list<Ausgaben> getListeAusgaben();
	
	//setter und getter Monate
	void setMonatRechnung(unsigned int monat);
	int getMonatRechnung();

	//setter und getter PersID
	void setPersID(unsigned int persID);
	int getpersID();
	//Methode  für neue Ausgaben die hinzugefügt werden!
	void pushNewAusgabe(Ausgaben &au);
	vector<Ausgaben> getModelAusgaben();


};




