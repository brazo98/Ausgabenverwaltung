#pragma once
#include <iostream>
#include "stdafx.h"
#include "AusgabeEventArgs.h"
#include "AusgabeAlarm.h"

//Klasse AlarmHandler 
ref class AlarmHandler{
public:
	AlarmHandler(AusgabeAlarm ^alarm);

	void alarm(Object ^sender, AusgabeEventArgs^ we);

};