#include "cliente.h"

#include <stdio.h>

/**
 * \brief Inicializa lista de clientes con valor 1 en el campo isEmpty
 * \param lista de clientes
 * \param longitud de la lista
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int inicializarListaClientes(eCliente list[], int len)
{
	int retorno = -1;
    if(list!=NULL && len>0 ){
		for(int i=0; i<len; i++){
			list[i].isEmpty=1;
		}
    	retorno =0;
    }
    return retorno;
}

/**
 * \brief Guarda una estructura cliente en la lista recibida y setea los datos de dicha estructura con el resto de parametros
 * \param lista de clientes
 * \param longitud de la lista
 * \param id cliente
 * \param nombre cliente
 * \param cuit cliente
 * \param direccion cliente
 * \param localidad cliente
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int guardarCliente(eCliente list[], int len, int id, char nombre[], char cuit[], char direccion[], int localidad )
{
    if(list==NULL ||len<1 ) return -1;
	for(int i=0;i<len;i++){
		if(list[i].isEmpty){
			list[i].id = id;
			strcpy(list[i].nombre,nombre);
			strcpy(list[i].cuit,cuit);
			strcpy(list[i].direccion,direccion);
			list[i].localidad = localidad;
			list[i].isEmpty=0;
			return 0;
		}
	}
    return -1;
}

/**
 * \brief Solicita datos al usuario para dar de alta un nuevo cliente
 * \param lista de clientes
 * \param longitud de la lista de clientes
 * \param lista de localidades
 * \param longitud de la lista de localidades
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int ingresarCliente(eCliente list[], int len, int id, eLocalidad list2[], int len2)
{
    char cuit[MAX_CUIT];
	char nombre[MAX_CADENA];
	char direccion[MAX_CADENA];
	int localidad;
	int retorno = -1;

	if(list!=NULL &&len>0 && list2!=NULL && len2>0 ){

		while(!getStringNumeros("Ingrese CUIT sin guiones ni espacios: ", cuit));
		getString("Ingrese nombre: ", nombre);
		getString("Ingrese direccion: ", direccion);
		localidad = ingresarLocalidad(list2, len2);

		guardarCliente(list, len, id, nombre, cuit, direccion, localidad);
		printf("\nID cliente: %d\n",id);
		retorno =0;
	}

	return retorno;
}

/**
 * \brief Busca la posicion de un cliente dentro de la lista.
 * \param lista de clientes
 * \param longitud de la lista de clientes
 * \param id del cliente a buscar
 * \return índice de la lista en caso de exito -1 en caso de error
 *
 */
int buscarClientePorId(eCliente list[], int len, int id)
{
	int retorno = -1;

    if(list!=NULL && len>0 ) {
		for(int i=0; i<len; i++){
			if(list[i].id==id && list[i].isEmpty==0) return i;
		}
    	retorno =0;
    }
    return retorno;
}

/**
 * \brief  Se ingresa el ID del cliente. Luego se preguntará si se quiere confirmar la eliminación.
 * \param lista de clientes
 * \param longitud de la lista de clientes
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int eliminarCliente(eCliente list[], int len)
{
	int index, id;
	int confirmar=0;
	int retorno = -1;

	if(list!=NULL && len>0 ) {
		id = getInt("Ingrese id del cliente: ",0,MAX_ID);
		index = buscarClientePorId(list, len , id);

		if(index<0) return -1;

		printf("¿Desea dar de baja al cliente: %s?\n", list[index].nombre);

		if((confirmar = getInt("Ingrese 1 para confirmar, otro valor para cancelar",0,5))==1){
			list[index].isEmpty=1;
			return 0;
		}
		retorno=0;
	}

	return retorno;
}

/**
 * \brief  Se ingresa el ID de cliente y se permitirá cambiar la dirección y la localidad.
 * \param lista de clientes
 * \param longitud de la lista de clientes
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int modificarCliente(eCliente list[], int len, eLocalidad list2[], int len2)
{
    int id, index;
	char direccion[MAX_CADENA];
	int localidad;
	int retorno = -1;

	if(list!=NULL && len>0 && list2!=NULL && len2>0 )
	{
		id = getInt("Ingrese id del cliente: ",0,MAX_ID);
		index = buscarClientePorId(list, len, id);
		if(index>=0){

			getString("Ingrese direccion: ", direccion);
			localidad = ingresarLocalidad(list2, len2);
			list[index].localidad=localidad;

			strcpy(list[index].direccion,direccion);
			retorno=0;
		}
	}
	return retorno;
}
