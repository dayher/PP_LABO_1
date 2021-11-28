#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadLibroFromText(char* path , LinkedList* pArrayListLibro);
int controller_ListLibro(LinkedList* pArrayListLibro);
int controller_sortLibro(LinkedList* pArrayListLibro);
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro);
int parser_TextFromLibro(FILE* pFile , LinkedList* pArrayListLibro);

int controller_loadEditorialFromText(char* path , LinkedList* pArrayListEditorial);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);

#endif /* CONTROLLER_H_ */
