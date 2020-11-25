#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bicicleta.h"
#include "LinkedList.h"




eBicicleta* bicicleta_new()
{
    return (eBicicleta*) malloc(sizeof(eBicicleta));
}

eBicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr)
{
    eBicicleta* nuevaBicicleta = bicicleta_new();

    if(nuevaBicicleta != NULL){
        if((bicicleta_setId(nuevaBicicleta,atoi(idStr))
            && bicicleta_setNombre(nuevaBicicleta, nombreStr)
            && bicicleta_setTipo(nuevaBicicleta, tipoStr)
            && bicicleta_setTiempo(nuevaBicicleta,atoi(tiempoStr)))){
            free(nuevaBicicleta);
            nuevaBicicleta = NULL;
           }
    }

    return nuevaBicicleta;
}

int bicicleta_setId(eBicicleta* this,int id){
    int todoOk = 0;
    if(this != NULL && id > 0){
        this->id_byke = id;
        todoOk = 1;
    }else{
        printf("Id invalido.\n");
    }
    return todoOk;
}

int bicicleta_getId(eBicicleta* this,int* id){
    int todoOk = 0;
    if(this != NULL && id > 0){
        *id = this->id_byke;
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_setNombre(eBicicleta* this,char* nombre){
    int todoOk = 0;
    if(this != NULL && nombre != NULL){
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_getNombre(eBicicleta* this,char* nombre){
    int todoOk = 0;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_setTipo(eBicicleta* this,char* tipo){
    int todoOk = 0;
    if(this != NULL && tipo != NULL){
        strcpy(this->tipo, tipo);
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_getTipo(eBicicleta* this,char* tipo){
    int todoOk = 0;
    if(this != NULL && tipo != NULL){
        strcpy(tipo, this->tipo);
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_setTiempo(eBicicleta* this,int tiempo){
    int todoOk = 0;
    if(this != NULL && tiempo > 0){
        this->tiempo = tiempo;
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_getTiempo(eBicicleta* this,int* tiempo){
    int todoOk = 0;
    if(this != NULL && tiempo > 0){
        *tiempo = this->tiempo;
        todoOk = 1;
    }
    return todoOk;
}

void printBicicleta(eBicicleta* bicicleta){
    if(bicicleta != NULL){
        printf("  %04d %20s       %12s         %6d     \n",bicicleta->id_byke, bicicleta->nombre, bicicleta->tipo, bicicleta->tiempo);
    }
}

int printBicicletas(LinkedList* bicicletas){
    int error = 1;
    int tam = ll_len(bicicletas);
    eBicicleta* auxBicleta;

    system("cls");
    printf("   ***LISTADO DE BICICLETAS***   \n\n");

    if(bicicletas != NULL){
        printf("  ID                Nombre                 Tipo             Tiempo\n");
        printf("--------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            auxBicleta = ll_get(bicicletas, i);
            if(auxBicleta != NULL){
                printBicicleta(auxBicleta);
                printf("--------------------------------------------------------------------\n");
            }
        }
        error = 0;
    }
    return error;
}

void* bicicleta_randomTiempo(void* bicicleta)
{
    int aleatorio;

    aleatorio = 50 + rand()% (120 - 50);
    eBicicleta* bici = NULL;

    if(bicicleta != NULL)
    {
        bici = (eBicicleta*)  bicicleta;
        bicicleta_setTiempo(bici, aleatorio);
    }
    return bici;
}

int filtrarBmx(void* bicicleta){
    int error = 0;
    char tipo[20] = "BMX";

    eBicicleta * bici = NULL;
    if(bicicleta != NULL)
    {
        bici = (eBicicleta*) bicicleta;
        if(!strcmp(bici->tipo, tipo))
        {
            error = 1;
        }
    }
    return error;
}

int filtrarPlayera(void* bicicleta){
    int error = 0;
    char tipo[20] = "PLAYERA";

    eBicicleta * bici = NULL;
    if(bicicleta != NULL)
    {
        bici = (eBicicleta*) bicicleta;
        if(!strcmp(bici->tipo, tipo))
        {
            error = 1;
        }
    }
    return error;
}

int filtrarMtb(void* bicicleta){
    int error = 0;
    char tipo[20] = "MTB";

    eBicicleta * bici = NULL;
    if(bicicleta != NULL)
    {
        bici = (eBicicleta*) bicicleta;
        if(!strcmp(bici->tipo, tipo))
        {
            error = 1;
        }
    }
    return error;
}

int filtrarPaseo(void* bicicleta){
    int error = 0;
    char tipo[20] = "PASEO";

    eBicicleta * bici = NULL;
    if(bicicleta != NULL)
    {
        bici = (eBicicleta*) bicicleta;
        if(!strcmp(bici->tipo, tipo))
        {
            error = 1;
        }
    }
    return error;
}

int sortTiempo(void* bicicletaA, void* bicicletaB){
    int error = 1;
    eBicicleta* biciA;
    eBicicleta* biciB;

    if(bicicletaA != NULL && bicicletaB != NULL)
    {
        biciA = (eBicicleta*)bicicletaA;
        biciB = (eBicicleta*)bicicletaB;

        if(biciA->tiempo < biciB->tiempo)
        {
            error = 0;
        }
    }
    return error;
}
int bicicletaSortByTipoYTiempo(void * bicicletaA, void* bicicletaB){
    int retorno = 0;
    eBicicleta* biciA;
    eBicicleta* biciB;

    if(bicicletaA != NULL && bicicletaB != NULL)
    {
        biciA = (eBicicleta*) bicicletaA;
        biciB = (eBicicleta*) bicicletaB;

        retorno = strcmp(biciA->tipo,biciB->tipo);

        if(!retorno)
        {
            retorno = sortTiempo(biciA,biciB);
        }
    }
    return retorno;
}
