#include <iostream>
#include <cstdlib>
#include "genericFSM.h"
#include "partFSM.h"
#include "events.h"
#include "instancia.h"

using namespace std;

int main(int argc, char** argv) {
    FSMArray arreglo;
    FSMString palabra;
    genericFSM* stackFSMs[] = {&arreglo, &palabra};
    int error = 0, quit = 0;
    int instance;
    eventType ev = NOEVENT;
    FILE *archivo;
    if((archivo = fopen("archivoJson.txt","r")) == NULL){
        printf("Error al intentar abrir el archivo de Json\n");
        error = -1;
    }
    else{
        unsigned int stackLevel = 0, last = 0;
        while(ev != EOF && !quit){
            ev = getNextEvent(archivo);
            if(ev != NOEVENT){
                if(instance = detectNewInstance(ev)){
                    //stackFSMsPop(FSMs[instance]);
                    stackLevel++;
                }
                else{
                    stackFSMs[stackLevel]->cycle(&ev);
                    if((stackFSMs[stackLevel]->getState()) == ERROR)
                        quit = 1;
                    else if((stackFSMs[stackLevel]->getState()) == FIN){
                        if(!last)
                            last = stackLevel;
                        stackLevel--;
                    }
                }
            }
        }
        if(quit){
            for(int i = 0; i < last; i++)
                if((stackFSMs[i]->getState()) == ERROR){
                    cout<< stackFSMs[i]->getErrorCode() << endl;
                    error = -1;
                }
        }
        else
            cout<<"Archivo valido"<<endl;
        free(archivo);
    }
    //free(archivo);
    //}
    return error;
}

