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
int controller_ListLibro(LinkedList* pArrayListLibro, LinkedList *pArrayListEditorial)
{
	eLibro * aux;
	eEditorial * editorial;
	int id, idEditorial; // debe mostrarse el nombre del editorial no su id
	char nombreEditorial[128];
	float precio;
	char titulo[128];
	char autor[128]; //Falta agregar este campo al listado
    int i=0,j=0;
    int retorno=1;

    if(pArrayListLibro != NULL && pArrayListEditorial!=NULL)
    {
		printf(	"----------------------------------------------------------------------------------------------------------------------------------\n"
				"\tID \t\tTITULO    \t\t\t\tAUTOR\t\t\tEDITORIAL \t\t\tPRECIO\n"
				"----------------------------------------------------------------------------------------------------------------------------------\n");

		while((aux = (eLibro *) ll_get(pArrayListLibro, i)) != NULL)
		{
			libro_getId(aux, &id);
			libro_getAutor(aux, autor);
			libro_getTitulo(aux, titulo);
			libro_getPrecio(aux, &precio);
			libro_getIdEditorial(aux,&idEditorial);

			while((editorial = (eEditorial *) ll_get(pArrayListEditorial, j)) != NULL)
			{
				if(idEditorial==(editorial->idEditorial))
				{
					editorial_getNombre(editorial, nombreEditorial);
					j=0;
					break;
				}
				j++;
			}

			printf("\t%d\t|\t%-32s|\t%-15s|\t%-20s\t|\t%.2f\n",id,titulo, autor,nombreEditorial,precio);
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

int controller_filtrarEditorialMinotauro(LinkedList* pArrayListLibro, char path[])
{
	int retorno= -1;
	FILE * pFile;

	LinkedList * newLinkedList;

	if(pArrayListLibro!=NULL && path!=NULL)
	{
		newLinkedList = ll_filter(pArrayListLibro,&comprobarListadoMinotauro);

		pFile = fopen(path,"wt");

		if(pFile!=NULL)
		{
			parser_TextFromLibro(pFile, newLinkedList);

			if((fclose(pFile))!=EOF)
			{
				ll_deleteLinkedList(newLinkedList);
				retorno=0;
			}
		}
	}
	return retorno;
}

int comprobarListadoMinotauro(void * libro)
{
	eLibro* aux;
	int idEditorial;
	int retorno=0;

	if(libro!=NULL)
	{
		aux = (eLibro*) libro;
		libro_getIdEditorial(aux,&idEditorial);
		if(idEditorial==103){
			retorno=1;
		}
	}

	return retorno;
}

int controller_mapLibros(LinkedList* pArrayListLibro,char path[])
{
	int retorno = -1;
	LinkedList * listaMap;

	if(path != NULL && pArrayListLibro != NULL)
	{
		retorno = 0;

		listaMap = ll_clone(pArrayListLibro);
		ll_map(listaMap, controller_criterioDescuento);
		controller_saveAsText(path, listaMap);
		ll_deleteLinkedList(listaMap);
	}
	return retorno;
}

int controller_criterioDescuento(void * libro)
{
	int retorno = 0;
	eLibro *aux;
	int idEditorial;
	float precio;

	aux = (eLibro*) libro;
	libro_getIdEditorial(aux, &idEditorial);
	libro_getPrecio(aux, &precio);
	if(idEditorial == 100 && precio > 299)
	{
		precio*=0.7;
		libro_setPrecio(aux, precio);
		retorno = 1;
	}
	if(idEditorial == 101 && precio < 201)
	{
		precio*=0.9;
		libro_setPrecio(aux, precio);
		retorno = 1;
	}
	return retorno;
}
int controller_mostrarMenu(int *flag1 , int* flag2)
{
	int opcion;

	printf("\n1)CARGAR ARCHIVO LIBROS\n"
			"2)CARGAR ARCHIVO EDITORIALES\n"
			"3)LISTAR LIBROS\n"
			"4)ORDENAR\n"
			"5)FILTRAR\n"
			"6)MAPEAR\n"
			"7)CONTAR LIBROS PRECIO MAYOR A 500\n"
			"8)SUMATORIA DE PRECIOS EDITORIAL PEARSON\n"
			"9)SALIR\n");

	opcion = getInt("\nIngrese una opcion:\n",0,10);

	if (opcion==1) (*flag1=1);
	if (opcion==2) {
		(*flag2=1);
	} else {
		while(opcion>2 && (*flag1)==0 && (*flag2)==0)
		{
			opcion = getInt("\nPrimero debe cargar los listados\n"
							"\nIngrese una opcion:\n",0,10);
		}
	}


	return opcion;
}

int controller_informarCantidadPrecioMayor(LinkedList* pArrayListLibro)
{
	int retorno= -1;
	int cantidad;

	if(pArrayListLibro!=NULL)
	{
		cantidad = ll_count(pArrayListLibro,comprobarPrecioMayor);
		printf("\nCantidad de libros con precio mayor a 500: %d\n", cantidad);
	}

	return retorno;
}
int controller_informarSumaEditorialPearson(LinkedList* pArrayListLibro)
{
	int retorno =-1;
	int i=0;
	float acumulador=0;
	float precio;
	LinkedList * newList;
	eLibro * aux;

	if(pArrayListLibro!=NULL)
	{
		newList = ll_filter(pArrayListLibro, comprobarListadoPearson);

		while((aux = (eLibro *) ll_get(newList, i)) != NULL)
		{
			libro_getPrecio(aux, &precio);
			acumulador= acumulador+precio;
			i++;
		}

		printf("\nLa Sumatoria de los precios de la Editorial Pearson es: %f  cantidad de libros: %d\n", acumulador, ll_len(newList));
    	retorno=0;
	}

	return retorno;
}
int comprobarListadoPearson(void *libro)
{
	eLibro* aux;
	int idEditorial;
	int retorno=0;

	if(libro!=NULL)
	{
		aux = (eLibro*) libro;
		libro_getIdEditorial(aux,&idEditorial);
		if(idEditorial==102){
			retorno=1;
		}
	}
	return retorno;
}
int comprobarPrecioMayor(void * libro)
{
	eLibro* aux;
	float precio;
	int retorno=0;

	if(libro!=NULL)
	{
		aux = (eLibro*) libro;
		libro_getPrecio(aux,&precio);
		if(precio>500){
			retorno=1;
		}
	}
	return retorno;
}





