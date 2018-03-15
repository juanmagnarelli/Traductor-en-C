#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#include "list_exc.h"

struct _node2_t{
	word_t word;
	struct _node2_t *next;
};

list_exc_t list_exc_empty(void){
	list_exc_t list  = NULL;
	return list;
}

list_exc_t list_exc_destroy(list_exc_t list){
	list_exc_t list_aux = NULL;
    while (list != NULL){
		list_aux = list;
		list = list -> next;
	    list_aux -> word = word_destroy(list_aux -> word);
	    list_aux -> next = NULL;
	    free (list_aux);
    }
	return list;
}

unsigned int list_exc_length(list_exc_t list){
	list_exc_t list_aux = list;
	unsigned int result = 0;
	while (list_aux != NULL) {
		  result++;
		  list_aux = list_aux -> next;
    }
	return result;
	}


bool list_exc_search(list_exc_t list, word_t word){

	list_exc_t listaux = list;
	bool result= false;

	while (listaux != NULL && !result){
		if (word_is_equal((listaux -> word) , word)){
		  result = true;

		}
		else{
		     listaux = listaux -> next;
		    }
         }
	return result;
}

list_exc_t list_exc_append(list_exc_t list, word_t word) {
	list_exc_t aux,aux1;

    if (list == NULL){
		list = calloc(1,sizeof(struct _node2_t));
		list -> word = word;
		list -> next = NULL;
		}
    else {
		aux = list;
		aux1 = list -> next;
	    while ( aux1 != NULL){
	     	aux1 = aux1 -> next;
			aux = aux -> next;
		}
	      aux -> next = calloc(1,sizeof(struct _node2_t));
	      aux = aux -> next;
	      aux -> word = word;
	      aux -> next = NULL;
	}
	aux = NULL;
	return list;
 }



void list_exc_dump(list_exc_t list, FILE * fd){
	char *data;
    list_exc_t list_aux = list;

	while (list_aux != NULL) {
	      data = word_to_string(list_aux -> word);
	      fprintf(fd,"%s,\n", data);
	      list_aux = list_aux -> next;
 		  free(data);
		  data = NULL;
	}

}
