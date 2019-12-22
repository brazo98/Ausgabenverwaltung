// esa1_main_ausgabenV.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include <iostream>
#include "rlutil.h"  //Wurde bereits in den Projekten davor benutz die Nutzung ist frei verfügbar und unter GIT zur Verfügung gestellt
#include "AusgabeAlarm.h" //Meine Eventklassen nach .NET manier zum feuern von Events hier jetzt speziell für die Budgetüberschreitung
#include "AlarmMelder.h" //Meine Eventklassen nach .NET manier zum feuern von Events hier jetzt speziell für die Budgetüberschreitung
#include "AlarmHandler.h" //Meine Eventklassen nach .NET manier zum feuern von Events hier jetzt speziell für die Budgetüberschreitung
#include "RechnungModel.h" //Mein Model
#include "Rechnung.h" //Meine Rechnungsklasse
#include <windows.h>

using namespace System;
using namespace std;

//Ein paar Statische Datentypen und Konstante
static char aufladen;
static float budget=500.00;
const int bar=20;

//Methode um das Budget wieder aufzuladen
void aufladenBudget(){
	budget=500;
}
void initialMain(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

//Instanzierung Model
	RechnungsModel re;

//Sortierroutine für mein Model
void sortRechnungen(){
	vector<Rechnung> tempModel;

	if (re.getModel().size()>0){

		tempModel.clear();
		for(unsigned i=0; i < re.getModel().size();i++){
			re.changeID(i);
			tempModel.insert(tempModel.begin(),re.getModel()[i]);
		}
	}


}

//Funktion für die Abfrage ob aktuelle Monatseingabe stimmt oder eine falsche Eingabe getätigt wurde!!
bool convertToMonth(String^ monat){
	DateTime ^now = DateTime::Now;
	DateTime firstOfMonth = now->AddDays(0);
	//Console::WriteLine("firstofMonth: {0}",  firstOfMonth.Month);

	if(firstOfMonth.Month.ToString() == monat){
		return true;
	}else {
		return false;
	}
}

int main(array<System::String ^> ^args)
{
	int id=0;
	int monat=0;
	int kategorie=0;
	int kategorie1=0;
	float ausgaben=0;
	char auswahlKategorie=0;
	char auswahlKategorie2=0;

	initialMain();
	//Event anmelden
	AusgabeAlarm ^myalarm = gcnew AusgabeAlarm;
    AlarmMelder ^myalarmMelder = gcnew AlarmMelder(myalarm);
	//AlarmHandler ^myalarmHandler = gcnew AlarmHandler(myalarm);

	//Aktuelles Datum/Monat
	DateTime ^now = DateTime::Now;
	DateTime firstOfMonth = now->AddDays(0);
	Console::WriteLine("firstofMonth: {0}",  firstOfMonth.Month);
	
	//Deklarieren von Rechnung
	Rechnung *rechnung1;


	//Deklaration von Ausgaben
	Ausgaben *au;
	//Ausgaben *au1;

	do{

		
		//Mein neues Dashboard
		system("cls");
		gotoxy(29, 2);  cout << "=====AusgabenverwaltungTHD=====";
		gotoxy(29, 3);  cout << "1. Einfuegen                   ";
		gotoxy(29, 4);  cout << "2. Editieren/Updaten           ";
		gotoxy(29, 5);  cout << "3. Loeschen                    ";
		gotoxy(29, 6);  cout << "4. ------                      ";
		gotoxy(29, 7);  cout << "5. ----------------            ";
		gotoxy(29, 8);  cout << "6. Anzeigen                    ";
		gotoxy(29, 9);  cout << "7. THD                         ";
		gotoxy(29, 10); cout << "8. Quit                        ";
		gotoxy(29, 11); cout << "===============================";

		char menu;
	repeat:
		gotoxy(29, 13);
		cout << "Ihre Auswahl: ";
		menu = getch();
		
		//Switchroutine für die Abfrage der Auswahl
		switch (menu){
		
			case '1': //Insert Routine
				
					system("cls");
					
					//Easteregg!
					do{
						system("cls");
						cout << "Geben Sie den Monat als Zahl ein: \n"; cin >> monat;
						if (convertToMonth(monat.ToString())){
							//do nothing
					
						}else{
							system("cls");
							//system("color 1e");
							cout << "to be continue...";
							for(int i=0; i<=bar; i++){
								Sleep(100);
								cout << ".";
							}
							cout  << ".";
							cout << "Ihre Monatseingabe entspricht nicht dem aktuellen Monat bitte korrigieren: \n"; 
							cout << "Geben Sie den Monat als Zahl ein: \n"; cin >> monat;
						}	
					}while(!convertToMonth(monat.ToString()));
					

					system("cls");
					gotoxy(29, 2);  cout << "============Kategorie===========";
					gotoxy(29, 3);  cout << "1. Tanken					      ";
					gotoxy(29, 4);  cout << "2. Kleidung			          ";
					gotoxy(29, 5);  cout << "3. Essen					     ";
					gotoxy(29, 6);  cout << "4. Freizeit                     ";
					gotoxy(29, 7);  cout << "5. Sparen				          ";
					gotoxy(29, 8);  cout << "6. Hochschule                   ";
					gotoxy(29, 9);  cout << "7. Buecher                      ";
					gotoxy(29, 10); cout << "8. Ferien                       ";
					gotoxy(29, 11); cout << "==============================";

					gotoxy(29, 13);
					cout << "Ihre Auswahl: \n";
					auswahlKategorie = getch();
					//Abfrage nach der Kategorie!
					switch(auswahlKategorie){
						case '1': 
							kategorie = 1;
							system("pause");
							break;
						case '2': 
							kategorie = 2;
							system("pause");
							break;
						case '3': 
							kategorie = 3;
							system("pause");
							break;
						case '4': 
							kategorie = 4;
							system("pause");
							break;
						case '5': 
							kategorie = 5;
							system("pause");
							break;
						case '6': 
							kategorie = 6;
							system("pause");
							break;
						case '7': 
							kategorie = 7;
							system("pause");
							break;
						case '8': 
							kategorie = 8;
							system("pause");
						break;

						default:
							kategorie = 1;
					}
					cout << "geben Sie die Ausgaben ein! \n"; cin >> ausgaben;
					rechnung1 = new Rechnung(re.getModel().size()+1,monat,kategorie,ausgaben);
					re.setRechnung(*rechnung1);
				

				system("cls");
				re.tableHeader();
				re.tableFooter(re.display());
				
				
				system("cls");
				re.tableHeader();
				re.tableFooter(re.display());
				//Eventhandler ist noch Guthaben vorhanden?
				if (re.getTotal() >= budget){
					myalarm->AusgabeAlarmAusloesen("Keine Kohle mehr verflixt!",0);
					Console::WriteLine("Wollen Sie 500 EURO aufladen j/n");
					cin >> aufladen;

					if(aufladen=='j'){
						aufladenBudget();
					}
				}
								
				system("pause");
				
				au = nullptr;
				delete rechnung1;
			
				
				
				break;
			case '2': //Änderung und Updateroutine
				//Wurde bereits in case 1 beschrieben
				if (!re.getModel().empty()){
					system("cls");
					re.tableHeader();
					re.tableFooter(re.display());
					cout << "Bitte geben Sie die ID ein welche sie noch Ausgaben hinzufuegen moechten! \n"; cin >> id;
					system("cls");
					gotoxy(29, 2);  cout << "============Kategorie===========";
					gotoxy(29, 3);  cout << "1. Tanken					      ";
					gotoxy(29, 4);  cout << "2. Kleidung			          ";
					gotoxy(29, 5);  cout << "3. Essen					     ";
					gotoxy(29, 6);  cout << "4. Freizeit                     ";
					gotoxy(29, 7);  cout << "5. Sparen				          ";
					gotoxy(29, 8);  cout << "6. Hochschule                   ";
					gotoxy(29, 9);  cout << "7. Buecher                      ";
					gotoxy(29, 10); cout << "8. Ferien                       ";
					gotoxy(29, 11); cout << "==============================";

					gotoxy(29, 13);
					cout << "Ihre Auswahl: \n";
					auswahlKategorie2 = getch();

					switch(auswahlKategorie2){
						case '1': 
							kategorie1 = 1;
							system("pause");
							break;
						case '2': 
							kategorie1 = 2;
							system("pause");
							break;
						case '3': 
							kategorie1 = 3;
							system("pause");
							break;
						case '4': 
							kategorie1 = 4;
							system("pause");
							break;
						case '5': 
							kategorie1 = 5;
							system("pause");
							break;
						case '6': 
							kategorie1 = 6;
							system("pause");
							break;
						case '7': 
							kategorie1 = 7;
							system("pause");
							break;
						case '8': 
							kategorie1 = 8;
							system("pause");
						break;

						default:
							kategorie1 = 1;
					}

					cout << "Bitte geben Sie die Ausgaben ein! \n"; cin >> ausgaben;
					
					system("cls");
					if (re.getTotal() >= budget){
						myalarm->AusgabeAlarmAusloesen("Keine Kohle mehr verflixt!",0);
						Console::WriteLine("Wollen Sie 500 EURO aufladen j/n");
						cin >> aufladen;

						if(aufladen=='j'){
							aufladenBudget();
							au = new Ausgaben(re.getModel()[id-1].getModelAusgaben().size()+1,kategorie1,ausgaben);
							re.getModel()[id-1].pushNewAusgabe(*au);
							delete au;
							break;
						}
						
					}
					au = new Ausgaben(re.getModel()[id-1].getModelAusgaben().size()+1,kategorie1,ausgaben);
					re.getModel()[id-1].pushNewAusgabe(*au);
					delete au;
					
				}
				
				system("pause");
				break;
				
				
			case '3': //Löschroutine
				
				system("cls");
				if (!re.getModel().empty()){
					re.tableHeader();
					re.tableFooter(re.display());
					cout << "Welche ID moechte Sie entfernen?: \n"; cin >> id;
					////ModelEmp.erase(ModelEmp.begin() + (id-1)); //Wird aus dem Model gelöscht an dieser Stelle ID-1
					re.getModel().erase(re.getModel().begin() + (id-1)); //Wird aus dem Model gelöscht an dieser Stelle ID-1
					sortRechnungen();
					system("cls");
					if (!re.getModel().empty()){
						re.tableHeader();
						re.tableFooter(re.display());
					}
				}else if (re.getModel().empty()){
					re.getModel().clear();
					//ModelEmp.clear();
					system("cls");
				}
							
				system("pause");
				
				break;
			case '4':  //Suchroutine
				system("cls");
				system("pause");
				break;
			case '5': //Urlaubserfassungsroutine
				system("cls");
				system("pause");

				break;
			case '6': // Komplette Datensätze anzeigen
				if (!re.getModel().empty()){
					system("cls");
					re.tableHeader();
					re.tableFooter(re.display());
				}
				system("pause");
				break;
			case '7': //About THD
				cout << "THD Angewandte Informatik www.thg.de\n";
				system("pause");
				break;
			case '8': //Exit Ausgang aus dem Programm
				cout << "Auswahl 8";
				delete myalarm;
				delete myalarmMelder;
				//delete myalarmHandler;
				exit(0);

			default:
				gotoxy(29, 15);  cout << "Falsche Eingabe";
				getch(); gotoxy(29, 15); system("cls");
				goto repeat;
		}

	}while(true); //Wird wiederholt bis case:8 kommt!
	system("pause");
	delete rechnung1;

	return 0;
 }
