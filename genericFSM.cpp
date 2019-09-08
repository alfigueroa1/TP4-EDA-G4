#include <iostream>
#include "genericFSM.h"

using namespace std;

genericFSM::genericFSM(){
    state = 0;
    rowCount = 2;
    columnCount = 2;
}

stateTypes genericFSM::getState(){
    return state;
}

char* genericFSM:: getErrorCode(){
    char a[] = "Error";
    return a;
}

void genericFSM:: cycle(eventType* ev){
    int a=0;
    a++;
}