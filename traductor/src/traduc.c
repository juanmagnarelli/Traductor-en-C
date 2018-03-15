#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include "traduc.h"


#define MAX_SIZE 20

FILE *open(char *name_file) {
	FILE *file = NULL;

	file = fopen(name_file,"r+");
	if(file == NULL)
		file = fopen(name_file, "w+");

	assert(file != NULL);

  return (file);
}

int close_file(FILE *file){
		int i;

		i = fclose(file);
		assert(i == 0);

		return (0);
}

char *menu(dict_exc_t dict_exc, dict_t dict, dict_t dict_aux, char *chain){
	char c;
	expression_t word_translated;
	expression_t expr;
	char * string = malloc(MAX_SIZE);

	back:
		printf("No translation for the word: -%s- \n", chain);
		printf("Ignore(i) - Ignore All (h) - Translated as (t) - Always translate as (s)\n");
		scanf(" %c", &c);
		if (c == 'i') {
			return (chain);
		}
		else if (c == 'h') {
			dict_exc = dict_exc_add(dict_exc, chain);
			return (chain);
		}
		else if (c == 't') {
			printf("Translate the word: %s as:",chain);
			scanf(" %s",string);
			word_translated = string;
			expr = chain;
			dict_aux = dict_add(dict_aux,expr,word_translated);
			return (word_translated);
		}
		else if(c == 's'){
			printf("Translate the word: %s as: ",chain);
			scanf(" %s", string);
			word_translated = string;
			expr = chain;
			dict = dict_add(dict, expr, word_translated);
			return (word_translated);
		}
		else{
			printf("incorrect command\n");
			goto back;
		}
	free(string);

}

int translation(char *chain, dict_t dict,dict_t dict_aux, dict_exc_t dict_exc, FILE *file_r){

	if (strlen(chain) == 0)
		return (0);

	if (dict_exc_exists(dict_exc, chain)) {
			fputs(chain, file_r);
	}
	else if (dict_exists(dict, chain)) {
		chain = dict_search(dict, chain);
		fputs(chain, file_r);
	}
	else if (dict_exists(dict_aux, chain)){
				chain = dict_search(dict_aux, chain);
				fputs(chain, file_r);
	}
	else{
			chain = menu(dict_exc, dict, dict_aux, chain);
			fputs(chain, file_r);
		}

	return (0);
}

bool symbols(char c) {
	char symbols[26] = ",.?!()[]*' /$=\"\n1234567890";
	bool b = false;
	int i = 0;
	while (!b && i < 26) {
		if (symbols[i] == c)
			b = true;
		i++;
	}
	return (b);
}

int search_word(char *name_w, dict_t dict, dict_t dict_aux, dict_exc_t dict_exc,char *name_r){
	FILE *file_w = NULL;
	FILE *file_r = NULL;
	char chain[MAX_SIZE];
	int i= 0;
	char a;

	file_w = fopen(name_w, "r");
	if(file_w == NULL){
		printf("File %s does not exist \n",name_w);
		return (0);
	}
	file_r = open(name_r);

	while (feof(file_w) == 0) {
		while (i < MAX_SIZE) {
			if (feof(file_w) != 0) {
				break;
			}
			chain[i] = fgetc(file_w);
			if (symbols(chain[i])) {
				fputc(chain[i],file_r);
				chain[i] = '\0';
			}
			else {
				i++;
				while (!symbols(chain[i-1])) {
					if (feof(file_w) != 0)
						break;
					chain[i] = fgetc(file_w);
					i++;
				}
				a = chain[i-1];
				if (feof(file_w) != 0) {
					chain[i] ='\0';
					break;
				}
				chain[i-1] ='\0';
				translation(chain,dict,dict_aux,dict_exc, file_r);
				fputc(a,file_r);
				break;
			}
		}
		if (feof(file_w) != 0) {
			break;
		}
		i = 0;
		while (i < MAX_SIZE) {
			chain[i] = '\0';
			i++;
		}
		i = 0;
		a = '\0';
	}

close_file(file_w);
close_file(file_r);

	return (0);
}
