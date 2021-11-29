#include "Editorial.h"
#include <stdlib.h>
#include <string.h>

int editorial_getNombre(eEditorial *this, char nombre[])
{
	int retorno=1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=0;
	}
	return retorno;
}

int editorial_getIdEditorial(eEditorial *this,int * idEditorial)
{
	int retorno=1;

	if(this!=NULL && idEditorial!=NULL)
	{
		(*idEditorial) = this->idEditorial;
		retorno=0;
	}
	return retorno;
}

int editorial_setNombre(eEditorial *this, char nombre[])
{
	int retorno=1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		retorno=0;
	}
	return retorno;
}

int editorial_setIdEditorial(eEditorial *this,int idEditorial)
{
	int retorno=1;

	if(this!=NULL)
	{
		this->idEditorial = idEditorial;
		retorno=0;
	}
	return retorno;
}

eEditorial * editorial_newParametros(char * idEditorial, char *nombre )
{
	eEditorial * newEditorial;

		if((newEditorial=editorial_new())!=NULL)
		{
			if(nombre!=NULL && idEditorial!=NULL)
			{
				editorial_setIdEditorial(newEditorial,atoi(idEditorial));
				editorial_setNombre(newEditorial,nombre);
			}
		}
		return newEditorial;
}

eEditorial * editorial_new(void)
{
	eEditorial * newEditorial;

	newEditorial=(eEditorial*) malloc(sizeof(eEditorial));

	return newEditorial;
}
