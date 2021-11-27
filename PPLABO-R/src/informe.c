#include "informe.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * \brief Imprime el cliente con mas pedidos pendientes y completados.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param lista de clientes
 * \param longitud de la lista de clientes
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int imprimirClienteConMasPedidos(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes)
{
	eCliente aux;
	int max = 0;
	int cantidad;
	int retorno =-1;

	if(listaPedidos!=NULL && listaClientes!=NULL && nPedidos>0 && nClientes>0)
	{
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
		retorno =0;
	}
	return retorno;
}

/**
 * \brief Imprime el cliente con mas pedidos pendientes.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param lista de clientes
 * \param longitud de la lista de clientes
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int imprimirClienteConMasPendientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes)
{
	eCliente aux;
	int max = 0;
	int cantidad;
	int retorno =-1;

	if(listaPedidos!=NULL && listaClientes!=NULL && nPedidos>0 && nClientes>0)
	{
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
		retorno =0;
	}
	return retorno;
}

/**
 * \brief Cuenta los pedidos pendientes de un cliente recibido como parametro.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param id del cliente
 * \return cantidad de pedidos en caso de exito -1 en caso de error
 *
 */
int contarPendientesPorCliente(ePedido list[], int len, int cliente)
{
	int contador = 0;
	int retorno =-1;

    if(list!=NULL && len>0 ){
		for(int i=0; i<len; i++){
			if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==PENDIENTE){
				contador++;
			}
		}
		retorno=contador;
    }
	return retorno;
}

/**
 * \brief Imprime el cliente con mas pedidos completados.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param lista de clientes
 * \param longitud de la lista de clientes
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int imprimirClienteConMasProcesados(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes)
{
	eCliente aux;
	int max = 0;
	int cantidad;
	int retorno =-1;

	if(listaPedidos!=NULL && listaClientes!=NULL && nPedidos>0 && nClientes>0)
	{
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
		printf("\nCliente con mayor cantidad de pedidos procesados: %s, cantidad: %d\n", aux.nombre, max);
		retorno=0;
	}
	return retorno;
}

/**
 * \brief Cuenta los pedidos completados de un cliente recibido como parametro.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param id del cliente
 * \return cantidad de pedidos en caso de exito -1 en caso de error
 *
 */
int contarProcesadosPorCliente(ePedido list[], int len, int cliente)
{
	int contador = 0;
	int retorno =-1;

    if(list!=NULL && len>0 ){
		for(int i=0; i<len; i++){
	        if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==COMPLETADO){
	        	contador++;
	        }
		}
		retorno=contador;
    }
	return retorno;
}

/**
 * \brief Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos de recolección” que posee en estado “Pendiente”.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
  * \param lista de clientes
 * \param longitud de la lista de clientes
 * \param lista de localidades
 * \param longitud de la lista de localidades
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int imprimirClientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes, eLocalidad listaLocalidades[], int nLocalidades)
{
	char * nombreLocalidad;
	int retorno=-1;

	if(listaPedidos!=NULL && listaClientes!=NULL && listaLocalidades!=NULL && nPedidos>0 && nClientes>0 && nLocalidades>0)
	{
		for(int i=0; i<nClientes; i++){
			if(listaClientes[i].isEmpty==0)
			{
				nombreLocalidad = listaLocalidades[buscarLocalidadPorId(listaLocalidades, nLocalidades, listaClientes[i].localidad)].nombre;

				printf("\n%d, %s, %s, %s, %s, Pedidos pendientes: %d\n",
						listaClientes[i].id,listaClientes[i].nombre, listaClientes[i].cuit,
						listaClientes[i].direccion, nombreLocalidad,
						contarPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id)
						);
			}
		}
		retorno=0;
	}

    return retorno;
}


int imprimirPendientesPorCliente(ePedido list[], int len, int cliente)
{
	int retorno=-1;

    if(list!=NULL && len>0 ){
		for(int i=0; i<len; i++){
			if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==PENDIENTE)
				printf("\t%d, %f\n", list[i].id, list[i].cantidad);
		}
    	retorno=0;
    }
    return retorno;
}

/**
 * \brief  Se imprimirá una lista de los pedidos que se encuentren en estado “Pendiente” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param lista de clientes
 * \param longitud de la lista de clientes
 * \return 0 de exito -1 en caso de error
 *
 */
int imprimirPendientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes)
{
	int retorno = -1;

	if(listaPedidos!=NULL && listaClientes!=NULL && nPedidos>0 && nClientes>0)
	{
		for(int i=0; i<nClientes; i++)
		{
			if(listaClientes[i].isEmpty==0){
				printf("%s, %s\n", listaClientes[i].cuit, listaClientes[i].direccion);
				imprimirPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id);
			}
		}
		retorno=0;
	}
    return retorno;
}


int imprimirProcesadosPorCliente(ePedido list[], int len, int cliente)
{
	int retorno=-1;

    if(list!=NULL && len>0 ){
    	for(int i=0; i<len; i++){
    	        if(list[i].cliente==cliente && list[i].isEmpty==0 && list[i].estado==COMPLETADO)
    	        {
    	            printf("\t%d, HDPE: %f, LDPE: %f, PP: %f\n",
    	            		list[i].id, list[i].tipo[HDPE],list[i].tipo[LDPE],list[i].tipo[PP]);
    	        }
    	}
    	retorno=0;
    }
    return retorno;
}

/**
 * \brief  Se imprimirá una lista de los pedidos que se encuentren en estado “Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo de plástico.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param lista de clientes
 * \param longitud de la lista de clientes
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int imprimirProcesados(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes)
{
	int retorno = -1;

	if(listaPedidos!=NULL && listaClientes!=NULL && nPedidos>0 && nClientes>0)
	{
		for(int i=0; i<nClientes; i++)
		{
		        if(listaClientes[i].isEmpty==0){
		            printf("%s,%s\n",listaClientes[i].cuit, listaClientes[i].direccion);
		            imprimirProcesadosPorCliente(listaPedidos, nPedidos, listaClientes[i].id);
		        }
		}
		retorno=0;
	}
    return retorno;
}

/**
 * \brief Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
  * \param lista de clientes
 * \param longitud de la lista de clientes
 * \param lista de localidades
 * \param longitud de la lista de localidades
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int imprimirPendientesPorLocalidad(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes, eLocalidad listaLocalidades[], int nLocalidades)
{
	int localidad;
	int acumuladorPendientes=0;
	int retorno=-1;

	if(listaPedidos!=NULL && listaClientes!=NULL && listaLocalidades!=NULL && nPedidos>0 && nClientes>0 && nLocalidades>0)
	{
		localidad = ingresarLocalidad(listaLocalidades, nLocalidades);
		for(int i=0; i<nClientes; i++){
			if(listaClientes[i].isEmpty==0 && listaClientes[i].localidad==localidad){
				acumuladorPendientes+=contarPendientesPorCliente(listaPedidos, nPedidos, listaClientes[i].id);
			}
		}
		printf("Pendientes: %d\n", acumuladorPendientes);
		retorno=0;
	}
	return retorno;
}


/**
 * \brief  Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param longitud de la lista de clientes
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int promediarPropileno(ePedido listaPedidos[], int nPedidos, int nClientes)
{
    double promedio=0, acumuladorPropileno=0;
    int retorno=-1;

    if(listaPedidos!=NULL && nPedidos>0)
    {
		for(int i=0; i<nPedidos; i++){
			if(listaPedidos[i].isEmpty==0 && listaPedidos[i].estado==COMPLETADO){
				acumuladorPropileno+=listaPedidos[i].tipo[PP];
			}
		}
		promedio = acumuladorPropileno / nClientes;
		printf("Promedio de propileno: %.2lf (kg/cliente)\n",promedio);
		retorno=0;
    }
    return retorno;
}

/**
 * \brief Imprime la localidad con el mayor importe acumulado en facturas.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
  * \param lista de clientes
 * \param longitud de la lista de clientes
 * \param lista de localidades
 * \param longitud de la lista de localidades
  * \param lista de facturas
 * \param longitud de la lista de facturas
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int imprimirLocalidadConMayorImporte(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes,
									eLocalidad listaLocalidades[], int nLocalidades, eFactura listaFacturas[], int nFacturas)
{
	int retorno = -1;
	int cliente, localidad;
	int index;
	float importe, max=0, acumulador=0;
	eLocalidad localidadMayorImporte;
	eFactura factura;

	if(		listaPedidos!=NULL && listaClientes!=NULL &&
			listaLocalidades!=NULL && listaFacturas!=NULL &&
			nPedidos>0 && nClientes>0 && nLocalidades>0 && nFacturas>0)
	{
		for(int j=0; j<nLocalidades; j++)
		{
			for(int i=0; i<nFacturas; i++)
			{
				factura=listaFacturas[i];

				if(factura.isEmpty==0)
				{
					if((index=buscarPedidoPorId(listaPedidos,nPedidos,factura.pedido))>=0)
					{
						cliente = listaPedidos[index].cliente;

						if((index=buscarClientePorId(listaClientes,nClientes, cliente))>=0)
						{
							localidad = listaClientes[index].localidad;

							if(localidad==listaLocalidades[j].id)
							{
								importe=factura.importe;
								acumulador+=importe;
							}
						}
					}
				}
			}
			if(acumulador>max){
				localidadMayorImporte = listaLocalidades[j];
				max=acumulador;
			}
		}
		printf("La localidad con mayor importe (%f) en facturas es: %s\n",max, localidadMayorImporte.nombre);
		retorno=0;
	}

	return retorno;
}
