#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>

#include "dict.h"
#include "file.h"
#include "traduc.h"
#include "dict_exc.h"


int main(int argc, char *argv[]) {
  char *iflag = NULL;
  char *dflag = NULL;
  char *gflag = NULL;
  char *oflag = NULL;
  int rflag = 0;
  int c;
  dict_t dict = NULL;
  dict_t dict_aux = dict_empty();
  dict_exc_t dict_exc = dict_exc_empty();
  FILE *Dfile;
  FILE *Gfile;

  opterr = 0;
  while ((c = getopt (argc, argv, "i:d:g:o:r")) != -1)
    switch (c)
    {
      case 'i':
        iflag = optarg;
        break;
      case 'd':
        dflag = optarg;
        break;
      case 'g':
        gflag = optarg;
        break;
      case 'o':
        oflag = optarg;
        break;
      case 'r':
        rflag = 1;
        break;
      case '?':
      if (optopt == 'i' || optopt == 'd' || optopt == 'g'|| optopt == 'o')
        fprintf (stderr, "Option -%c requires an argument.\n", optopt);
      else if (isprint (optopt))
        fprintf (stderr, "Unknown option `-%c'.\n", optopt);
      else
        fprintf (stderr,"Unknown option character `\\x%x'.\n",optopt);
      return (1);
      default:
      abort ();
    }

  for (int index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);

  if (iflag == NULL) {
    printf("Requires input argumnet, insert -i File.txt \n");
    return (0);
  }

  if (dflag == NULL)
    dflag = "translated.txt";

  if (oflag == NULL)
    oflag = "writing.txt";

  dict = dict_from_file(dflag);
  if (dict == NULL) {
      printf("Can not load dict from filename %s\n", dflag);
      return 0;
  } else {
      printf("\t-> The dictionary was successfully loaded.\n");
  }

  if (rflag == 1)
    dict = dict_revers(dict);

  if (gflag == NULL){
    gflag = "excluded.txt";
    Gfile= fopen(gflag,"r+");

    if(Gfile == NULL){
       Gfile= fopen(gflag,"w+");
       printf("\t->Can not load ignored list. New Created\n");
    } else {
      printf("\t-> The ignored list was successfully loaded.\n");
    }
  }
  else {
     Gfile= fopen(gflag,"r+");
    if(Gfile == NULL){
       Gfile= fopen(gflag,"w+");
       printf("\t->Can not load ignored list. New Created\n");
    } else {
       printf("\t-> The ignored list was successfully loaded.\n");
    }
  }

  Dfile= fopen(dflag,"r+");
  dict_exc = dict_exc_from_file(gflag);

  search_word(iflag,dict,dict_aux,dict_exc,oflag);

  if (rflag == 1)
    dict = dict_revers(dict);

  dict_dump(dict,Dfile);
  dict_exc_dump(dict_exc,Gfile);
  fclose (Gfile);
  fclose (Dfile);
  dict = dict_destroy(dict);
  dict_aux = dict_destroy(dict_aux);
  dict_exc = dict_exc_destroy(dict_exc);

  return (0);
}
