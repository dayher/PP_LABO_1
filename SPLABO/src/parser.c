#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"

/** \brief Parsea los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
	char idStr[MAX_CADENA],
	titulo[MAX_CADENA],
	autor[MAX_CADENA],
	precioStr[MAX_CADENA],
	idEditorial[MAX_CADENA];
	eLibro * newLibro;
	int retorno=1;

	 if (pFile!=NULL && pArrayListLibro!=NULL)
	 {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,]%[^\n]\n", idStr, titulo, autor, precioStr, idEditorial);
		fflush(NULL);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, titulo, autor, precioStr, idEditorial);
			fflush(NULL);
			newLibro = libro_newParametros(idStr, titulo, autor, precioStr, idEditorial);
			ll_add(pArrayListLibro, newLibro);
		}
		retorno=0;
	 }
    return retorno;
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
    int id, idEditorial;
    float precio;
    char titulo[128];
    char autor[128];
    int retorno=1;

    if (pFile!=NULL && pArrayListLibro!=NULL)
    {
		while((aux = (eLibro *)ll_get(pArrayListLibro, i)) != NULL)
		{
			libro_getId(aux, &id);
			libro_getAutor(aux, autor);
			libro_getTitulo(aux, titulo);
			libro_getPrecio(aux, &precio);
			libro_getIdEditorial(aux,&idEditorial);
			fprintf(pFile, "%d,%s,%d,%f\n",id,titulo,idEditorial,precio); // guardar nombre del editorial no su id
			i++;
		}
    	retorno=0;
    }
	return retorno;
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
	char idStr[50], nombre[50];
	eEditorial * newEditorial;
	int retorno=1;

	 if (pFile!=NULL && pArrayListEditorial!=NULL)
	 {
		fscanf(pFile, "%[^,],%[^\n]\n", idStr, nombre);
		fflush(NULL);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^\n]\n", idStr, nombre);
			fflush(NULL);
			newEditorial = editorial_newParametros(idStr, nombre);
			ll_add(pArrayListEditorial, newEditorial);
		}
		retorno=0;
	 }
    return retorno;
}

