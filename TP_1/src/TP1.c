/*
 ============================================================================
 Name        : TP1.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : 
 Description : Calculadora básica
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {
	double primero, segundo;

	printf("Ingresar 1er operando A = ");
	scanf("%lf",&primero);
	printf("Ingresar 2do operando B = ");
	scanf("%lf",&segundo);

	printf("\nA = %f\t B = %f",primero,segundo);

	printf("\nEl resultado de A+B es: %lf",sumar(primero,segundo));
	printf("\nEl resultado de A-B es: %lf",restar(primero,segundo));
	printf("\nEl resultado de A*B es: %lf",multiplicar(primero,segundo));
	if (segundo){
		printf("\nEl resultado de A/B es: %lf",dividir(primero,segundo));
	} else {
		printf("\nNo es posible dividir por cero");
	}
	if(primero-(unsigned)primero || primero<0 || primero>15){
		printf("\nA No es un número natural entre 0 y 15");
	} else {
		printf("\nEl factorial de A es: %Ld",factorial((unsigned)primero));
	}
	if(segundo-(unsigned)segundo || segundo<0 || segundo>15){
		printf("\nB No es un número natural entre 0 y 15");
	} else {
		printf("\nEl factorial de B es: %Ld\n",factorial((unsigned)segundo));
	}

	return EXIT_SUCCESS;
}
