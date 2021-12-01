#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

int controller_loadLibroFromText(char* path , LinkedList* pArrayListLibro);
int controller_ListLibro(LinkedList* pArrayListLibro, LinkedList *pArrayListEditorial);
int controller_sortLibro(LinkedList* pArrayListLibro);
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro);
int parser_TextFromLibro(FILE* pFile , LinkedList* pArrayListLibro);

int controller_loadEditorialFromText(char* path , LinkedList* pArrayListEditorial);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);
int comprobarListadoMinotauro(void * libro);
int controller_filtrarEditorialMinotauro(LinkedList* pArrayListLibro, char path[]);
int controller_mapLibros(LinkedList* pArrayListLibro,char path[]);
int controller_criterioDescuento(void * libro);
int controller_mostrarMenu(void);

#endif /* CONTROLLER_H_ */
