#ifndef _FSMSTRING_H
#define _FSMSTRING_H

#include "genericFSM.h"

enum{state0, state1, state2, state3, state4};

class FSMString:public genericFSM{

public:
    FSMString():genericFSM(){}

	virtual void cycle(eventType* ev) {
		eventType evento;
		int i = 0;
		evento = filterEvents(*ev);
		i = evento;
		state = FSMTable[(state * rowCount) + (evento - 1)].nextState;
	}

private:
#define TX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMString::x))

    const fsmCell fsmTable[7][6] = {

            // Recibir "            // Recibir char         // Recibir \            // Recibir u            // Recibir 4hex             // Recibir symb
            {state1, TX(prueba0)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},      {ERROR, TX(prueba1)},
            {FIN, TX(prueba1)},	    {state1, TX(prueba1)},  {state2, TX(prueba1)},  {state1, TX(prueba0)},  {state1, TX(prueba0)},     {state1, TX(prueba1)},
            {state3, TX(prueba0)},	{ERROR, TX(prueba1)},   {state3, TX(prueba1)},   {state4, TX(prueba1)},  {ERROR, TX(prueba1)},     {state3, TX(prueba1)},
            {FIN, TX(prueba1)},	    {state1, TX(prueba1)}, 	{state2, TX(prueba1)},  {state1, TX(prueba1)},	{state1, TX(prueba1)},     {state1, TX(prueba1)},
            {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {state3, TX(prueba1)},     {ERROR, TX(prueba1)},
            {}, {}, {}, {}, {}, {}, // Error
            {}, {}, {}, {}, {}, {} // Fin
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

#endif //_FSMSTRING_H
