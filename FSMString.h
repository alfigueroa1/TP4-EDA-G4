#ifndef _FSMSTRING_H
#define _FSMSTRING_H

#include "genericFSM.h"
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>


enum{state0, state1, state2, state3, state4};

class FSMString:public genericFSM{

public:
    FSMString():genericFSM(){}

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
        const char *regex_digit = "^[ac-eg-mo-qsv-zG-TV-Z]$";
        const char *regex_quote = "^\"$";
        const char *regex_rsolidus = "^\\\\$";
        const char *regex_symb = "^[fnrt/]$";
        const char *regex_u = "^[uU]$";
        const char *regex_hex = "^[0-9a-fA-F]$";

        /* Digit */
        if (!regcomp (&preg, regex_digit, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 1;
            }
        }

        /* Quote */
        if (!regcomp (&preg, regex_quote, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 0;
            }
        }

        /* Reverse solidus */
        if (!regcomp (&preg, regex_rsolidus, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 2;
            }
        }

        /* U */
        if (!regcomp (&preg, regex_u, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 3;
            }
        }

        /* Hexa */
        if (!regcomp (&preg, regex_hex, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 4;
            }
        }

        /* Symbol */
        if (!regcomp (&preg, regex_symb, REG_NOSUB | REG_EXTENDED))
        {
            if( !regexec (&preg, evento, 0, NULL, 0)){
                regfree (&preg);
                return 5;
            }
        }
        return 0;
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
