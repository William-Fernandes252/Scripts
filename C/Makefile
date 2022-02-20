CFLAGS: -std=gnu99 -pedantic -Wall -Werror
GDBFLAGS: -g

#	general instructions to compile simple programs for testing purposes.
%.exe: %.c
	gcc -o $@ $(CFLAGS) $(GDBFLAGS) $< -lm
%.o: %.c
	gcc $(CFLAGS) -c $<
.PHONY: clean
clean:
	rm $@ -f *.o *.c~ *.o~ *.exe