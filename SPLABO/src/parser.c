#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


/** \brief Parsea los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
	char idStr[50], nombre[50], hsStr[50], sueldoStr[50];
	eLibro * newLibro;

	 if (pFile==NULL || pArrayListLibro==NULL) return 1;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, hsStr, sueldoStr);
	fflush(NULL);

	while(!feof(pFile)) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, hsStr, sueldoStr);
		fflush(NULL);
		newLibro = employee_newParametros(idStr, nombre, hsStr, sueldoStr);
		ll_add(pArrayListLibro, newLibro);
	}

    return 0;
}

/** \brief Parsea los datos de la lista de Libros al achivo de texto.
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int  0 en caso de exito, 1 en caso de error
 *
 */
int parser_TextFromLibro(FILE* pFile , LinkedList* pArrayListLibro){
	eLibro * aux;
    int i=0;
    int id, sueldo, hs;
    char nombre[128];

    if (pFile==NULL || pArrayListLibro==NULL) return 1;

    while((aux = (eLibro *)ll_get(pArrayListLibro, i)) != NULL){
    	employee_getNombre(aux, nombre);
    	employee_getId(aux, &id);
    	employee_getSueldo(aux, &sueldo);
    	employee_getHorasTrabajadas(aux, &hs);
    	fprintf(pFile, "%d,%s,%d,%d\n",id,nombre,hs,sueldo);
    	i++;
    }
	return 0;
}

/** \brief Parsea los datos de los editoriales desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEditorial LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial)
{
	char idStr[50], nombre[50], hsStr[50], sueldoStr[50];
	eEditorial * newEditorial;

	 if (pFile==NULL || pArrayListEditorial==NULL) return 1;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, hsStr, sueldoStr);
	fflush(NULL);

	while(!feof(pFile)) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, hsStr, sueldoStr);
		fflush(NULL);
		newEditorial = employee_newParametros(idStr, nombre, hsStr, sueldoStr);
		ll_add(pArrayListEditorial, newEditorial);
	}

    return 0;
}

