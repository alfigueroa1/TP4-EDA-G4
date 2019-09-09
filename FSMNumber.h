#ifndef _FSMNUMBER_H
#define _FSMNUMBER_H

#include "genericFSM.h"
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

enum{state0, state1, state2, state3, state4, state5, state6, state7, state8};

class FSMNumber:public genericFSM{

public:
    FSMNumber():genericFSM(){}

	virtual void cycle(eventType* ev) {
		eventType evento;
		int i = 0;
		evento = filterEvents(*ev);
		i = evento;
		state = fsmTable[(state * rowCount) + (evento - 1)].nextState;
	}

    virtual int filterEvents(eventType ev) {
        char * evento;
        if(ev != EOF)
            evento = (char*) ev;
        else
            return 0;
        regex_t preg;
        const char *regex_menos = "^-$";
        const char *regex_zero = "^0$";
        const char *regex_digit = "^[1-9]$";
        const char *regex_point = "^\\.$";
        const char *regex_e = "^[eE]$";
        const char *regex_mas = "^+$";

        /* Digit */
        if (!regcomp (&preg, regex_menos, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 0;
            }
        }

        /* Quote */
        if (!regcomp (&preg, regex_zero, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 1;
            }
        }

        /* Reverse solidus */
        if (!regcomp (&preg, regex_digit, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 2;
            }
        }

        /* U */
        if (!regcomp (&preg, regex_point, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 3;
            }
        }

        /* Hexa */
        if (!regcomp (&preg, regex_e, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 4;
            }
        }

        /* Symbol */
        if (!regcomp (&preg, regex_mas, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 5;
            }
        }
        return 0;
    }

private:
#define TX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMNumber::x))

    const fsmCell fsmTable[11][7] = {

            // Recibir -            // Recibir 0            // Recibir digit        // Recibir .            // Recibir e                   // Recibir +                //Recibir fin
            {state1, TX(prueba0)},  {state2, TX(prueba1)},  {state3, TX(prueba1)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},    {state1, TX(prueba1)},      {ERROR, TX(prueba1)},
            {ERROR, TX(prueba1)},	{state2, TX(prueba1)},  {state3, TX(prueba1)},  {ERROR, TX(prueba0)},   {ERROR, TX(prueba0)},    {ERROR, TX(prueba1)},       {ERROR, TX(prueba1)},
            {ERROR, TX(prueba0)},	{ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},   {state4, TX(prueba1)},  {state6, TX(prueba1)},   {ERROR, TX(prueba0)},       {FIN, TX(prueba1)},
            {ERROR, TX(prueba1)},	{state3, TX(prueba1)}, 	{state3, TX(prueba1)},  {state4, TX(prueba1)},	{ERROR, TX(prueba1)},    {ERROR, TX(prueba1)},       {FIN, TX(prueba1)},
            {ERROR, TX(prueba1)},   {state5, TX(prueba1)},  {state5, TX(prueba1)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},    {ERROR, TX(prueba1)},       {ERROR, TX(prueba1)},
            {ERROR, TX(prueba1)},   {state5, TX(prueba1)},  {state5, TX(prueba1)},  {ERROR, TX(prueba1)},   {state6, TX(prueba1)},   {ERROR, TX(prueba1)},       {FIN, TX(prueba1)},
            {state7, TX(prueba1)},  {state8, TX(prueba1)},  {state8, TX(prueba1)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},    {state7, TX(prueba1)},      {ERROR, TX(prueba1)},
            {ERROR, TX(prueba1)},   {state8, TX(prueba1)},  {state8, TX(prueba1)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},    {ERROR, TX(prueba1)},       {ERROR, TX(prueba1)},
            {ERROR, TX(prueba1)},   {state8, TX(prueba1)},  {state8, TX(prueba1)},  {ERROR, TX(prueba1)},   {ERROR, TX(prueba1)},    {ERROR, TX(prueba1)},       {FIN, TX(prueba1)},
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
