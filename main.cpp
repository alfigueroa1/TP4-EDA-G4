#ifdef _WIN32 
#define _CRT_SECURE_NO_DEPRECATE 
#endif

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
	genericFSM* stackFSMs[100];
    int error = 0, quit = 0;
    int instance;
    eventType ev = NOEVENT;
    FILE *archivo;
	stackFSMs[0] = &palabra;
    if((archivo = fopen("archivoJson.txt","r")) == NULL){
        printf("Error al intentar abrir el archivo de Json\n");
        error = -1;
    }
    else{
        unsigned int stackLevel = 0, last = 0;
        while(ev != EOF && !quit){
            ev = getNextEvent(archivo);
            if(ev != NOEVENT){
				stackFSMs[stackLevel]->cycle(&ev);
				if ((stackFSMs[stackLevel]->getState()) == ERROR)
					quit = 1;
				else if ((stackFSMs[stackLevel]->getState()) == FIN)
					stackLevel--;
				else if ((stackFSMs[stackLevel]->getState()) == OBJSTRING || (stackFSMs[stackLevel]->getState()) == OBJARRAY) {
					if ((stackFSMs[stackLevel]->getState()) == OBJSTRING)
						stackFSMsPop(1, stackFSMs, stackLevel);
					else if ((stackFSMs[stackLevel]->getState()) == OBJARRAY)
						stackFSMsPop(0, stackFSMs, stackLevel);
					stackLevel++;
					last = stackLevel;
					printf("StackLevel: %d\n", stackLevel);
/*				else {					//(Reemplaza el ultimo else if)
					stackFSMsPop(stackFSMs[stackLevel]->getState(), stackFSMs, stackLevel);
					stackLevel++;
					last = stackLevel;
					printf("StackLevel: %d\n", stackLevel);
				}
*/
				}
            }
        }
        if(quit){
            for(int i = 0; i < last; i++)
                if((stackFSMs[i]->getState()) == ERROR){
					printf("%s\n", stackFSMs[i]->getErrorCode());
                    error = -1;
                }
        }
        else
            cout<<"Archivo valido"<<endl;
		for (int i = 1; i < (last + 1); i++)
				free(stackFSMs[i]);
        free(archivo);
    }
    //free(archivo);
    //}
    return error;
}

