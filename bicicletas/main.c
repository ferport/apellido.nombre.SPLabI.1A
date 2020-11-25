#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include <ctype.h>
#include <time.h>
#include "menu.h"

int main()
{
    srand (time(NULL));
    int rta;
    char seguir = 's';
    char confirmacion;
    int flagOrdenar = 0;
    int flagCargar = 0;
    LinkedList* listaBicicletas = ll_newLinkedList();

     do{
        switch(menu())
        {
            case 1:
                if(flagCargar == 0){
                    if(!controller_loadFromText("data.cvs",listaBicicletas)){
                        printf("Datos cargados con exito.\n");
                        flagCargar = 1;
                    }else{
                        printf("Error al cargar los datos.\n");
                        exit(EXIT_FAILURE);
                    }
                }else{
                    printf("Solo puede cargar los datos 1 vez.\n");
                }
                break;
            case 2:
                if(ll_isEmpty(listaBicicletas) == 0){
                    controller_ListBicicletas(listaBicicletas);
                }else{
                    printf("Lista vacia.\n");
                }
                break;
            case 3:
                if(ll_isEmpty(listaBicicletas) == 0){
                    controller_AsignarTiempo(listaBicicletas);
                }else{
                    printf("Lista vacia.\n");
                }
                break;
            case 4:
                if(ll_isEmpty(listaBicicletas) == 0){
                    rta = controller_filtrarTipos(listaBicicletas);
                    if(!rta){
                        printf("Filtrado realizad con exito.\n");
                    }else if(rta == 2){
                        printf("Filtrado cancelado por el usuario.\n");
                    }else{
                        printf("Error en la filtracion.\n");
                    }
                }else{
                    printf("Lista vacia.\n");
                }
                break;
            case 5:
                if(ll_isEmpty(listaBicicletas) == 0){
                    if(!controller_sort(listaBicicletas)){
                        flagOrdenar = 1;
                    }else{
                        printf("Error al ordenar.\n");
                    }
                }else{
                    printf("Lista vacia.\n");
                }
                break;
            case 6:
                if(ll_isEmpty(listaBicicletas) == 0){
                    if(flagOrdenar == 1){
                        if(!controller_saveAsText("listaOrdenado.cvs",listaBicicletas)){
                            printf("Datos guardados con exito.\n");
                        }else{
                            printf("Error al guardar los datos.\n");
                        }
                    }else{
                        printf("Debe ordenar la lista para guardarla.\n");
                    }

                }else{
                    printf("Lista vacia.\n");
                }
                break;
            case 7:
                printf("Confirma la salida?(s/n)");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);
                if(confirmacion == 's'){
                seguir = 'n';
                ll_deleteLinkedList(listaBicicletas);
                }
                break;
            default:
                printf("Opcion invalida.\n");

        }
    system("pause");
    }while(seguir == 's');


    return 0;
}
