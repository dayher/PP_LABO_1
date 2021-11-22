#include "informe.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
6) Imprimir Clientes: Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos de recolección” que posee en estado “Pendiente”.
*/
int contarPendientesPorCliente(ePedido list[], int len, int cliente){
    int contador=0;
    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
        if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==PENDIENTE)
            contador++;
	}
    return contador;
}

int imprimirClientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes){
    for(int i=0; i<nClientes; i++){
        if(listaClientes[i].isEmpty==0){
            printf("%d, %s, %s, %s, %s, Pedidos pendientes: %d\n",listaClientes[i].id,listaClientes[i].nombre, listaClientes[i].cuit, listaClientes[i].direccion, listaClientes[i].localidad,
            contarPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id));
        }
    }
    return 0;
}
/*
7) Imprimir Pedidos pendientes: Se imprimirá una lista de los pedidos que se encuentren en estado “Pendiente” con la información:
Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
*/
int imprimirPendientesPorCliente(ePedido list[], int len, int cliente){

    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
        if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==PENDIENTE)
            printf("\t%d, %f\n", list[i].id, list[i].cantidad);
	}
    return 0;
}

int imprimirPendientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes){
    for(int i=0; i<nClientes; i++){
        if(listaClientes[i].isEmpty==0){
            printf("%s, %s\n", listaClientes[i].cuit, listaClientes[i].direccion);
            imprimirPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id);
        }
    }
    return 0;
}
/*
8) Imprimir Pedidos procesados: Se imprimirá una lista de los pedidos que se encuentren en estado “Completado” con la información:
Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo de plástico.
*/
int imprimirProcesadosPorCliente(ePedido list[], int len, int cliente){
    if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
        if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==COMPLETADO)
            printf("\t%d, HDPE: %f, LDPE: %f, PP: %f\n", list[i].id, list[i].tipo[HDPE],list[i].tipo[LDPE],list[i].tipo[PP]);
	}
    return 0;
}

int imprimirProcesados(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes){
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
int imprimirPendientesPorLocalidad(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes){
	char localidad[MAX_CADENA];
	int acumuladorPendientes=0;
	while(!getStringLetras("Ingrese localidad: ", localidad));
    for(int i=0; i<nClientes; i++){
        if(listaClientes[i].isEmpty==0 && !strcmp(listaClientes[i].localidad,localidad)){
            acumuladorPendientes+=contarPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id);
        }
    }
    printf("Pendientes: %d\n", acumuladorPendientes);
	return 0;
}
/*
10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
*/
int promediarPropileno(ePedido listaPedidos[], int nPedidos, int nClientes){
    double promedio=0, acumuladorPropileno=0;
    for(int i=0; i<nPedidos; i++){
        if(listaPedidos[i].isEmpty==0 && listaPedidos[i].estado==COMPLETADO){
            acumuladorPropileno+=listaPedidos[i].tipo[PP];
        }
    }
    promedio = acumuladorPropileno / nClientes;
    printf("Promedio de propileno: %.2lf (kg/cliente)",promedio);
    return promedio;
}


