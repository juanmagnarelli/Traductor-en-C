#ifndef _DICT_EXC_H
#define _DICT_EXC_H

#include <stdio.h>
#include <stdbool.h>

#include "list_exc.h"
#include "word.h"

typedef struct _dict_exc_t *dict_exc_t;


dict_exc_t dict_exc_empty(void);

//Crea y devuelve un diccionario Nuevo y vacio.

dict_exc_t dict_exc_destroy(dict_exc_t dict);

//Libera los recursos del diccionario y lo setea en NULL

bool dict_exc_exists(dict_exc_t dict, char *expr);

//Devuelve verdadero si una palabra se encuentra en el diccionario

dict_exc_t dict_exc_add(dict_exc_t dict, char *expr);

//Devuelve un diccionario con la palabra expr agregada

void dict_exc_dump(dict_exc_t dict, FILE * fd);

//Vuelca el contenido del diccionario en un archivo de texto

#endif
