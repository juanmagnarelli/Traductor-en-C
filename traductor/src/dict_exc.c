#include <assert.h>
#include <stdlib.h>

#include "dict_exc.h"


typedef char *expression_t;

struct _dict_exc_t {
    list_exc_t list_exc;
};

dict_exc_t dict_exc_empty(void) {
    dict_exc_t dict = NULL;

    dict = calloc(1, sizeof(struct _dict_exc_t));
    assert(dict != NULL);

   
    dict->list_exc = list_exc_empty();

    assert(dict != NULL);
    return (dict);
}


dict_exc_t dict_exc_destroy(dict_exc_t dict) {
    dict->list_exc = list_exc_destroy(dict->list_exc);
    free(dict);

    dict = NULL;
    return (dict);
}



bool dict_exc_exists(dict_exc_t dict, char *expr) {
    assert(dict != NULL && expr != NULL);

    bool result;
    word_t word  = NULL;

    word = word_from_string(expr);
    result = (list_exc_search(dict->list_exc, word));

    word = word_destroy(word);
    return (result);
}



dict_exc_t dict_exc_add(dict_exc_t dict, char *expr) {
    assert(dict != NULL && expr != NULL);
    word_t word = NULL;
    word = word_from_string(expr);
    dict->list_exc = list_exc_append(dict->list_exc, word);
    return dict;
}

void dict_exc_dump(dict_exc_t dict, FILE * fd) {
    assert(dict != NULL && fd != NULL);
    list_exc_dump(dict->list_exc, fd);
}

