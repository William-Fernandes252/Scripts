/* Formats a file of text. */

#include <string.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LENGTH 20

int main(void) {

    char buffer[MAX_WORD_LENGTH+2];
    int word_len;

    clear_line();
    for(;;) {

        
        word_len = read_word(buffer, MAX_WORD_LENGTH+1);
        if(word_len == 0) {
            flush_line();
            return EXIT_SUCCESS;
        }

        if(word_len > MAX_WORD_LENGTH) {
            buffer[MAX_WORD_LENGTH] = '*';
        }

        if(word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }

        add_word(buffer);

    }

    return EXIT_SUCCESS;

}