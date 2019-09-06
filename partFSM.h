
#ifndef PARTFSM_H
#define PARTFSM_H

#include "genericFSM.h"

enum{state0, state1};

class FSMString:public genericFSM{
    
public:
    FSMString():genericFSM(){}
    
private:
    #define TX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMString::x))
    
    const fsmCell fsmTable[2][2] = {
        {state0, TX(prueba0)},  {state1, TX(prueba1)}
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

class FSMArray:public genericFSM{
    
public:
    FSMArray():genericFSM(){}
    
private:
    
    #define AX(x) (static_cast<void (genericFSM::* )(eventType*)>(&FSMArray::x))
    
    const fsmCell fsmTable[2][2] = {
        {state0, AX(prueba2)},  {state1, AX(prueba3)}
    };
        
    void prueba2(eventType* ev){
        int a=0;
        a++;
    }
        
    void prueba3(eventType* ev){
        int a=0;
        a++;
    }
};

#endif /* PARTFSM_H */

