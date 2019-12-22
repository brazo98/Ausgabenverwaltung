#pragma once
#include <iostream>
#include <list>
#include "stdafx.h"


using namespace std;

class Ausgaben{
private:
	unsigned int ausgabenID;
	unsigned int kategorie;
	float verbrauch;

public:
	//Konstruktor 
	Ausgaben(unsigned int ausgabenID, unsigned int kategorie, float verbrauch);

	//Setter und Getter AusgabenID
	void setausgabenID(unsigned int ausgabenID);
	int getausgabenID();

	//Setter und Getter Kategorie
	void setKategorieAusgaben(unsigned int kategorie);
	int getKategorie();

	//Settter und Getter Verbrauch
	void setVerbrauch(unsigned int verbrauch);
	float getVerbrauch();


};