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
int controller_loadFromText(char* path , LinkedList* pArrayListLibro)
{
	FILE * pFile;

	if((pFile = fopen(path,"rb"))==NULL) return 1;

	if(parser_LibroFromText(pFile, pArrayListLibro)) return 1;

	fclose(pFile);

    return 0;
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
	int id, hs, sueldo;
	char nombre[128];
    int i=0;

    if(pArrayListLibro == NULL) return 1;

    printf("\n\t\t\tLISTADO:\n\n"
    		"\t ID \t|\t      NOMBRE       |\t HORAS \t|\t SUELDO\n"
    		"______________________________________________________________________________\n");
    while((aux = (Libro *) ll_get(pArrayListLibro, i)) != NULL){
    	employee_getId(aux, &id);
    	employee_getNombre(aux, nombre);
    	employee_getHorasTrabajadas(aux, &hs);
    	employee_getSueldo(aux, &sueldo);
    	printf("\t%d\t|\t%-20s|\t%d\t|\t%d\n", id,nombre,hs,sueldo);
    	i++;
    }
    return 0;
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

	if(pArrayListLibro == NULL) return 1;

	order = 1;//getInt("\nIngrese orden: ", -1,1);

	ll_sort(pArrayListLibro, &compararLibrosPorAutor, order);

    return 0;
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

	if(path == NULL || pArrayListLibro == NULL) return 1;

	if((pFile = fopen(path,"w")) == NULL) return 1;

	if(parser_TextFromLibro(pFile , pArrayListLibro)){
		fclose(pFile);
		return 1;
	}
	if(fclose(pFile)==EOF) return 1;

    return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEditorial LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEditorial)
{
	FILE * pFile;

	if((pFile = fopen(path,"rb"))==NULL) return 1;

	if(parser_EditorialFromText(pFile, pArrayListEditorial)) return 1;

	fclose(pFile);

    return 0;
}
