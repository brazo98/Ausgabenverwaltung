#include "stdafx.h"
#include "Ausgaben.h"


Ausgaben::Ausgaben(unsigned int ausgabenID, unsigned int kategorie, float verbrauch){
	this->ausgabenID = ausgabenID;
	this->kategorie= kategorie;
	this->verbrauch= verbrauch;
}
	//Setter und Getter AusgabenID
void Ausgaben::setausgabenID(unsigned int ausgabenID){
	this->ausgabenID = ausgabenID;
}
int Ausgaben::getausgabenID(){
	return this->ausgabenID;
}

	//Setter und Getter Kategorie
void Ausgaben::setKategorieAusgaben(unsigned int kategorie){
	this->kategorie = kategorie;
}
int Ausgaben::getKategorie(){
	return this->kategorie;
}

	//Settter und Getter Verbrauch
void Ausgaben::setVerbrauch(unsigned int verbrauch){
	this->verbrauch = verbrauch;
}
float Ausgaben::getVerbrauch(){
	return this->verbrauch;
}