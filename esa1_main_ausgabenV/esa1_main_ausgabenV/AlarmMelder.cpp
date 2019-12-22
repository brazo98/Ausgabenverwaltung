#include "stdafx.h"
#include "AusgabeAlarm.h"
#include "AusgabeEventArgs.h"
#include "AlarmMelder.h"

using namespace System;

AlarmMelder::AlarmMelder(AusgabeAlarm ^alarm){
	alarm->AlarmEvent += gcnew AusgabeAlarm::AlarmDelegate(
		this, &AlarmMelder::alarm);
}

void AlarmMelder::alarm(System::Object ^sender, AusgabeEventArgs ^we){
	Console::WriteLine(L"Alarm: Budget ueberschritten!!! {0}, {1}", we->msg, we->ueberschritten);
		
}

