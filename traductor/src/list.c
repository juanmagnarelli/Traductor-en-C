#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "list.h"

struct _node_t{
	pair_t pair;
	struct _node_t *next;
};

list_t list_empty(void){
	list_t list = NULL;
	return list;
}

list_t list_destroy(list_t list){
	list_t list_aux = NULL;
    while (list != NULL){
		list_aux = list;
		list = list -> next;
	    list_aux -> pair = pair_destroy(list_aux -> pair);
	    list_aux -> next = NULL;
	    free (list_aux);
    }
	return list;
}

word_t list_search(list_t list, word_t word){

	list_t listaux = list;
	word_t result= NULL;
	bool b = true;

	while (listaux != NULL && b){
		if (word_is_equal(pair_fst(listaux -> pair) , word)){
		  result = pair_snd (listaux -> pair);
		  b = false;
		}
		else{
		     listaux = listaux -> next;
		    }
         }
	return result;
}

list_t list_append(list_t list, word_t first, word_t second) {
	list_t list_aux,aux1;
    if (list == NULL){
		list = calloc(1,sizeof(struct _node_t));
		list -> pair = pair_from_ingl_esp(first,second);
		list -> next = NULL;
		}
    else {
		list_aux = list;
		aux1 = list -> next;
	    while ( aux1 != NULL){
	     	aux1 = aux1 -> next;
			list_aux = list_aux -> next;
		}
	      list_aux -> next = calloc(1,sizeof(struct _node_t));
	      list_aux = list_aux -> next;
	      list_aux -> pair = pair_from_ingl_esp(first,second);
	      list_aux -> next = NULL;
	}
	list_aux = NULL;
	return list;
 }


void list_dump(list_t list, FILE * fd){
	char *first,*second;
    list_t list_aux = list;

	while (list_aux != NULL) {
	      first = word_to_string(pair_fst(list_aux -> pair));
	      second = word_to_string(pair_snd(list_aux -> pair));
	      fprintf(fd,"%s,%s\n",first,second);
	      list_aux = list_aux -> next;
 		  free(first);
		  first = NULL;
		  free(second);
		  second = NULL;
	}

}

list_t list_revers(list_t list){
	list_t aux = list;

	while (aux != NULL) {
			aux->pair = pair_revers(aux->pair);
			aux = aux -> next;
		}
		free(aux);
	return (list);

}
