#pragma once
#include <iostream>
#include "stdafx.h"
#include "AusgabeEventArgs.h"
#include "AusgabeAlarm.h"

//Klasse AlarmMelder
ref class AlarmMelder{
public:
	AlarmMelder(AusgabeAlarm ^alarm);

	void alarm(Object ^sender, AusgabeEventArgs^ we);

};