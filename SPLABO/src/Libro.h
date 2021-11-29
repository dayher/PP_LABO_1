#ifndef LIBRO_H_
#define LIBRO_H_

#define MAX_CADENA 51
typedef struct {
    int id; //private key
    char titulo[MAX_CADENA];
    char autor[MAX_CADENA];
    float precio;
    int idEditorial; //foreign key
} eLibro;

int compararLibrosPorAutor(void* primero, void* segundo);
int libro_getId(eLibro *libro, int * id);
int libro_getAutor(eLibro *libro, char autor[]);
int libro_getTitulo(eLibro *libro,char titulo[]);
int libro_getPrecio(eLibro *libro, float *precio);
int libro_getIdEditorial(eLibro *libro,int * idEditorial);
int libro_setId(eLibro *libro, int id);
int libro_setAutor(eLibro *libro, char autor[]);
int libro_setTitulo(eLibro *libro,char titulo[]);
int libro_setPrecio(eLibro *libro, float precio);
int libro_setIdEditorial(eLibro *libro,int idEditorial);
eLibro * libro_newParametros(char *idStr, char *titulo, char *autor,char* precioStr, char* idEditorial);
eLibro * libro_new(void);

#endif /* LIBRO_H_ */
