#include "stdafx.h"
#include "AusgabeAlarm.h"
#include "AusgabeEventArgs.h"
#include "AlarmMelder.h"
#include "AlarmHandler.h"

using namespace System;

AlarmHandler::AlarmHandler(AusgabeAlarm ^alarm){
	alarm->AlarmEvent += gcnew AusgabeAlarm::AlarmDelegate(
		this, &AlarmHandler::alarm);
}

void AlarmHandler::alarm(System::Object ^sender, AusgabeEventArgs ^we){
	Console::WriteLine(L"Alarm: Budget wurde neu aufgeladen!!! {0}, {1}", we->msg, we->ueberschritten);

}
