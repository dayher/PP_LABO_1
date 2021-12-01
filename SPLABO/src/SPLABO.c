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
	int flag1=0;
	int flag2=0;

	pListEditoriales = ll_newLinkedList();
	pListLibros = ll_newLinkedList();

	while(opcion!=9)
	{
		opcion = controller_mostrarMenu(&flag1,&flag2);

		switch(opcion)
		{
			case  1:
				if(controller_loadLibroFromText("libros.csv", pListLibros)==0){
					printf("\nCARGA EXITOSA\n");
				} else {
					printf("\nCARGA FALLIDA\n");
				}

				break;
			case  2:
				if(controller_loadEditorialFromText("editoriales.csv", pListEditoriales)==0){
					printf("\nCARGA EXITOSA\n");
				} else {
					printf("\nCARGA FALLIDA\n");
				}
				break;
			case  3:
				if(controller_ListLibro(pListLibros, pListEditoriales)==0){
					printf("\nFIN DEL LISTADO\n");
				} else {
					printf("\nNO SE HA LOGRADO LISTAR\n");
				}
				break;
			case  4:
				if(controller_sortLibro(pListLibros)==0){
					printf("\nLISTA ORDENADA\n");
				} else {
					printf("\nNO SE HA ORDENADO EL LISTADO\n");
				}

				break;
			case  5:
				if(controller_filtrarEditorialMinotauro(pListLibros, "editorialMinotauro.csv")==0){
					printf("\nFILTRADO EXITOSO\n");
				} else {
					printf("\nNO SE HA FILTRADO LA LISTA\n");
				}

				break;
			case  6:
				if(controller_mapLibros(pListLibros,"mapeado.csv")==0){
					printf("\nMAPEADO EXITOSO\n");
				} else {
					printf("\nNO SE HA MAPEADO LA LISTA\n");
				}
				break;
			case  7:
				if(controller_informarCantidadPrecioMayor(pListLibros)==0){
					printf("\n\n");
				} else {
					printf("\nNO SE LOGRO CONTABILIZAR\n");
				}
				break;
			case  8:
				if(controller_informarSumaEditorialPearson(pListLibros)==0){
					printf("\n\n");
				} else {
					printf("\nNO SE LOGRO SUMAR LOS PRECIOS\n");
				}
				break;
			case  9:
				ll_deleteLinkedList(pListLibros);
				ll_deleteLinkedList(pListEditoriales);
				printf("\nFIN DEL PROGRAMA\n");
				break;
			default:
				printf("\nOpcion invalida\n");
		}
	}
	return EXIT_SUCCESS;
}

