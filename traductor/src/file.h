#ifndef _FILE_H
#define _FILE_H

#include "dict_exc.h"
#include "list.h"
#include "word.h"
#include "dict.h"

dict_t dict_from_file(char *filename);

//Devuelve un diccionario creado a partir de un archivo


char *readline_from_stdin(void);

char *readline(FILE * file);

//Lee linea por linea el archivo ingresado

dict_exc_t dict_exc_from_file(char *filename);

//Crea el diccionario de excluidos a partir de un archivo

#endif
