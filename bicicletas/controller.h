#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED


int controller_loadFromText(char* path , LinkedList* pArrayListBicicletas);
int controller_ListBicicletas(LinkedList* pArrayListBicicletas);
int controller_AsignarTiempo(LinkedList* pArrayListBicicletas);
int controller_filtrarTipos(LinkedList* pArrayListBicicletas);
int controller_saveAsText(char* path, LinkedList* pArrayListBicicletas);
int controller_sort(LinkedList* pArrayListBicicletas);
