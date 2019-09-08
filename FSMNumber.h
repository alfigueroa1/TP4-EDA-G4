#ifndef _FSMNUMBER_H
#define _FSMNUMBER_H

#include "genericFSM.h"

enum{state0, state1, state2, state3, state4, state5, state6, state7, state8};

class FSMNumber:public genericFSM{

public:
    FSMNumber():genericFSM(){}

	virtual void cycle(eventType* ev) {
		eventType evento;
		int i = 0;
		evento = filterEvents(*ev);
		i = evento;
		state = FSMTable[(state * rowCount) + (evento - 1)].nextState;
	}

private:
#define TX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMNumber::x))

    const fsmCell fsmTable[11][8] = {

            // Recibir -            // Recibir 0            // Recibir digit        // Recibir .            // Recibir e            // Recibir E            // Recibir +                //Recibir fin
            {state1, TX(prueba0)},  {state2, TX(prueba1)},  {state3, TX(prueba1)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {state1, TX(prueba1)},      {ERROR, TX(prueba1)},
            {ERROR, TX(prueba1)},	{state2, TX(prueba1)},  {state3, TX(prueba1)},  {ERROR, TX(prueba0)},   {ERROR, TX(prueba0)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},       {ERROR, TX(prueba1)},
            {ERROR, TX(prueba0)},	{ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {state4, TX(prueba1)},  {state6, TX(prueba1)},  {state6, TX(prueba1)},  {ERROR, TX(prueba0)},       {FIN, TX(prueba1)},
            {ERROR, TX(prueba1)},	{state3, TX(prueba1)}, 	{state3, TX(prueba1)},  {state4, TX(prueba1)},	{ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},       {FIN, TX(prueba1)},
            {ERROR, TX(prueba1)},   {state5, TX(prueba1)},  {state5, TX(prueba1)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},       {ERROR, TX(prueba1)},
            {ERROR, TX(prueba1)},   {state5, TX(prueba1)},  {state5, TX(prueba1)},  {ERROR, TX(prueba1)},   {state6, TX(prueba1)},  {state6, TX(prueba1)},  {ERROR, TX(prueba1)},       {FIN, TX(prueba1)},
            {state7, TX(prueba1)},  {state8, TX(prueba1)},  {state8, TX(prueba1)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {state7, TX(prueba1)},      {ERROR, TX(prueba1)},
            {ERROR, TX(prueba1)},   {state8, TX(prueba1)},  {state8, TX(prueba1)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},       {ERROR, TX(prueba1)},
            {ERROR, TX(prueba1)},   {state8, TX(prueba1)},  {state8, TX(prueba1)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},       {FIN, TX(prueba1)},
            {}, {}, {}, {}, {}, {}, {}, // Error
            {}, {}, {}, {}, {}, {}, {}, // Fin
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

#endif //_FSMNUMBER_H
