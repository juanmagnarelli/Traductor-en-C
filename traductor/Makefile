CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
OBJECTS = bin/word.o bin/pair.o bin/list.o bin/list_exc.o bin/dict.o bin/dict_exc.o bin/file.o bin/traduc.o bin/main.o

traductor : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o traductor 
bin/word.o : src/word.c src/word.h
	$(CC) $(CFLAGS) -c src/word.c -o bin/word.o 
bin/pair.o : src/pair.c src/pair.h src/word.h
	$(CC) $(CFLAGS) -c src/pair.c -o bin/pair.o
bin/list.o : src/list.c src/list.h src/word.h src/pair.h
	$(CC) $(CFLAGS) -c src/list.c -o bin/list.o
bin/list_exc.o : src/list_exc.c src/list_exc.h src/word.h
	$(CC) $(CFLAGS) -c src/list_exc.c -o bin/list_exc.o
bin/traduc.o : src/traduc.c src/traduc.h src/dict.h
	$(CC) $(CFLAGS) -c src/traduc.c -o bin/traduc.o
bin/file.o : src/file.c src/file.h src/dict.h
	$(CC) $(CFLAGS) -c src/file.c -o bin/file.o
bin/dict.o : src/dict.c src/dict.h src/list.h src/word.h
	$(CC) $(CFLAGS) -c src/dict.c -o bin/dict.o
bin/dict_exc.o : src/dict_exc.c src/dict_exc.h src/list_exc.h src/word.h
	$(CC) $(CFLAGS) -c src/dict_exc.c -o bin/dict_exc.o
bin/main.o : src/main.c src/file.h src/dict.h
	$(CC) $(CFLAGS) -c src/main.c -o bin/main.o

.PHONY : clean
clean :
	rm bin/*.o



