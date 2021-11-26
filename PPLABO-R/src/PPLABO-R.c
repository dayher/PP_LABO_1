/*
 ============================================================================
 Name        : PPLABO-R.c
 Author      : Dayher Marchan
 Version     :
 Copyright   :
 Description : Una empresa de recolección y reciclado de plásticos requiere un sistema que les permita administrar sus clientes y pedidos de recolección.
 ============================================================================
 */

#include <stdio.h>
#include "informe.h"

#define MAX_CLIENTE 100
#define MAX_PEDIDO 1000
#define MAX_LOCALIDAD 6
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
#define MAYOR_PENDIENTES 11
#define MAYOR_PROCESADOS 12
#define MAYOR_PEDIDOS 13
#define MAX_MENU 14
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
    eLocalidad listaLocalidades[MAX_LOCALIDAD] = {{10,"CABA",0},{11,"Jujuy",0},{12,"Mendoza",0},{13,"Avellaneda",1},{14,"Ituzaingo",1},{15,"Bariloche",0}};

    inicializarListaClientes(listaClientes, MAX_CLIENTE);
    inicializarListaPedidos(listaPedidos, MAX_PEDIDO);
   /* inicializarListaLocalidades(listaLocalidades, MAX_LOCALIDAD);*/

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
				"%d) CLIENTE CON MAS PEDIDOS PENDIENTES\n"
				"%d) CLIENTE CON MAS PEDIDOS PROCESADOS\n"
				"%d) CLIENTE CON MAS PEDIDOS \n"
				"%d) SALIR\n",
				ALTA, BAJA, MODIFICACION, PEDIDO, PROCESAR, CLIENTES, PENDIENTES, PROCESADOS, LOCALIDAD, PROPILENO, MAYOR_PENDIENTES, MAYOR_PROCESADOS, MAYOR_PEDIDOS, SALIR);

		opcion = getInt("\nIngrese una opción:\t",SALIR,MAX_MENU);

		switch(opcion){
		case ALTA:
			if(!ingresarCliente(listaClientes,MAX_CLIENTE,idCliente, listaLocalidades, MAX_LOCALIDAD)){
				idCliente++;
				altaClientes++;
				printf("\nAlta exitosa\n");
			} else {
				printf("No hay espacios disponibles\n");
			}
			break;
		case BAJA:
			if(altaClientes==0){
				printf("\nNo hay Altas en el sistema\n");
			} else {
				if(eliminarCliente(listaClientes,MAX_CLIENTE)){
					printf("No existe ningún cliente con el id ingresado\n");
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
				if(modificarCliente(listaClientes,MAX_CLIENTE, listaLocalidades, MAX_LOCALIDAD)){
					printf("No existe ningún cliente con el id ingresado\n");
				} else {
					printf("\nModificacion exitosa\n");
				}
			}
			break;
		case PEDIDO:
			if(altaClientes==0){
				printf("\nNo hay Altas en el sistema\n");
			} else {
				imprimirClientes(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE, listaLocalidades, MAX_LOCALIDAD);
				if(!crearPedido(listaPedidos, MAX_PEDIDO, idPedido, listaClientes, MAX_CLIENTE)){
    				pedidosPendientes++;
    				idPedido++;
    				printf("\nSe creó el pedido\n");
				} else {
				    printf("\nNo se creó el pedido\n");
				}
			}
			break;
		case PROCESAR:
			if(altaClientes==0 || pedidosPendientes==0){
				printf("\nNo hay Altas en el sistema o no hay pedidos pendientes\n");
			} else {
				imprimirPendientes(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE);
			    if(!procesarPedido(listaPedidos, MAX_PEDIDO)){
    				pedidosProcesados++;
    				pedidosPendientes--;
    				printf("\nSe procesó el pedido\n");
			    } else {
			        printf("\nNo se procesó el pedido\n");
			    }
			}
			break;

		case CLIENTES:
			if(altaClientes==0){
				printf("\nNo hay Altas en el sistema\n");
			} else {
				imprimirClientes(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE, listaLocalidades, MAX_LOCALIDAD);
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
				imprimirPendientesPorLocalidad(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE, listaLocalidades, MAX_LOCALIDAD);
			}
			break;
		case PROPILENO:
			if(altaClientes==0|| pedidosProcesados==0){
				printf("\nNo hay altas en el sistema o no se han procesado pedidos\n");
			} else {
				promediarPropileno(listaPedidos, MAX_PEDIDO, altaClientes);
			}
			break;
		case MAYOR_PENDIENTES:
			if(altaClientes==0|| pedidosPendientes==0){
				printf("\nNo hay altas en el sistema o no hay pedidos pendientes\n");
			} else {
				imprimirClienteConMasPendientes(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE);
			}
			break;
		case MAYOR_PROCESADOS:
			if(altaClientes==0|| pedidosProcesados==0){
				printf("\nNo hay altas en el sistema o no hay pedidos procesados\n");
			} else {
				imprimirClienteConMasProcesados(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE);
			}
			break;
		case MAYOR_PEDIDOS:
			if(altaClientes==0|| (pedidosPendientes==0 && pedidosProcesados==0)){
				printf("\nNo hay altas en el sistema o no hay pedidos\n");
			} else {
				imprimirClienteConMasPedidos(listaPedidos, MAX_PEDIDO, listaClientes,MAX_CLIENTE);
			}
			break;
		case SALIR:
			printf("\nFIN\n\n");
			break;
		default:
			printf("\nOpción inválida\n");
			break;
		}
	}
    return 0;
}
