#include <stdio.h>
#include "word.h"

int read_char(void) {

    int ch = getchar();

    if(ch == '\n' || ch == '\t') {
        return ' ';
    }

    return ch;

}

int read_word(char *buffer, int len) {

    int ch, pos = 0;
    while((ch = read_char()) != ' ')
        ;
    while(ch != ' ' && ch != EOF) {
        if(pos < len) buffer[pos++] = ch;
        ch = read_char();
    }

    buffer[pos] = '\0';
    
    return pos;

}