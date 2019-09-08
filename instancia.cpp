#include <iostream>
#include "partFSM.h"

using namespace std;

int detectNewInstance(eventType){
    static int a = 0;
    a++;
    if(a >= 5)
        return a;
    else
        return 0;
}

void stackFSMsPop(int instance, genericFSM** stack, uint stackLevel) {
	genericFSM* newFSM = NULL;
	if (instance == 0)
		FSMArray* newFSM = new (std::nothrow) FSMArray;
	else if (instance == 1)
		FSMString* newFSM = new (std::nothrow) FSMString;
	stack[stackLevel + 1] = newFSM;
}