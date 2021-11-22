/*
 ============================================================================
 Name        : PPLABO-R.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : Your copyright notice
 Description : Una empresa de recolecci�n y reciclado de pl�sticos requiere un sistema que les permita administrar sus clientes y pedidos de recolecci�n.
 ============================================================================
 */

#include <stdio.h>
#include "informe.h"

#define MAX_CLIENTE 100
#define MAX_PEDIDO 1000
#define ALTA 1
#define BAJA 2
#define MODIFICACION 3
#define PEDIDO 4
#define PROCESAR 5
#define CLIENTES 6
#define PENDIENTES 7
#define PROCESADOS 8
#define LOCALIDAD 9
#define PROPILENO 10
#define MAX_MENU 11
#define SALIR 0

int main()
{
    int opcion=MAX_MENU;
    int idCliente = 100;
    int idPedido = 1000;
    int pedidosPendientes = 0;
    int pedidosProcesados = 0;
    int altaClientes = 0;
    eCliente listaClientes[MAX_CLIENTE];
    ePedido listaPedidos[MAX_PEDIDO];

    inicializarListaClientes(listaClientes, MAX_CLIENTE);
    inicializarListaPedidos(listaPedidos, MAX_PEDIDO);

    while(opcion!=SALIR){
		printf("\n"
				"%d) ALTA\n"
				"%d) BAJA\n"
				"%d) MODIFICACION\n"
				"%d) PEDIDO\n"
				"%d) PROCESAR\n"
				"%d) CLIENTES\n"
				"%d) PENDIENTES\n"
				"%d) PROCESADOS\n"
				"%d) LOCALIDAD\n"
				"%d) PROPILENO\n"
				"%d) SALIR\n",
				ALTA, BAJA, MODIFICACION, PEDIDO, PROCESAR, CLIENTES, PENDIENTES, PROCESADOS, LOCALIDAD, PROPILENO, SALIR);

		opcion = getInt("\nIngrese una opci�n:\t",SALIR,MAX_MENU);

		switch(opcion){
		case ALTA:
			if(!ingresarCliente(listaClientes,MAX_CLIENTE,idCliente)){
				idCliente++;
				printf("\nAlta exitosa\n");
				altaClientes++;
			} else {
				printf("No hay espacios disponibles\n");
			}
			break;
		case BAJA:
			if(altaClientes==0){
				printf("\nNo hay Altas en el sistema\n");
			} else {
				if(eliminarCliente(listaClientes,MAX_CLIENTE)){
					printf("No existe ning�n cliente con el id ingresado\n");
				} else {
					printf("\nBaja exitosa\n");
					altaClientes--;
				}
			}
			break;
		case MODIFICACION:
			if(altaClientes==0){
				printf("\nNo hay Altas en el sistema\n");
			} else {
				if(modificarCliente(listaClientes,MAX_CLIENTE)){
					printf("No existe ning�n cliente con el id ingresado\n");
				} else {
					printf("\nModificacion exitosa\n");
				}
			}
			break;
		case PEDIDO:
			if(altaClientes==0){
				printf("\nNo hay Altas en el sistema\n");
			} else {
				if(!crearPedido(listaPedidos, MAX_PEDIDO, idPedido, listaClientes, MAX_CLIENTE)){ // validar que haya espacio suficiente y sumar a idPedido
    				pedidosPendientes++;
    				idPedido++;
    				printf("\nSe cre� el pedido\n");
				} else {
				    printf("\nNo se cre� el pedido\n");
				}
			}
			break;
		case PROCESAR:
			if(altaClientes==0 || pedidosPendientes==0){
				printf("\nNo hay Altas en el sistema\n");
			} else {
			    if(!procesarPedido(listaPedidos, MAX_PEDIDO)){
    				pedidosProcesados++;
    				pedidosPendientes--;
    				printf("\nSe proces� el pedido\n");
			    } else {
			        printf("\nNo se proces� el pedido\n");
			    }
			}
			break;

		case CLIENTES:
			if(altaClientes==0){
				printf("\nNo hay Altas en el sistema\n");
			} else {
				imprimirClientes(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE);
			}
			break;
		case PENDIENTES:
			if(altaClientes==0|| pedidosPendientes==0){
				printf("\nNo hay altas en el sistema o no hay pedidos pendientes\n");
			} else {
				imprimirPendientes(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE);
			}
			break;
		case PROCESADOS:
			if(altaClientes==0 || pedidosProcesados==0){
				printf("\nNo hay altas en el sistema o no se han procesado pedidos\n");
			} else {
				imprimirProcesados(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE);
			}
			break;
		case LOCALIDAD:
			if(altaClientes==0|| pedidosPendientes==0){
				printf("\nNo hay altas en el sistema o no hay pedidos pendientes\n");
			} else {
				imprimirPendientesPorLocalidad(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE);
			}
			break;
		case PROPILENO:
			if(altaClientes==0|| pedidosProcesados==0){
				printf("\nNo hay altas en el sistema o no se han procesado pedidos\n");
			} else {
				promediarPropileno(listaPedidos, MAX_PEDIDO, altaClientes);
			}
			break;
		case SALIR:
			printf("\nFIN\n\n");
			break;
		default:
			printf("\nOpci�n inv�lida\n");
			break;
		}
	}
    return 0;
}