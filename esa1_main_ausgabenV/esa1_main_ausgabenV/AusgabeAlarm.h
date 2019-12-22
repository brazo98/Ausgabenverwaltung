#pragma once
#include <iostream>
#include "stdafx.h"
#include "AusgabeEventArgs.h"

//Klasse AusgabeAlarm
public ref class AusgabeAlarm{
public:
	delegate void AlarmDelegate(Object ^sender, AusgabeEventArgs ^we );
	event AlarmDelegate^ AlarmEvent;

	void AusgabeAlarmAusloesen(String ^msg, float ausgabe);
};
