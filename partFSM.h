
#ifndef PARTFSM_H
#define PARTFSM_H

#include "genericFSM.h"

enum{state0, state1, state2};
enum  getNewFSM{NEWOBJ, NEWARRAY, NEWVALUE, NEWSTRING, NEWNUM, };
/*************************************************************
 *                        OBJECT FSM
 ************************************************************/
enum objectStates {INITOBJ, OBJSTRING, OBJVALUE, OBJERROR, OBJOK, OBJARRAY};
class FSMObject :public genericFSM {

public:
	FSMObject() :genericFSM() {}
	virtual int filterEvents(eventType ev) {
		switch (ev) {
		case '"':
			return 1;
		case '}':
			return 2;
		case ':':
			return 3;
		case ',':
			return 4;
		default:
			return 5;
		}
	}
	virtual void cycle(eventType* ev) {
		eventType evento;
		int i = 0;
		evento = filterEvents(*ev);
		i = evento;
		state = FSMTable[(state * rowCount) + (evento - 1)].nextState;
	}

private:
#define RX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMObject::x))

	//const fsmCell fsmTable[4][6] = {
	const fsmCell FSMTable[20] = {
		//"""							"}"				":"							","					OTHER
		{OBJSTRING,RX(V_FSMString)},	{OBJOK,},		{OBJERROR,},				{OBJERROR,},	{OBJERROR,},//INITOBJECT	objectState0
		{OBJERROR,},					{OBJERROR,},	{OBJVALUE, RX(V_FSMValue)},	{OBJERROR,},	{OBJERROR,},//OBJSTRING		objectState1
		{OBJERROR,},					{OBJOK,},		{OBJERROR,},				{OBJSTRING,},	{OBJERROR,},//OBJVALUE		objectState2
		{},								{},				{},							{},				{},			//OBJERROR		
	//	{},								{},				{},							{},				{},			//OBJOK
	};

	void V_FSMString(eventType* ev) {
		int a = 0;
		a++;
	}

	void V_FSMValue(eventType* ev) {
		int a = 0;
		a++;
	}
};

/*************************************************************
 *                        VALUE FSM
 ************************************************************/
class FSMValue :public genericFSM {

public:
	FSMValue() :genericFSM() {}

	virtual void cycle(eventType* ev) {
		eventType evento;
		int i = 0;
		evento = filterEvents(*ev);
		i = evento;
		state = FSMTable[(state * rowCount) + (evento - 1)].nextState;
	}

private:
#define QX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMValue::x))

	//const fsmCell fsmTable[4][6] = {
	const fsmCell fsmTable[24] = {
		{state1, QX(prueba0)},  {FIN, QX(prueba1)}, {ERROR, QX(prueba1)}, {},					{},					  {ERROR, QX(prueba0)},
		{},						{},					{ERROR, QX(prueba1)}, {state2, QX(prueba0)},{ERROR, QX(prueba0)}, {},
		{state1, QX(prueba0)},	{FIN, QX(prueba1)}, {ERROR, QX(prueba1)}, {},					{},					  {ERROR, QX(prueba0)},
		{},						{},					{ERROR, QX(prueba1)}, {},					{},					  {},
	};

	void prueba0(eventType* ev) {
		int a = 0;
		a++;
	}

	void prueba1(eventType* ev) {
		int a = 0;
		a++;
	}

};


#endif /* PARTFSM_H */
//Receptackle of an idea
