#include "Libro.h"
#include <stdlib.h>
#include <string.h>

int libro_getId(eLibro *this, int * id)
{
	int retorno=1;

	if(this!=NULL && id != NULL)
	{
		(*id) = this->id;
		retorno=0;
	}
	return retorno;
}

int libro_setId(eLibro* this,int id)
{
	int retorno=1;

	if(this!=NULL){
		this->id = id;
		retorno=0;
	}
	return retorno;
}

int libro_getAutor(eLibro *this, char autor[])
{
	int retorno=1;

	if(this!=NULL && autor!=NULL)
	{
		strcpy(autor, this->autor);
		retorno=0;
	}
	return retorno;
}
int libro_setAutor(eLibro *this, char autor[])
{
	int retorno=1;

	if(this!=NULL && autor!=NULL)
	{
		strcpy(this->autor, autor);
		retorno=0;
	}
	return retorno;
}

int libro_getTitulo(eLibro *this,char titulo[])
{
	int retorno=1;

	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo, this->titulo);
		retorno=0;
	}
	return retorno;
}
int libro_setTitulo(eLibro *this,char titulo[])
{
	int retorno=1;

	if(this!=NULL && titulo!=NULL)
	{
		strcpy(this->titulo, titulo);
		retorno=0;
	}
	return retorno;
}

int libro_getPrecio(eLibro *this, float *precio)
{
	int retorno=1;

	if(this!=NULL && precio != NULL)
	{
		(*precio) = this->precio;
		retorno=0;
	}
	return retorno;
}

int libro_setPrecio(eLibro* this,float precio)
{
	int retorno=1;

	if(this!=NULL){
		this->precio = precio;
		retorno=0;
	}
	return retorno;
}

int libro_getIdEditorial(eLibro *this,int * idEditorial)
{
	int retorno=1;

	if(this!=NULL && idEditorial!=NULL)
	{
		(*idEditorial) = this->idEditorial;
		retorno=0;
	}
	return retorno;
}

int libro_setIdEditorial(eLibro* this,int idEditorial)
{
	int retorno=1;

	if(this!=NULL)
	{
		this->idEditorial = idEditorial;
		retorno=0;
	}
	return retorno;
}

int compararLibrosPorAutor(void* primero, void* segundo)
{
	char autor1[MAX_CADENA];
	char autor2[MAX_CADENA];

	if(primero!=NULL && segundo!=NULL)
	{
		libro_getAutor((eLibro*)primero,autor1);
		libro_getAutor((eLibro*)segundo,autor2);
	}
	return strcmp(autor1,autor2);
}

eLibro * libro_newParametros(char *idStr, char *titulo, char *autor,char* precioStr, char* idEditorial)
{
	eLibro * newLibro;

	if((newLibro=libro_new())!=NULL)
	{
		if(idStr!=NULL && titulo!=NULL && autor!=NULL && precioStr!=NULL && idEditorial!=NULL)
		{
			libro_setId(newLibro,atoi(idStr));
			libro_setIdEditorial(newLibro,atoi(idEditorial));
			libro_setAutor(newLibro,autor);
			libro_setTitulo(newLibro,titulo);
			libro_setPrecio(newLibro,atof(precioStr));
		}
	}
	return newLibro;
}

eLibro * libro_new(void)
{
	eLibro * newLibro;

	newLibro=(eLibro*) malloc(sizeof(eLibro));

	return newLibro;
}
