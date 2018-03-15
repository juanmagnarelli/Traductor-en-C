#ifndef _PAIR_H
#define _PAIR_H

#include <stdbool.h>
#include "word.h"


typedef struct _pair_t *pair_t;

pair_t pair_destroy(pair_t pair);

//libera los recursos del par y los setea en NULL

pair_t pair_from_ingl_esp(word_t first, word_t second);

//Crea y devuelve un par con la palabra y su traduccion

word_t pair_fst(pair_t pair);

//Devuelve el primer elemento del par

word_t pair_snd(pair_t pair);

//Devuelve el segundo elemento del par

bool pair_is_equal(pair_t pair, pair_t other);

//Devuelve true si dos pares son iguales

pair_t pair_revers(pair_t pair);

//Invierte el orden de los elementos del par para permitir la traduccion ingles español

#endif
