#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libro.h"
#include "Editorial.h"
#include "input.h"

/** \brief Carga los datos de los libros desde el archivo libros.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_loadLibroFromText(char* path , LinkedList* pArrayListLibro)
{
	FILE * pFile;
	int retorno=1;

	if((pFile = fopen(path,"r"))!=NULL)
	{
		retorno=0;
		if(parser_LibroFromText(pFile, pArrayListLibro)){
			retorno=1;
		}

		fclose(pFile);
	}
    return retorno;
}

/** \brief Listar libros
 *
 * \param pArrayListLibro LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_ListLibro(LinkedList* pArrayListLibro)
{
	eLibro * aux;
	int id, idEditorial; // debe mostrarse el nombre del editorial no su id
	float precio;
	char titulo[128];
	char autor[128]; //Falta agregar este campo al listado
    int i=0;
    int retorno=1;

    if(pArrayListLibro != NULL)
    {
		printf("\n\t\tLISTADO:\n\n"
				" ID \t|\tTITULO    \t\t\t| EDITORIAL \t|\t PRECIO\n"
				"__________________________________________________________________________________\n");

		while((aux = (eLibro *) ll_get(pArrayListLibro, i)) != NULL)
		{
			libro_getId(aux, &id);
			libro_getAutor(aux, autor);
			libro_getTitulo(aux, titulo);
			libro_getPrecio(aux, &precio);
			libro_getIdEditorial(aux,&idEditorial);
			printf("  %d\t|\t%-32s|\t%d\t|\t%.2f\n", id,titulo,idEditorial,precio);
			i++;
		}
    	retorno=0;
    }
    return retorno;
}

/** \brief Ordenar libros
 *
 * \param pArrayListLibro LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_sortLibro(LinkedList* pArrayListLibro)
{
	int order;
	int retorno=1;

	if(pArrayListLibro != NULL)
	{
		order = 1;//getInt("\nIngrese orden: ", -1,1);
		ll_sort(pArrayListLibro, &compararLibrosPorAutor, order);
		retorno=0;
	}
    return retorno;
}

/** \brief Guarda los datos de los libros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListLibro)
{
	FILE * pFile;
	int retorno=1;

	if(path != NULL && pArrayListLibro != NULL)
	{
		retorno=0;

		if((pFile = fopen(path,"w")) == NULL) retorno=1;

		if(parser_TextFromLibro(pFile , pArrayListLibro)){
			fclose(pFile);
			retorno=1;
		}

		if(fclose(pFile)==EOF) retorno=1;
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEditorial LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_loadEditorialFromText(char* path , LinkedList* pArrayListEditorial)
{
	FILE * pFile;
	int retorno=1;

	if(path!=NULL && pArrayListEditorial!=NULL)
	{
		retorno=0;

		if((pFile = fopen(path,"r"))==NULL) retorno=1;

		if(parser_EditorialFromText(pFile, pArrayListEditorial)) retorno=1;

		fclose(pFile);

	}
    return retorno;
}
