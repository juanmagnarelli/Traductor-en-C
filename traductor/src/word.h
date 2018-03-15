#ifndef _WORD_H
#define _WORD_H

#include <stdbool.h>


typedef struct _word_t *word_t; 

word_t word_from_string(char *s);

//Devuelve un nuevo word, desde el string s

word_t word_destroy(word_t w);

//Libera los recursos del word y le asigna NULL

char *word_to_string(word_t w);

//Devuelve un string desde el word w ingresado

bool word_is_equal(word_t w, word_t other);

//Devuelve true si dos word son iguales, sino devuelve false


#endif
