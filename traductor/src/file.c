#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"


#define BUFFER_SIZE 128


dict_t dict_from_file(char *filename) {
    expression_t expr1= NULL;
    expression_t expr2 = NULL;
    dict_t result = NULL;
    FILE *fd = NULL;
    char *line = NULL;

    fd = fopen(filename, "r+");

    if (fd != NULL) {
        /* filename is a existing file, so create the empty dict */
        result = dict_empty();
        while (!feof(fd)) {
            line = readline(fd);
            if (line == NULL) {
                /* this is the case of the last (empty) line */
                continue;
            }
            expr1 = strtok(line, ",");
            if (expr1 != NULL) {
                expr2 = strtok(NULL, "\n");
                if (expr2 != NULL) {
                    /* remove extra initial spaces, if any */
                    while (expr2[0] == ' ') {
                        expr2 = expr2 + 1;
                    }
                    result = dict_add(result, expr1, expr2);
                }
            }
            free(line);
        }
        fclose(fd);
    }

    return (result);
}


void dict_to_file(dict_t dict, char *filename) {
    FILE *fd = NULL;

    fd = fopen(filename, "w");
    if (fd != NULL) {
        printf("Dumping dict to filename %s.\n", filename);
        dict_dump(dict, fd);
        fclose(fd);
    } else {
        printf("Can not dump dict to filename %s.\n", filename);
    }
}


char *readline(FILE * file) {
    bool done = false;
    char *result = NULL, *read_from = NULL;
    char *alloc_result = NULL, *fgets_result = NULL;
    unsigned int size = BUFFER_SIZE;
    size_t result_len = 0;

    while (!done) {
        alloc_result = realloc(result, size * sizeof(char));
        if (alloc_result == NULL) {
            free(result);
            result = NULL;
            done = true;
        } else {
            result = alloc_result;

            read_from = result + result_len;

            fgets_result = fgets(read_from, size - result_len, file);
            if (fgets_result == NULL) {
                free(result);
                result = NULL;
                done = true;
            } else {
                result_len = strlen(result);
                //assert(result_len < size);
                if (feof(file)) {
                    done = true;
                } else if (result[result_len - 1] == '\n') {
                    result[result_len - 1] = '\0';
                    //assert(strlen(result) == result_len - 1);
                    done = true;
                }
            }
        }
        size = size * 2;
    }

    //assert(result == NULL || result[strlen(result)] != '\n');
    return (result);
}

char *readline_from_stdin(void) {
    return (readline(stdin));
}

dict_exc_t dict_exc_from_file(char *filename) {
    expression_t expr= NULL;
    dict_exc_t result = NULL;
    FILE *fd = NULL;
    char *line = NULL;

    fd = fopen(filename, "r+");

    if (fd != NULL) {
        /* filename is a existing file, so create the empty dict */
        result = dict_exc_empty();
        while (!feof(fd)) {
            line = readline(fd);
            if (line == NULL) {
                /* this is the case of the last (empty) line */
                continue;
            }
            expr = strtok(line, ",");
            if (expr != NULL) {
        
               result = dict_exc_add(result, expr);
                }
            }
            free(line);
        }
        fclose(fd);

    return (result);
}
