CFLAGS: -std=gnu99 -pedantic -Wall -Werror

#	justify:	Formats a file of text.
justify: justify.o line.o word.o
	gcc -o justify justify.o line.o word.o $(CFLAGS)
justify.o: justify.c word.h line.h
	gcc -c justify.c $(CFLAGS)
word.o: word.c word.h
	gcc -c word.c $(CFLAGS)
line.o: line.c word.h
	gcc -c line.c $(CFLAGS)