/*
 ============================================================================
 Name        : SPLABO.c
 Author      : Dayher Marchan
 Version     :
 Copyright   :
 Description :
				1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro.
				2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial.
				3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente.
				4. Imprimir por pantalla todos los datos de los libros.
				5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Editorial.h"
#include "Libro.h"
#include "LinkedList.h"
#include "input.h"

int main(void)
{
	LinkedList * pListEditoriales;
	LinkedList * pListLibros;
	int opcion=10;

	pListEditoriales = ll_newLinkedList();
	pListLibros = ll_newLinkedList();

	while(opcion!=9)
	{
		opcion = controller_mostrarMenu();

		switch(opcion)
		{
			case  1:
				controller_loadLibroFromText("libros.csv", pListLibros);
				break;
			case  2:
				controller_loadEditorialFromText("editoriales.csv", pListEditoriales);
				break;
			case  3:
				controller_ListLibro(pListLibros, pListEditoriales);
				break;
			case  4:
				controller_sortLibro(pListLibros);
				break;
			case  5:
				controller_filtrarEditorialMinotauro(pListLibros, "editorialMinotauro.csv");
				break;
			case  6:
				controller_mapLibros(pListLibros,"librosMap.csv");
				break;
			case  7:
				controller_informarCantidadPrecioMayor(pListLibros);
				break;
			case  8:
				controller_informarSumaEditorialPearson(pListLibros);
				break;
			case  9:
				ll_deleteLinkedList(pListLibros);
				ll_deleteLinkedList(pListEditoriales);
				break;
			default:
				printf("\nOpcion invalida\n");
		}
	}
	return EXIT_SUCCESS;
}


