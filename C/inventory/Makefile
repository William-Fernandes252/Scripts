CFLAGS: -std=gnu99 -pedantic -Wall -Werror

#	inventory:	Mantains an inventory database.
inventory: inventory.o insert.o update.o search.o print.o
	gcc -o inventory inventory.o insert.o update.o search.o print.o $(CFLAGS)
inventory.o: inventory.c inventory.h insert.h update.h search.h print.h
	gcc -c inventory.c $(CFLAGS)
insert.o: insert.c insert.h
	gcc -c insert.c $(CFLAGS)
update.o: update.c update.h
	gcc -c update.c $(CFLAGS)
search.o: search.c search.h
	gcc -c search.c $(CFLAGS)
print.o: print.c print.h
	gcc -c print.c $(CFLAGS)