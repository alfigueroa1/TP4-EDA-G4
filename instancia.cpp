#include <iostream>
#include "events.h"

using namespace std;

int detectNewInstance(eventType){
    static int a = 0;
    a++;
    if(a >= 5)
        return a;
    else
        return 0;
}