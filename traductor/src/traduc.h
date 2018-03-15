#ifndef _TRADUC_H
#define _TRADUC_H

#include "dict.h"
#include "dict_exc.h"
#include "word.h"

FILE *open(char *name_file);

//Abre un archivo para leer y escribir

int close_file(FILE *file);

//Cierra un archivo

int search_word(char *name_w, dict_t dict, dict_t dict_aux, dict_exc_t dict_exc,char *name_r);

//Busca la palabra en los diccionarios, y escribe los signos  en el archivo de salida

int translation(char *chain, dict_t dict,dict_t dict_aux, dict_exc_t dict_exc, FILE *file_r);

/* Se fija si la palabra  esta en el diccionario o en lista de ignorados si no
llama a menu para que decidamos que hacer con la palabra */

char *menu(dict_exc_t dict_exc, dict_t dict, dict_t dict_aux, char *chain);

//Menu de opciones para cuando una palabra no se encuentra en ningun diccionario

bool symbols(char c);

//Detecta una serie de simbolos y nuemeros

#endif
