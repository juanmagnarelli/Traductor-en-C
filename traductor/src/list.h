#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdbool.h>
#include "word.h"
#include "pair.h"

typedef struct _node_t  *list_t;


list_t list_empty(void);

//Crea y devuelve una lista vacia

list_t list_destroy(list_t list);

//Libera los recursos de la lista y la setea a NULL

word_t list_search(list_t list, word_t word);

//Devuelve la traduccion asociada a la palabra word

list_t list_append(list_t list, word_t first, word_t second);

//Devuelve la lista con la palabra y la traduccion agregadas.

void list_dump(list_t list, FILE * fd);

//Vuelca el contenido de la lista en un archivo de texto.

list_t list_revers(list_t list);

//Invierte el orden de los elementos de la lista para permitir la traduccion ingles español



#endif
