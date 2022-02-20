#ifndef LINE_H
#define LINE_H

/* 
    clear_line: Clears the current line 
*/
void clear_line(void);

/*
    add_word:   Adds word in the end of the current line.
                If this is not the first word in the line,
                puts one space before the word.
*/
void add_word(const char *buffer);

/*
    space_remaining:    Returns the number of characters 
                        left in the current line.
*/
int space_remaining(void);

/*
    write_line:     Writes the current line with justification.
*/
void write_line(void);

/*
    flush_line:     Writes the current line without justification. 
                    If the line is empty then it does nothing.
*/
void flush_line(void);

#endif