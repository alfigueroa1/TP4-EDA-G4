#pragma once
enum FSMStates {
	FIN, ERROR, NEWOBJ, NEWARRAY, NEWVALUE, NEWSTRING, NEWNUM,
	objectState0, objectState1, objectState2,
	arrayState0, arrayState1,
	valueState0,
	stringState0, stringState1, stringState2, stringState3, stringState4,
	numberState0, numberState1, numberState2, numberState3, numberState5, numberState6, numberState7, numberState8
};