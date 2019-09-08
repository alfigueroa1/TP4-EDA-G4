
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
    //void cycle(eventType* ev);
	virtual void cycle(eventType* ev) = 0;
    stateTypes getState();
    char* getErrorCode();
	virtual int filterEvents(eventType) = 0;
protected:    
	stateTypes state;
private:
    unsigned int rowCount;
    unsigned int columnCount;
    fsmCell * FSMTAble; 
};

#endif /* GENERICFSM_H */

