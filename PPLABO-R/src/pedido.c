#include "pedido.h"
#include <stdio.h>

int inicializarListaPedidos(ePedido list[], int len){
     if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
		list[i].isEmpty=1;
	}
    return 0;
}
int guardarPedido(ePedido list[], int len, int id, int cliente, float cantidad){
    if(list==NULL ||len<1 ) return -1;
	for(int i=0;i<len;i++){
		if(list[i].isEmpty){
			list[i].id= id;
			list[i].cliente=cliente;
			list[i].estado=PENDIENTE;
			list[i].cantidad=cantidad;
			list[i].isEmpty=0;
			return 0;
		}
	}
    return -1;
}
/*
4) Crear pedido de recolección: Se imprimirán los clientes por pantalla y se pedirá que se ingrese el ID de un cliente existente y la cantidad de kilos totales que se recolectarán del cliente.
Se generará un ID para el pedido y el mismo quedará en estado “Pendiente” hasta que se obtengan los residuos del cliente y se trasladen a la empresa.
*/
int crearPedido(ePedido listaPedidos[], int nPedidos, int id, eCliente listaClientes[], int nClientes){
    float cantidad;
    int index;
    int cliente;

	if(listaClientes==NULL ||nClientes<1 || listaPedidos==NULL || nPedidos<1 ) return -1;

	cliente = getInt("Ingrese id del cliente: ",0,MAX_ID);
	index = buscarClientePorId(listaClientes, nClientes , cliente);
	if(index<0)	return -1;

	cantidad= getFloat("Ingrese cantidad de kilos a recolectar: ",0,MAX_CANTIDAD);

	return guardarPedido(listaPedidos, nPedidos, id, cliente ,cantidad);
}
int buscarPedidoPorId(ePedido list[], int len, int id){

    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
        if(list[i].id==id && list[i].isEmpty==0) return i;
	}
    return -1;
}
/*
5) Procesar residuos: Se elegirá esta opción cuando los residuos que volvieron a la empresa se hayan procesado y separado en los diferentes tipos de plástico que la empresa puede reciclar.
Se imprimirán los pedidos por pantalla y se pedirá seleccionar el ID de uno de ellos.
Luego deberán ingresarse la cantidad de kilos de plástico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que se recolectaron.
Por último, se marcará al pedido como “Completado”.
*/
int procesarPedido(ePedido list[], int len){
	int index, id;
	if(list==NULL ||len<1 ) return -1;

	id = getInt("Ingrese id del pedido: ",0,MAX_ID);
	index = buscarPedidoPorId(list, len , id);
	if(index<0) return -1;
	list[index].tipo[HDPE] = getFloat("Ingrese kilos de HDPE: ",0,MAX_CANTIDAD);
	list[index].tipo[LDPE] = getFloat("Ingrese kilos de LDPE: ",0,MAX_CANTIDAD);
	list[index].tipo[PP] = getFloat("Ingrese kilos de PP: ",0,MAX_CANTIDAD);
	list[index].estado=COMPLETADO;
	return 0;
}
