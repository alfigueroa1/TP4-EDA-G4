
#ifndef GENERICFSM_H
#define GENERICFSM_H

#include "events.h"

enum {ERROR, FIN};

typedef unsigned int stateTypes;
//typedef unsigned int eventType;

class genericFSM;

struct fsmCell{
    stateTypes nextState;
    void (genericFSM::*action)(eventType*);
};


class genericFSM{
public:
    genericFSM();
    void cycle(eventType* ev);
    stateTypes getState();
    char* getErrorCode();
private:
    stateTypes state;
    unsigned int rowCount;
    unsigned int columnCount;
    fsmCell * FSMTAble; 
};

#endif /* GENERICFSM_H */

