#ifndef INPUT_H_
#define INPUT_H_

float getFloat(char mensaje[],float min , float max);

int getInt(char mensaje[],int min,int max);

int isFloat(char str[]);

int isInt(char str[]);

int esNumerico(char str[]);

int esSoloLetras(char str[]);

void getString(char mensaje[],char input[]);

int getStringLetras(char mensaje[],char input[]);

int getStringNumeros(char mensaje[],char input[]);

#endif /* INPUT_H_ */
