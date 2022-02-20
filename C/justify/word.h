#ifndef WORD_H
#define WORD_H

/*  
read_word:  Reads the next word from the input file and stores it in word. 
            Makes word empty if no word could be read because of EOF. 
            Truncates the word if its size exceeds len. Returns the number of
            characters stored. 
*/

int read_word(char *buffer, int len);
#endif