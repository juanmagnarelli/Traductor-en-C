#include <assert.h>
#include <stdlib.h>

#include "pair.h"

struct _pair_t {
    word_t first;
    word_t second;
};

pair_t pair_destroy(pair_t pair) {
    pair->first = word_destroy(pair->first);
    pair->second = word_destroy(pair->second);

    free(pair);
    pair = NULL;
    return (pair);
}

pair_t pair_from_ingl_esp(word_t first, word_t second) {
    assert(first != NULL && second != NULL);

    pair_t pair = NULL;

    pair = calloc(1, sizeof(struct _pair_t));
    assert(pair != NULL);

    pair->first = first;
    pair->second = second;

    assert(pair != NULL && word_is_equal(pair->first, first) &&
           word_is_equal(pair->second, second));
    return (pair);
}



word_t pair_fst(pair_t pair) {
    assert(pair != NULL);

    assert(pair->first != NULL);
    return (pair->first);
}

word_t pair_snd(pair_t pair) {
    assert(pair != NULL);

    assert(pair->second != NULL);
    return (pair->second);
}

bool pair_is_equal(pair_t pair, pair_t other) {
    assert(pair != NULL && other != NULL);

    return (word_is_equal(pair->first, other->first) &&
            word_is_equal(pair->second, other->second));
}
pair_t pair_revers(pair_t pair){
  word_t aux;
  aux = pair->first;
  pair->first = pair->second;
  pair->second = aux;

  return(pair);

}
