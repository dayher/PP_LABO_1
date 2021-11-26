#include "factura.h"
#include <stdio.h>

int inicializarListaFacturas(eFactura list[], int len)
{
	int retorno = -1;

    if(list!=NULL && len>0 )
    {
		for(int i=0; i<len; i++){
			list[i].isEmpty=1;
		}
		retorno = 0;
    }
	return retorno;
}

int guardarFactura(eFactura list[], int len, int id, int pedido, float importe)
{
	int retorno = -1;

    if(list!=NULL && len>0 )
    {
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty){
				list[i].id= id;
				list[i].pedido=pedido;
				list[i].importe=importe;
				list[i].isEmpty=0;
				retorno = 0;
				break;
			}
		}
    }
    return retorno;
}

int crearFactura(eFactura listaFacturas[], int nFacturas, int id, ePedido listaPedidos[], int nPedidos)
{
    float importe;
    int index;
    int pedido;
    int retorno = -1;

	if(listaPedidos!=NULL && nPedidos>0 && listaFacturas!=NULL && nFacturas>0 )
	{
		pedido = getInt("Ingrese id del pedido: ",0 ,MAX_ID);
		index = buscarPedidoPorId(listaPedidos, nPedidos , pedido);

		if(index>=0)
		{
			importe = (listaPedidos[index].cantidad)*PRECIOXKG;
			retorno = guardarFactura(listaFacturas, nFacturas, id, pedido ,importe);
		}
	}
	return retorno;
}

int buscarFacturaPorId(eFactura list[], int len, int id)
{
	int retorno = -1;

    if(list!=NULL && len>0 )
    {
		for(int i=0; i<len; i++)
		{
			if(list[i].id==id && list[i].isEmpty==0) {
				retorno=i;
				break;
			}
		}
    }
    return retorno;
}
