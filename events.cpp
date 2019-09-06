#include <iostream>
#include "events.h"

using namespace std;

const char entradas[] = {EOF, ' ', '(', ')', '{', '}', ']', '[', '"', ':', '/', 'f', 'n', 'r', 't', 'b', ','};

eventType getNextEvent(FILE* archivo){
    short caracter;
    caracter = fgetc(archivo);
    for(int i = 0; i < (sizeof(entradas)/sizeof(char)); i++){
        if(caracter == entradas[i])
            return caracter;
    }
    return NOEVENT;
}

