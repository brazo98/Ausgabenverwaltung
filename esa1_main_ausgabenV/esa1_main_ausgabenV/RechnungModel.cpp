#include "stdafx.h"
#include "RechnungModel.h"
#include "rlutil.h"
#include <vector>
#include <algorithm>
#include <windows.h>
 
//clearen des Datenmodel
void RechnungsModel::clearModel(){
	ml.clear();
}

 vector<Rechnung> RechnungsModel::getModel(void){
	return ml;
}

//Methode für die Headerausgabe
void RechnungsModel::tableHeader()
{
	gotoxy(1, 1);
	cout << "ID";
	gotoxy(10, 1);
	cout << "Monat";
	gotoxy(30, 1);
	cout << "Kategorie";
	gotoxy(50, 1);
	cout << "Ausgaben";

	for (int i = 0; i < 80; i++) {
		gotoxy(i, 2);
		cout << "-";
	}

}

void RechnungsModel::tableFooter(int line){
	
	for (int i = 0; i < 80; i++) {
		gotoxy(i, line);
		cout << "-";
	}

	gotoxy(50, line+1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),124);
		cout << getTotal()<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void RechnungsModel::setTotal(float total){
	this->total = total;
}

float RechnungsModel::getTotal(){
	return this->total;
}


int RechnungsModel::display(){
	int line=4;
	float total=0;

	if(!ml.empty()){
		for(unsigned int i=0; i <= ml.size()-1;i++){
			gotoxy(1, line + i);
			cout << ml[i].getpersID() << endl;
			gotoxy(10, line + i);
			cout << parserForExplaneMonth(ml[i].getMonatRechnung())<< endl;
			
			if(ml[i].getModelAusgaben().size()-1 ==0){
				for(unsigned int j=0; j <= ml[i].getModelAusgaben().size()-1; j++){
					gotoxy(30, line + i);
					cout << parserForKategorie(ml[i].getModelAusgaben()[j].getKategorie())<< endl;
					gotoxy(50, line + i);
					cout <<  ml[i].getModelAusgaben()[j].getVerbrauch()<< endl;
					total += ml[i].getModelAusgaben()[j].getVerbrauch();
					setTotal(total);
					
				}
			}else{
				for(unsigned int j=0; j <= ml[i].getModelAusgaben().size()-1; j++){
					gotoxy(30, line + j);
					cout << parserForKategorie(ml[i].getModelAusgaben()[j].getKategorie())<< endl;
					gotoxy(50, line + j);
					cout <<  ml[i].getModelAusgaben()[j].getVerbrauch()<< endl;
					total += ml[i].getModelAusgaben()[j].getVerbrauch();
					setTotal(total);
					
				}
				line += line;
				gotoxy(50, line-1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),124);
					cout << getTotal();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			}
			

		}
	}
	return line+3;
}
//Methode zum weitere Ausgaben hinzuzufügen
void RechnungsModel::setRechnung(Rechnung rechnung){
	ml.push_back(rechnung);
}	



//Parse zum umwandeln von zahlen in Monatsnamen
string RechnungsModel::parserForExplaneMonth(int zahl){
	
	switch(zahl){
		case 1:
			return "Januar";
			break;
		case 2:
			return "Februar";
			break;
		case 3:
			return "Maerz";
			break;
		case 4:
			return "April";
			break;
		case 5:
			return "Mai";
			break;
		case 6:
			return "Juni";
			break;
		case 7:
			return "Juli";
			break;
		case 8:
			return "August";
			break;
		case 9:
			return "September";
			break;
		case 10:
			return "Oktober";
			break;
		case 11:
			return "November";
			break;
		case 12:
			return "Dezember";
			break;
		default:
			return "n/n";
			break;
			
	}
	
}
//Parser für umwandeln von Zahle in Kategorien
string RechnungsModel::parserForKategorie(int zahl){
	switch(zahl){
		case 1:
			return "Tanken";
			break;
		case 2:
			return "Kleidung";
			break;
		case 3:
			return "Essen";
			break;
		case 4:
			return "Freizeit";
			break;
		case 5:
			return "Sparen";
			break;
		case 6:
			return "Hochschule";
			break;
		case 7:
			return "Buecher";
			break;
		case 8:
			return "Ferien";
			break;
		case 9:
			return "Ausfluege";
			break;
		case 10:
			return "Theater";
			break;
		case 11:
			return "Kino";
			break;
		case 12:
			return "Restaurant";
			break;
		default:
			return "n/n";
			break;
			
	}

}

void RechnungsModel::changeID(int i){
	this->ml[i].setPersID(i+1);
}