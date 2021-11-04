/*
 * biblioteca.c
 *
 *  Created on: 1 sep. 2021
 *      Author: dayher
 */

#include "biblioteca.h"



double sumar(double primero, double segundo){
	double resultado;
	resultado = primero + segundo;
	return resultado;
}

double restar(double primero, double segundo){
	double resultado;
	resultado = primero - segundo;
	return resultado;
}

double multiplicar(double primero, double segundo){
	double resultado;
	resultado = primero * segundo;
	return resultado;
}
double dividir(double primero, double segundo){
	double resultado;
	resultado = primero / segundo;
	return resultado;
}
long long factorial(unsigned numero){

	long long resultado=1;
	unsigned contador=0;

	if(numero==0 || numero==1){
		return resultado;
	} else {
		for(contador=numero;contador>1;contador--){
			resultado*=contador;
		}
		return resultado;
	}
}
