#include "informe.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int imprimirClienteConMasPedidos(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes)
{
	eCliente aux;
	int max = 0;
	int cantidad;

	for(int i = 0; i<nClientes; i++){
		if(listaClientes[i].isEmpty == 0){
			cantidad = contarPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id) + contarProcesadosPorCliente(listaPedidos, nPedidos, listaClientes[i].id);
			if(cantidad>max){
				aux = listaClientes[i];
				max = cantidad;
			}
		}
	}
	printf("\nCliente con mayor cantidad de pedidos: %s, cantidad: %d\n", aux.nombre, max);

	return 0;
}

int imprimirClienteConMasPendientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes)
{
	eCliente aux;
	int max = 0;
	int cantidad;

	for(int i = 0; i<nClientes; i++){
		if(listaClientes[i].isEmpty == 0){
			cantidad = contarPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id);
			if(cantidad>max){
				aux = listaClientes[i];
				max = cantidad;
			}
		}
	}
	printf("\nCliente con mayor cantidad de pedidos pendientes: %s, cantidad: %d\n", aux.nombre, max);

	return 0;
}

int contarPendientesPorCliente(ePedido list[], int len, int cliente)
{
	int contador = 0;

    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
        if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==PENDIENTE){
        	contador++;
        }
	}

	return contador;
}

int imprimirClienteConMasProcesados(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes)
{
	eCliente aux;
	int max = 0;
	int cantidad;

	for(int i = 0; i<nClientes; i++)
	{
		if(listaClientes[i].isEmpty == 0)
		{
			cantidad = contarProcesadosPorCliente(listaPedidos, nPedidos, listaClientes[i].id);

			if(cantidad>max)
			{
				aux = listaClientes[i];
				max = cantidad;
			}
		}
	}
	printf("\nCliente con mayor cantidad de pedidos procesados: %s, cantidad: %d", aux.nombre, max);

	return 0;
}

int contarProcesadosPorCliente(ePedido list[], int len, int cliente)
{
	int contador = 0;

    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
        if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==COMPLETADO){
        	contador++;
        }
	}

	return contador;
}
/*
6) Imprimir Clientes: Se imprimir� una lista de clientes con todos sus datos junto con la cantidad de �pedidos de recolecci�n� que posee en estado �Pendiente�.
*/

int imprimirClientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes, eLocalidad listaLocalidades[], int nLocalidades)
{
	char * nombreLocalidad;

    for(int i=0; i<nClientes; i++){
        if(listaClientes[i].isEmpty==0)
        {
        	nombreLocalidad = listaLocalidades[buscarLocalidadPorId(listaLocalidades, nLocalidades, listaClientes[i].localidad)].nombre;

            printf("%d, %s, %s, %s, %s, Pedidos pendientes: %d\n",
            		listaClientes[i].id,listaClientes[i].nombre, listaClientes[i].cuit,
					listaClientes[i].direccion, nombreLocalidad,
					contarPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id)
					);
        }
    }
    return 0;
}
/*
7) Imprimir Pedidos pendientes: Se imprimir� una lista de los pedidos que se encuentren en estado �Pendiente� con la informaci�n:
Cuit del cliente, direcci�n del cliente, cantidad de kilos a recolectar.
*/
int imprimirPendientesPorCliente(ePedido list[], int len, int cliente)
{
    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
        if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==PENDIENTE)
            printf("\t%d, %f\n", list[i].id, list[i].cantidad);
	}
    return 0;
}

int imprimirPendientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes)
{
    for(int i=0; i<nClientes; i++){
        if(listaClientes[i].isEmpty==0){
            printf("%s, %s\n", listaClientes[i].cuit, listaClientes[i].direccion);
            imprimirPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id);
        }
    }
    return 0;
}

/*
8) Imprimir Pedidos procesados: Se imprimir� una lista de los pedidos que se encuentren en estado �Completado� con la informaci�n:
Cuit del cliente, direcci�n del cliente, cantidad de kilos reciclados de cada tipo de pl�stico.
*/
int imprimirProcesadosPorCliente(ePedido list[], int len, int cliente)
{
    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
        if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==COMPLETADO)
            printf("\t%d, HDPE: %f, LDPE: %f, PP: %f\n",
            		list[i].id, list[i].tipo[HDPE],list[i].tipo[LDPE],list[i].tipo[PP]);
	}
    return 0;
}

int imprimirProcesados(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes)
{
    for(int i=0; i<nClientes; i++){
        if(listaClientes[i].isEmpty==0){
            printf("%s,%s\n",listaClientes[i].cuit, listaClientes[i].direccion);
            imprimirProcesadosPorCliente(listaPedidos, nPedidos, listaClientes[i].id);
        }
    }
    return 0;
}
/*
9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
*/
int imprimirPendientesPorLocalidad(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes, eLocalidad listaLocalidades[], int nLocalidades)
{
	int localidad;
	int acumuladorPendientes=0;

	localidad = ingresarLocalidad(listaLocalidades, nLocalidades);
    for(int i=0; i<nClientes; i++){
        if(listaClientes[i].isEmpty==0 && listaClientes[i].localidad==localidad){
            acumuladorPendientes+=contarPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id);
        }
    }
    printf("Pendientes: %d\n", acumuladorPendientes);

	return 0;
}

/*
10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
*/
int promediarPropileno(ePedido listaPedidos[], int nPedidos, int nClientes)
{
    double promedio=0, acumuladorPropileno=0;

    for(int i=0; i<nPedidos; i++){
        if(listaPedidos[i].isEmpty==0 && listaPedidos[i].estado==COMPLETADO){
            acumuladorPropileno+=listaPedidos[i].tipo[PP];
        }
    }
    promedio = acumuladorPropileno / nClientes;
    printf("Promedio de propileno: %.2lf (kg/cliente)\n",promedio);

    return promedio;
}


