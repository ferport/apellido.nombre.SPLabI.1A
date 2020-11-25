#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include <ctype.h>
#include <time.h>
#include "menu.h"

int menu(void){
    int opcion;

    system("cls");

    printf("   ***BICICLETAS***\n\n");
    printf("1) Cargar archivos.\n");
    printf("2) Imprimir lista.\n");
    printf("3) Asignar tiempo.\n");
    printf("4) Filtrar por tipo.\n");
    printf("5) Ordenar por tipo y tiempo.\n");
    printf("6) Guardar lista ordenada.\n");
    printf("7) Salir.\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
