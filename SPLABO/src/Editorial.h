#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#define MAX_NOMBRE 51
typedef struct {
    int idEditorial; //private key
    char nombre[MAX_NOMBRE];
} eEditorial;

int editorial_getNombre(eEditorial *editorial, char nombre[]);

int editorial_getIdEditorial(eEditorial *editorial,int * idEditorial);

int editorial_setNombre(eEditorial *editorial, char nombre[]);

int editorial_setIdEditorial(eEditorial *editorial,int idEditorial);

eEditorial * editorial_newParametros(char * idEditorial, char *nombre );

eEditorial * editorial_new(void);

#endif /* EDITORIAL_H_ */
