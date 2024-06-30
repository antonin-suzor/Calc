#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

enum input_type {
    INPUT_FILE,
    INPUT_STDIN,
    INPUT_STRING,
};

struct input {
    enum input_type type;
    char* string_source;
    FILE* file_source;
    int index;
};

struct input* new_input_file(char* filename);
struct input* new_input_stdin();
struct input* new_input_string(char* string);

/**
 * Get the next character from the input.
 * 
 * @param input The input to read from.
 * @return The next character from the input, or EOF on end of input or error.
*/
char get_next_char(struct input* input);

#endif /* INPUT_H */
