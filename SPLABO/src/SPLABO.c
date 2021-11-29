/*
 ============================================================================
 Name        : SPLABO.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Editorial.h"
#include "Libro.h"
#include "LinkedList.h"

int main(void)
{
	LinkedList * pListEditoriales;
	LinkedList * pListLibros;

	pListEditoriales = ll_newLinkedList();
	pListLibros = ll_newLinkedList();

	controller_loadLibroFromText("libros.csv", pListLibros);
	controller_loadEditorialFromText("editoriales.csv", pListEditoriales);
	controller_sortLibro(pListLibros);
	controller_ListLibro(pListLibros);

	return EXIT_SUCCESS;
}
