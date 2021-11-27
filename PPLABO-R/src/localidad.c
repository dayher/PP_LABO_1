#include <stdlib.h>
#include <stdio.h>
#include "localidad.h"

/**
 * \brief Inicializa lista de localidades con valor 1 en el campo isEmpty
 * \param lista de localidades
 * \param longitud de la lista
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int inicializarListaLocalidades(eLocalidad list[], int len)
{
	int retorno=-1;

    if(list!=NULL && len>0 )
    {
		for(int i=0; i<len; i++){
			list[i].isEmpty=1;
		}
    	retorno=0;
    }
    return retorno;
}

/**
 * \brief Busca la posicion de una localidad en la lista
 * \param lista de localidades
 * \param longitud de la lista
 * \param id de la localidad buscada
 * \return indice de la lista en caso de exito -1 en caso de error
 *
 */
int buscarLocalidadPorId(eLocalidad list[], int len, int id)
{
	int retorno =-1;

    if(list!=NULL && len>0 )
    {
		for(int i=0; i<len; i++){
			if(list[i].id==id && list[i].isEmpty==0) {
				retorno=i;
				break;
			}
		}
    }
    return retorno;
}

/**
 * \brief Imprime las localidades disponibles
 * \param lista de localidades
 * \param longitud de la lista
 * \return cantidad de localidades mostradas en caso de exito -1 en caso de error
 *
 */
int mostarLocalidades(eLocalidad lista [], int longitud)
{
    int contador=0;
    int retorno=-1;

    if(lista!=NULL && longitud>0)
    {
		for(int i=0 ; i<longitud ; i++){
			if(lista[i].isEmpty==0){
				printf("\t#%d\t%s\n",++contador,lista[i].nombre);
			}
		}
		retorno=contador;
    }

    return retorno;
}

/**
 * \brief Pide al usuario ingresar un numero correspondiente a la lista de localidades disponibles
 * \param lista de localidades
 * \param longitud de la lista
 * \return id de la localidad en caso de exito -1 en caso de error
 *
 */
int ingresarLocalidad(eLocalidad lista [], int longitud)
{
    int contador=0;
    int opcion;
    int id;
    int retorno = -1;

    if(lista!=NULL || longitud>0)
    {
		contador = mostarLocalidades(lista, longitud);

		if(contador>0)
		{
			opcion = getInt("\nIngrese número de localidad\t",1,contador);
		}

		for(int i=0 ; i<longitud ; i++){
			if(lista[i].isEmpty==0 && (--opcion)==0 ){
				id=lista[i].id;
				printf("Localidad ingresada: %s\n", lista[i].nombre);
				break;
			}
		}
    	retorno=id;
    }

    return retorno;
}
