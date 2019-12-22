#pragma once
#include <iostream>
#include "stdafx.h"

using namespace System;
using namespace std;

//Klasse AusgabeEventArgs abgeleitet von EventArgs
public ref class AusgabeEventArgs: public EventArgs{
private: 
	float budget;

public:	
	AusgabeEventArgs(String ^msg, float ueberschritte);

	String ^msg;
	float ueberschritten;

		
};

