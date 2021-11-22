#include "cliente.h"
#include <stdio.h>

/*
1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit dirección y localidad.
Se generará un ID único para este cliente que se imprimirá por pantalla si el alta es correcta.
*/
int inicializarListaClientes(eCliente list[], int len){
    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
		list[i].isEmpty=1;
	}
    return 0;
}
int guardarCliente(eCliente list[], int len, int id, char nombre[], char cuit[], char direccion[], char localidad[] ){
    if(list==NULL ||len<1 ) return -1;
	for(int i=0;i<len;i++){
		if(list[i].isEmpty){
			list[i].id= id;
			strcpy(list[i].nombre,nombre);
			strcpy(list[i].cuit,cuit);
			strcpy(list[i].direccion,direccion);
			strcpy(list[i].localidad,localidad);
			list[i].isEmpty=0;
			return 0;
		}
	}
    return -1;
}
int ingresarCliente(eCliente list[], int len, int id){
    char cuit[MAX_CUIT];
	char nombre[MAX_CADENA];
	char direccion[MAX_CADENA];
	char localidad[MAX_CADENA];

	if(list==NULL ||len<1 ) return -1;

	while(!getStringNumeros("Ingrese CUIT sin guiones ni espacios: ", cuit));
	getString("Ingrese nombre: ", nombre);
	getString("Ingrese direccion: ", direccion);
	while(!getStringLetras("Ingrese localidad: ", localidad));

	return guardarCliente(list, len, id, nombre, cuit, direccion, localidad);
}

/*
2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitirá cambiar la dirección y la localidad.
3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntará si se quiere confirmar la eliminación.
*/
int buscarClientePorId(eCliente list[], int len, int id){
    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
		if(list[i].id==id && list[i].isEmpty==0) return i;
	}
    return -1;
}
int eliminarCliente(eCliente list[], int len){
	int index, id;
	int confirmar=0;

	if(list==NULL ||len<1 ) return -1;

	id = getInt("Ingrese id del cliente: ",0,MAX_ID);
	index = buscarClientePorId(list, len , id);

	if(index<0) return -1;

	printf("¿Desea dar de baja al cliente: %s?\n", list[index].nombre);

	if((confirmar = getInt("Ingrese 1 para confirmar, otro valor para cancelar",0,5))==1){
    	list[index].isEmpty=1;
    	return 0;
	}
	return -1;
}
int modificarCliente(eCliente list[], int len){
    int id, index;
	char direccion[MAX_CADENA];
	char localidad [MAX_CADENA];

	if(list==NULL ||len<1 ) return -1;

	id = getInt("Ingrese id del cliente: ",0,MAX_ID);
	index = buscarClientePorId(list, len, id);
	if(index<0){
		return -1;
	} else {

    	getString("Ingrese direccion: ", direccion);
    	while(!getStringLetras("Ingrese localidad: ", localidad));

		strcpy(list[index].direccion,direccion);
		strcpy(list[index].localidad,localidad);
		return 0;
	}

	return -1;
}


