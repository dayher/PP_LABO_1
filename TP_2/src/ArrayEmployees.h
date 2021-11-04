/*
 * ArrayEmployees.h
 *
 *  Created on: 18 sep. 2021
 *  Author: Dayher Marchan
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define MAX_SALARY 1000000
#define MAX_SECTOR 1000
#define MAX_ID 10000000
#endif /* ARRAYEMPLOYEES_H_ */

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int ingresarEmpleado(Employee* list, int len, int newId);
int modificarEmpleado(Employee* list, int len);
int eliminarEmpleado(Employee* list, int len);
int mostrarSalarioPromedio(Employee* list, int len);
int ordenarEmpleadosApellidoSector(Employee* list, int len);
