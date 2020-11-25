#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicleta.h"
#include "parser.h"
//#include "FPUTN.h"
#include "Controller.h"


/** \brief Carga los datos de las bicicletas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBicicletas)
{
    int error = 1;
    FILE* pFile;

    pFile = fopen(path, "r");
    if(pFile != NULL){
        if(!parser_BicicletaFromText(pFile, pArrayListBicicletas)){
            error = 0;
        }
    }

    fclose(pFile);

    return error;
}

int controller_ListBicicletas(LinkedList* pArrayListBicicletas)
{
    return printBicicletas(pArrayListBicicletas);
}

int controller_AsignarTiempo(LinkedList* pArrayListBicicletas){
    int error = 1;

    if(pArrayListBicicletas){
        pArrayListBicicletas = ll_map(pArrayListBicicletas, bicicleta_randomTiempo);
        printBicicletas(pArrayListBicicletas);
        error = 0;

    }
    return error;
}

int controller_filtrarTipos(LinkedList* pArrayListBicicletas){
    int error = 1;
    int opcion;
    int flagSalir = 0;
    int flagDef = 0;
    LinkedList* listaFiltrada = NULL;
    if(pArrayListBicicletas != NULL){
        system("cls");

        printf("   *** FILTRAR BICICLETAS POR TIPO ***   \n\n");
        printf("1) FILTRAR BMX.\n");
        printf("2) FLITRAR PLAYERA.\n");
        printf("3) FLITRAR MTB.\n");
        printf("4) FLITRAR PASEO.\n");
        printf("5) MENU ANTERIOR.\n");
        printf("Seleccione un opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                listaFiltrada = ll_filter(pArrayListBicicletas,filtrarBmx);

                if(!controller_saveAsText("BMX.csv", listaFiltrada))
                {
                    printf("Lista guardada con exito!\n\n");
                }

                printBicicletas(listaFiltrada);
                break;
            case 2:
                listaFiltrada = ll_filter(pArrayListBicicletas,filtrarPlayera);

                if(!controller_saveAsText("PLAYERA.csv", listaFiltrada))
                {
                    printf("Lista guardada con exito!\n\n");
                }

                printBicicletas(listaFiltrada);
                break;
            case 3:
                listaFiltrada = ll_filter(pArrayListBicicletas,filtrarMtb);

                if(!controller_saveAsText("MTB.csv", listaFiltrada))
                {
                    printf("Lista guardada con exito!\n\n");
                }

                printBicicletas(listaFiltrada);
                break;
            case 4:
                listaFiltrada = ll_filter(pArrayListBicicletas,filtrarPaseo);

                if(!controller_saveAsText("PASEO.csv", listaFiltrada))
                {
                    printf("Lista guardada con exito!\n\n");
                }

                printBicicletas(listaFiltrada);
                break;
            case 5:
                flagSalir = 1;
                error = 2;
                break;
            default:
                flagDef = 1;
                printf("Opcion no valida.\n");
                break;
            }
            if(!flagSalir && !flagDef && error != 2){
                error = 0;
            }else{
                error = 2;
            }

    }

    return error;
}

int controller_saveAsText(char* path, LinkedList* pArrayListBicicletas)
{
    int error = 1;

    FILE* pFile;
    eBicicleta* bicicleta;

    if(path != NULL && pArrayListBicicletas!= NULL)
    {
        pFile = fopen(path, "w");
        fprintf(pFile,"id_bike,nombre,tipo,tiempo\n");

        for(int i=0; i < ll_len(pArrayListBicicletas); i++)
        {
            bicicleta = (eBicicleta*)ll_get(pArrayListBicicletas, i);
            if(bicicleta != NULL)
            {
                fprintf(pFile, "%d,%s,%s,%d,\n", bicicleta->id_byke, bicicleta->nombre, bicicleta->tipo, bicicleta->tiempo);
            }
        }
        error = 0;

        free(bicicleta);
        fclose(pFile);
    }
    return error;
}

int controller_sort(LinkedList* pArrayListBicicletas){
    int error = 1;
    if(pArrayListBicicletas != NULL){
        ll_sort(pArrayListBicicletas,bicicletaSortByTipoYTiempo, 1);
        printBicicletas(pArrayListBicicletas);
        error = 0;
    }
    return error;
}
