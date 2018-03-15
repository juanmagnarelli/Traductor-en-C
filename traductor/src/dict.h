#ifndef _DICT_H
#define _DICT_H

#include <stdio.h>
#include <stdbool.h>

#include "word.h"
#include "list.h"

typedef char *expression_t;
typedef struct _dict_t *dict_t;


dict_t dict_empty(void);

//Crea y devuelve un diccionario Nuevo y vacio.

dict_t dict_destroy(dict_t dict);

//Libera los recursos del diccionario y lo setea en NULL

bool dict_exists(dict_t dict, expression_t expr);

//Devuelve true si una palabra se encuentra en el diccionario.

expression_t dict_search(dict_t dict, expression_t expr);

//Busca y devuelve una palabra alojada en el diccionario

dict_t dict_add(dict_t dict, expression_t expr1, expression_t expr2);

//Devuelve un diccionario con la palabra y su definicion agregadas

void dict_dump(dict_t dict, FILE * fd);

//Imprime el contenido del diccionario en un archivo

dict_t dict_revers(dict_t dict);

//Invierte el orden de las palabras en el diccionario, para traducir de ingles a español.

#endif
