
#ifndef PARTFSM_H
#define PARTFSM_H

#include "genericFSM.h"

enum{state0, state1, state2};
/*************************************************************
 *                        OBJECT FSM
 ************************************************************/
enum objectStates {INITOBJ, OBJSTRING, OBJVALUE, OBJERROR, OBJOK};
class FSMObject :public genericFSM {

public:
	FSMObject() :genericFSM() {}

private:
#define RX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMObject::x))

	const fsmCell fsmTable[4][6] = {
		//"""							"}"					":"							","					OTHER
		{OBJSTRING,RX(V_FSMString)},	{OBJOK, RX()},		{OBJERROR, RX()},			{OBJERROR, RX()},	{OBJERROR, RX()},//INITOBJECT
		{OBJERROR,RX()},				{OBJERROR, RX()},	{OBJVALUE, RX(V_FSMValue)},	{OBJERROR, RX()},	{OBJERROR, RX()},//OBJSTRING
		{OBJERROR,RX()},				{OBJOK, RX()},		{OBJERROR, RX()},			{OBJSTRING, RX()},	{OBJERROR, RX()},//OBJVALUE
		{},					{},							{},					{},			{},					{},				//OBJERROR
		{},					{},							{},					{},			{},					{}				//OBJOK
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
    
    const fsmCell fsmTable[4][3] = {
		//recibir LBRACKET			//RECIBIR RBRACKET			//RECIBIR COMMA
		{VALUE, AX(V_FSMValue)},	{ARRAYERROR, AX(arrayError)}, {ARRAYERROR, AX(arrayError)},	//INIT
		{},							{ARRAYOK, AX(arrayOk)},		  {INIT, AX(arrayNothing)}		//VALUE
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
