#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "word.h"

#define WORD_MAX_LENGTH 20


struct _word_t {
    char *term;
    unsigned int length;
};


word_t word_from_string(char *s) {
    word_t result = NULL;
    assert(s != NULL);

    result = calloc(1, sizeof(struct _word_t));
    assert(result != NULL);

    result->length = strlen(s);
    result->term = calloc(result->length + 1, sizeof(char));
    assert(result->term != NULL);

    strncpy(result->term, s, result->length + 1);
    result->term[result->length] = '\0';
    return (result);
}

word_t word_destroy(word_t w) {
    if (w != NULL) {
        free(w->term);
    }
    free(w);
    w = NULL;
    return (w);
}

char *word_to_string(word_t w) {
    char *result = NULL;

    assert(w != NULL);

    result = calloc(w->length + 1, sizeof(char));
    assert(result != NULL);

    strncpy(result, w->term, w->length + 1);

    return (result);
}

bool word_is_equal(word_t w, word_t other) {
    return (strncmp(w->term, other->term, WORD_MAX_LENGTH) == 0);
}
