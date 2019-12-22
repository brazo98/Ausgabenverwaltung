#include "stdafx.h"
#include "Rechnung.h"
#include "Ausgaben.h"


vector<Ausgaben> Rechnung::getModelAusgaben(){
	return AusgabenModel;
}

Rechnung::Rechnung(unsigned int persID, unsigned int monat, unsigned int kategorie, float verbrauch){
	this->persID = persID;
	this->monat = monat;

	Ausgaben ausgabe(persID, kategorie, verbrauch );
	AusgabenModel.push_back(ausgabe);

	
	
}
//setter und getter Monate
void Rechnung::setMonatRechnung(unsigned int monat){
	this->monat = monat;
}
int Rechnung::getMonatRechnung(){
	return this->monat;
}

//setter und getter PersID
void Rechnung::setPersID(unsigned int persID){
	this->persID = persID;
}
int Rechnung::getpersID(){
	return this->persID;
}

void Rechnung::pushNewAusgabe(Ausgaben &au){
	AusgabenModel.push_back(au);
}
