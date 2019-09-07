
#ifndef PARTFSM_H
#define PARTFSM_H

#include "genericFSM.h"

enum{state0, state1, state2};
/*************************************************************
 *                        OBJECT FSM
 ************************************************************/
class FSMObject :public genericFSM {

public:
	FSMObject() :genericFSM() {}

private:
#define RX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMObject::x))

	const fsmCell fsmTable[4][6] = {
		{state1, RX(prueba0)},  {FIN, RX(prueba1)}, {ERROR, RX(prueba1)}, {},					{},					  {ERROR, RX(prueba0)},
		{},						{},					{ERROR, RX(prueba1)}, {state2, RX(prueba0)},{ERROR, RX(prueba0)}, {},
		{state1, RX(prueba0)},	{FIN, RX(prueba1)}, {ERROR, RX(prueba1)}, {},					{},					  {ERROR, RX(prueba0)},
		{},						{},					{ERROR, RX(prueba1)}, {},					{},					  {},
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
 *                        VALUE FSM
 ************************************************************/
class FSMValue :public genericFSM {

public:
	FSMValue() :genericFSM() {}

private:
#define QX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMValue::x))

	const fsmCell fsmTable[4][6] = {
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
    
private:
    #define TX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMString::x))
    
    const fsmCell fsmTable[4][6] = {
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
    
private:
    
    #define AX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMArray::x))
    
    const fsmCell fsmTable[][2] = {
		//recibir LBRACKET			//RECIBIR RBRACKET			//RECIBIR COMMA
		{VALUE, AX(V_FSMValue)},	{ARRAYERROR, AX(arrayError)}, {ARRAYERROR, AX(arrayError)},	//INIT
		{},							{ARRAYOK, AX(arrayOk)},		  {INIT, AX(arrayNothing)}		//VALUE
	};																							
        
    void arrayError(eventType* ev){
		return;
    }
	void arrayNothing(eventType* ev) {
		return;
	}
        
    void prueba3(eventType* ev){
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

private:
#define VX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMNumber::x))

	const fsmCell fsmTable[4][6] = {
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
