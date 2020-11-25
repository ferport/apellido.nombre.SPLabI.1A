#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

#include "LinkedList.h"

typedef struct{
    int id_byke;
    char nombre[50];
    char tipo[20];
    int tiempo;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

eBicicleta* bicicleta_new();
eBicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr);

int bicicleta_setId(eBicicleta* this,int id);
int bicicleta_getId(eBicicleta* this,int* id);

int bicicleta_setNombre(eBicicleta* this,char* nombre);
int bicicleta_getNombre(eBicicleta* this,char* nombre);

int bicicleta_setTipo(eBicicleta* this,char* tipo);
int bicicleta_getTipo(eBicicleta* this,char* tipo);

int bicicleta_setTiempo(eBicicleta* this,int tiempo);
int bicicleta_getTiempo(eBicicleta* this,int* tiempo);

void printBicicleta(eBicicleta* bicicleta);
int printBicicletas(LinkedList* bicicletas);

void* bicicleta_randomTiempo(void* bicicleta);

int filtrarBmx(void* bicicleta);
int filtrarPlayera(void* bicicleta);
int filtrarMtb(void* bicicleta);
int filtrarPaseo(void* bicicleta);

int bicicletaSortByTipoYTiempo(void* bicicletaA, void* bicicletaB);
