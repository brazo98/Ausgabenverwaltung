#include "stdafx.h"
#include "AusgabeAlarm.h"
#include "AusgabeEventArgs.h"
using namespace System;

void AusgabeAlarm::AusgabeAlarmAusloesen(System::String ^msg, float ausgabe){
	AusgabeEventArgs ^alarmparam = gcnew AusgabeEventArgs(msg, ausgabe);
	AlarmEvent(this, alarmparam);
}