#pragma once
#include "genericFSM.h"
#include "FSMstates.h"
/*************************************************************
 *                        ARRAY FSM
 ************************************************************/
class FSMArray :public genericFSM {

public:
	FSMArray() :genericFSM() {}
	virtual int filterEvents(eventType ev) {
		switch (ev) {
		case ']':
			return 1;
		case ',':
			return 2;
		default:
			return 3;
		}
	}
	virtual void cycle(eventType* ev) {
		eventType evento;
		int i = 0;
		evento = filterEvents(*ev);
		i = evento;
		state = FSMTable[(state * rowCount) + (evento - 1)].nextState;
		//FSMTable[(state * rowCount) + (evento - 1)].action;
	}

private:

#define AX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMArray::x))

	//const fsmCell FSMTable[2][3] = {
	const fsmCell FSMTable[6] = {
		//RECIBIR ']'			//RECIBIR ','					//Other
		{FIN, AX(arrayOk)},		{ERROR, AX(arrayError)},		{NEWVALUE, AX(checkVal)},		//INIT			arrayState0
		{FIN, AX(arrayOk)},		{NEWVALUE, AX(arrayOk)},		{ERROR, AX(arrayError)},		//ARRAYVALUE	arrayState1
	};

	void arrayError(eventType* ev) {
		state = ERROR;
	}
	void arrayOk(eventType* ev) {
		return;
	}
};