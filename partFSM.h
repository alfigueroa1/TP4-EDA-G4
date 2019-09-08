
#ifndef PARTFSM_H
#define PARTFSM_H

#include "genericFSM.h"

enum{state0, state1, state2};
/*************************************************************
 *                        OBJECT FSM
 ************************************************************/
enum objectStates {INITOBJ, OBJSTRING, OBJVALUE, OBJERROR, OBJOK, OBJARRAY};
class FSMObject :public genericFSM {

public:
	FSMObject() :genericFSM() {}

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
	const fsmCell fsmTable[20] = {
		//"""							"}"					":"							","					OTHER
		{OBJSTRING,RX(V_FSMString)},	{OBJOK,},		{OBJERROR,},				{OBJERROR,},	{OBJERROR,},//INITOBJECT
		{OBJERROR,},					{OBJERROR,},	{OBJVALUE, RX(V_FSMValue)},	{OBJERROR,},	{OBJERROR,},//OBJSTRING
		{OBJERROR,},					{OBJOK,},		{OBJERROR,},				{OBJSTRING,},	{OBJERROR,},//OBJVALUE
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

/*************************************************************
 *                        STRING FSM
 ************************************************************/
class FSMString:public genericFSM{
    
public:
    FSMString():genericFSM(){}

	virtual int filterEvents(eventType ev) {
		switch (ev) {
		case '/':
			return 1;
		case '"':
			return 2;
		case EOF:
			return 3;
		case 'f':case 'n':case 'r':case 't':case 'u':case 'b':
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
    #define TX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMString::x))
    
    //const fsmCell fsmTable[4][6] = {
	const fsmCell fsmTable[24] = {
		{state1, TX(prueba0)},  {FIN, TX(prueba1)}, {ERROR, TX(prueba1)}, {},					{},					  {ERROR, TX(prueba0)},
		{},						{},					{ERROR, TX(prueba1)}, {state2, TX(prueba0)},{ERROR, TX(prueba0)}, {},
		{state1, TX(prueba0)},	{FIN, TX(prueba1)}, {ERROR, TX(prueba1)}, {},					{},					  {ERROR, TX(prueba0)},
		{},						{},					{ERROR, TX(prueba1)}, {},					{},					  {},
   };
        
    void prueba0(eventType* ev){
        int a=0;
        a++;
    }
        
    void prueba1(eventType* ev){
        int a=0;
        a++;
    }
};
/*************************************************************
 *                        ARRAY FSM
 ************************************************************/
enum arrayStates {INIT, VALUE, ARRAYERROR, ARRAYOK};
class FSMArray:public genericFSM{
    
public:
    FSMArray():genericFSM(){}

	virtual void cycle(eventType* ev) {
		eventType evento;
		int i = 0;
		evento = filterEvents(*ev);
		i = evento;
		state = FSMTable[(state * rowCount) + (evento - 1)].nextState;
	}
    
private:
    
    #define AX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMArray::x))
    
   // const fsmCell fsmTable[4][3] = {
	const fsmCell fsmTable[12] = {
		//recibir LBRACKET			//RECIBIR RBRACKET			//RECIBIR COMMA
		{VALUE, AX(V_FSMValue)},	{ARRAYERROR, AX(arrayError)}, {ARRAYERROR, AX(arrayError)},	//INIT
		{},							{ARRAYOK, AX(arrayOk)},		  {INIT, AX(arrayNothing)},		//VALUE
		{},							{},							  {},							//ARRAYERROR
		{},							{},							  {},							//ARRAYOK
	};																							
        
    void arrayError(eventType* ev){
		return;
    }
	void arrayNothing(eventType* ev) {
		return;
	}
	void arrayOk(eventType* ev) {
		return;
	}
    void V_FSMValue(eventType* ev){
        int a=0;
        a++;
    }
};
/*************************************************************
 *                        NUMBER FSM
 ************************************************************/
class FSMNumber :public genericFSM {

public:
	FSMNumber() :genericFSM() {}

	virtual void cycle(eventType* ev) {
		eventType evento;
		int i = 0;
		evento = filterEvents(*ev);
		i = evento;
		state = FSMTable[(state * rowCount) + (evento - 1)].nextState;
	}

private:
#define VX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMNumber::x))

	//const fsmCell fsmTable[4][6] = {
	const fsmCell fsmTable[24] = {
		{state1, VX(prueba0)},  {FIN, VX(prueba1)}, {ERROR, VX(prueba1)}, {},					{},					  {ERROR, VX(prueba0)},
		{},						{},					{ERROR, VX(prueba1)}, {state2, VX(prueba0)},{ERROR, VX(prueba0)}, {},
		{state1, VX(prueba0)},	{FIN, VX(prueba1)}, {ERROR, VX(prueba1)}, {},					{},					  {ERROR, VX(prueba0)},
		{},						{},					{ERROR, VX(prueba1)}, {},					{},					  {},
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
