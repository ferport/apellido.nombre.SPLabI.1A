#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"


int parser_BicicletaFromText(FILE* pFile , LinkedList* pArrayListBicicletas)
{
    int error = 1;
    int cant;
    char buffer[4][128];
    eBicicleta* auxBicicleta;

    if(pFile != NULL){
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        while(!feof(pFile)){
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if(cant == 4){
                auxBicicleta = bicicleta_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                ll_add(pArrayListBicicletas, auxBicicleta);
            }else{
                break;
            }

        }
        error = 0;
    }
    return error;
}
