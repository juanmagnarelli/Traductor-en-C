#include <assert.h>
#include <stdlib.h>

#include "dict.h"

struct _dict_t {
    list_t list;
};

dict_t dict_empty(void) {
    dict_t dict = NULL;

    dict = calloc(1, sizeof(struct _dict_t));
    assert(dict != NULL);

    dict->list = list_empty();

    assert(dict != NULL);
    return (dict);
}


dict_t dict_destroy(dict_t dict) {
    dict->list = list_destroy(dict->list);
    free(dict);

    dict = NULL;
    return (dict);
}


bool dict_exists(dict_t dict, expression_t expr) {
    assert(dict != NULL && expr != NULL);

    bool result;
    word_t word  = NULL;

    word = word_from_string(expr);
    result = (list_search(dict->list, word) != NULL);

    word = word_destroy(word);
    return (result);
}

expression_t dict_search(dict_t dict, expression_t expr) {
    assert(dict != NULL && expr != NULL && dict_exists(dict, expr));

    word_t first = NULL;
    word_t second = NULL;
    expression_t expr1 = NULL;

    first = word_from_string(expr);
    second = list_search(dict->list, first);
    expr1 = word_to_string(second);

    first = word_destroy(first);

    assert(expr1 != NULL);
    return (expr1);
}

dict_t dict_add(dict_t dict, expression_t expr1, expression_t expr2) {
    assert(dict != NULL && expr1 != NULL &&  expr2 != NULL);
    word_t first = NULL;
    word_t second = NULL;
    first = word_from_string(expr1);
    second = word_from_string(expr2);
    dict->list = list_append(dict->list, first, second);
    return (dict);
}


void dict_dump(dict_t dict, FILE * fd) {
    assert(dict != NULL && fd != NULL);
    list_dump(dict->list, fd);
}

dict_t dict_revers(dict_t dict){
    dict->list = list_revers(dict->list);
    return dict;
}
