# Lab 1. Traductor

  - ### Diseño y funcionamiento

Para la realizacion de este traductor decidimos crear un diccionario, en el cual se alojan las palabras y sus traducciones al ingles, para esto implementamos el tad dict, en dict.c, esta estructura es un puntero a la lista enlasada list, implementada en list.c; desde dict se llama a las funciones alojadas en la lista enlasada, pasandole los parametros correctos.

La lista enlasada list es un puntero a la estructura pair y por un puntero next,  que señala el siguiente elemento de la lista. La estructura pair es compuesta por dos estructuras word, (definidas en word.c) una para la palabra y otra para la definicion.
Word es simplemente un puntero a char. Aqui se definen las funciones basicas para añadir y quitar una palabra, comparar etc..

De la misma manera se creo un diccionario para las palabras excluidas, con la diferencia que la lista enlasada no contiene la estructura pair, sino que a un word, dado que para las palabras excluidas (Ignoradas) no hace falta definicion.

En el archivo traduc.c, se implementan las funciones clave para el funcionamiento del programa en si, es decir, donde se produce la traduccion de palabras. Aqui se lee el archivos a traducir y se escribe el nuevo archivo ya traducido. 

El archivo file.c contiene las funciones utilizadas para pasar de archivos de texto a las estructuras diccionario, y viseversa.

Finalmente en el menu, main.c, se usa getopt para leer las flags y archivos que ingresa el usuario desde la terminal, se crean y se eliminan los diccionarios, y se llama a las funciones necesarias.

Para el funcionamiento del programa es necesario ingresar un archivo de lectura, en formato .txt, con el flag -i y un diccionario, si no se pasa uno distinto por flag, el programa cargara automaticamente el diccionario "dictionary.txt". Para la lista de excluidos y para el output de el texto ya traducido no es necesario que estos existan. Es decir, si no se pasa flag para cargar la lista de excluidos, el traductor intentara crear la lista "excluded.txt", de no existir este archivo, lo generara automaticamente con el mismo nombre. Lo mismo ocurre con el output.

El traductor reconoce entre mayusculas y minusculas, por lo tanto, si se ingresa para traducir un texto que contiene mayusculas, y estas palabras no estan cargadas de esta forma en el diccionario, el traductor no las va a reconocer. Ademas devido a que en ingles no exite los simbolos "¿" y "¡" , el programa va  generar un error.

Las palabras y sus traducciones en el diccionario.txt deben estar separadas por una coma (,). Las palabras en la lista de ignorados, (excluidos.txt) deben finalizar con una coma.

El tamaño maximo aceptado para una palabra es de 20 (veinte) caracteres.


  - ### Dependencias e instalacion

Para este programa se utilizaron las dependencias estandar de c. 
Estas son:   

 <assert.h>
 <stdbool.h>
 <stdio.h>
 <stdlib.h>
 <string.h>
 <ctype.h>
 <getopt.h>

En caso de que el usuario no las tenga instaladas:
Descargar del siguiente link:

[Dependencias](https://gmplib.org/download/gmp/gmp-6.1.0.tar.xz)

Extraer y configurar:

        $ tar Jxvf gmp-6.1.0.tar.xz
        $ cd gmp-6.1.0
        $ ./configure --prefix=/usr
        
Compilar:


        $ make; make check
        
  - ### Forma de uso:
	Para ejecutar el traductor se escribe por terminal: ./traductor (comndos)
	Los comandos que reconoce son:
	-i FILE | --input=FILE      : Documento de entrada. (Requerido)
	-d FILE | --dictionary=FILE : Diccionario de traducción.
	-g FILE | --ignored=FILE    : Diccionario de palabras ignoradas.
	-o FILE | --output=FILE     : Archivo de salida.
	-r      | --reverse         : Dirección de la traducción.

Una vez que se ejecuto el programa, si estan todas las palabras del archivo de entrada en el diccionario y en el diccionario de palabras
ignoradas, el programa terminara y en el archivo de salida se encontrara la traduccion.
Si no llega a encontrar la palabra XXXXXXXX en los dicionarios se imprimira el menu:

	No translation for the word: XXXXXXXX
	Ignore(i) - Ignore All (h) - Translated as (t) - Always translate as (s)

El comando  "-i" ignora la palabra XXXXXXXX unicamenta por esa vez. El comando "h" ignora la palabra XXXXXXXX  cada vez que aparesca en el texto
y futuros textos que cargen al mismo diccionario de palabras ignoradas. EL comando "t" nos pedira la traduccion de la palabra XXXXXXXX, y nos 
traducira cada ves que aparece XXXXXXXX como la traduccion que le dimos. Por ultimo el comando "s" nos pide la traduccion para XXXXXXXX y
cada vez que aparece la misma en el texto y futuros texto  que cargen el mismo diccionario nos la traducira.
