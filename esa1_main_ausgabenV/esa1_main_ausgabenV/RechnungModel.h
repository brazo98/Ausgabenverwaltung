#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "stdafx.h"
#include "Rechnung.h"


class RechnungsModel{
private:
	float total;
	vector<Rechnung> ml;
protected:
	
public:
	
	//Methode setze Rechnung
	void setRechnung(Rechnung rechnung);
	//Methode zeige deine Werte an
	int display();
	//Headerausgabe
	void tableHeader();
	//Footerausgabe
	void tableFooter(int line);
	//Methode um Bildschirm zu löschen
	void clearModel();
	//Methode um das Total anzupassen
	void setTotal(float total);
	//Methode gibt mir das Total
	float getTotal();
	//Methode um den Monat zu parsen in einen String
	string parserForExplaneMonth(int zahl);
	//Methode um die Kategorie zu parsen in einen String
	string parserForKategorie(int zahl);
	//Methode um die ID anzupasen beim sortieren
	void changeID(int i);
	//Get Methode für das parsen vom Model dadurch bleibt die Kapselung erhalten!
	vector<Rechnung> getModel(void);
	

};