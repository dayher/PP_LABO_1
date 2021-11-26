#include <stdlib.h>
#include <stdio.h>
#include "localidad.h"


int inicializarListaLocalidades(eLocalidad list[], int len)
{
    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
		list[i].isEmpty=1;
	}
    return 0;
}

int buscarLocalidadPorId(eLocalidad list[], int len, int id)
{
    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
		if(list[i].id==id && list[i].isEmpty==0) return i;
	}
    return -1;
}

int mostarLocalidades(eLocalidad lista [], int longitud)
{
    int contador=0;

    if(lista==NULL || longitud<1) return -1;

    for(int i=0 ; i<longitud ; i++){
        if(lista[i].isEmpty==0){
            printf("\t#%d\t%s\n",++contador,lista[i].nombre);
        }
    }
    return contador;
}

int ingresarLocalidad(eLocalidad lista [], int longitud)
{
    int contador=0;
    int opcion;
    int id;

    if(lista==NULL || longitud<1) return -1;

    contador = mostarLocalidades(lista, longitud);

    if(contador>0)
	{
		opcion = getInt("\nIngrese n�mero de localidad\t",1,contador);
	}

    for(int i=0 ; i<longitud ; i++){
        if(lista[i].isEmpty==0 && (--opcion)==0 ){
            id=lista[i].id;
            printf("Localidad ingresada: %s\n", lista[i].nombre);
            break;
        }
    }
    return id;
}
