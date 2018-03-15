#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdbool.h>
#include "word.h"


typedef struct _node2_t  *list_exc_t;

list_exc_t list_exc_empty(void);

//Crea y devuelve una lista vacia

list_exc_t list_exc_destroy(list_exc_t list);

//Libera los recursos de la lista y la setea a NULL

bool list_exc_search(list_exc_t list, word_t word);

//Devuelve verdadero si word esta en la lista

list_exc_t list_exc_append(list_exc_t list, word_t word);

//Devuelve la lista con word agregado a ella

void list_exc_dump(list_exc_t list, FILE * fd);

//Vuelca el contenido de la lista en un archivo

#endif
