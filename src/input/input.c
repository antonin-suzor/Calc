#include "input.h"

#include <stdlib.h>



struct input* new_input_file(char* filename) {
    struct input* input = calloc(1, sizeof(struct input));
    if (!input) {
        return NULL;
    }
    input->file_source = fopen(filename, "r");
    if (input->file_source == NULL) {
        free(input);
        return NULL;
    }
    input->type = INPUT_FILE;
    return input;
}

struct input* new_input_stdin() {
    struct input* input = calloc(1, sizeof(struct input));
    if (!input) {
        return NULL;
    }
    input->type = INPUT_STDIN;
    return input;
}

struct input* new_input_string(char* string) {
    struct input* input = calloc(1, sizeof(struct input));
    if (!input) {
        return NULL;
    }
    input->type = INPUT_STRING;
    input->string_source = string;
    return input;
}



static char get_next_char_file(struct input* input) {
    if (!input || !input->file_source) {
        return EOF;
    }
    return fgetc(input->file_source);
}

static char get_next_char_stdin(struct input* input) {
    if (!input) {
        return EOF;
    }
    if (input->index == -1 || !input->string_source) {
        if (input->string_source) {
            free(input->string_source);
        }
        char* line = NULL;
        size_t len = 0;
        ssize_t nb_read = getline(&line, &len, stdin);
        if (nb_read == -1) {
            free(line);
            return EOF;
        }
        input->string_source = line;
        input->index = 0;
    }
    char c = input->string_source[input->index++];
    if (c == 0) {
        // fetch next line
        input->index = -1;
        return get_next_char_stdin(input);
    }
    return c;

}

static char get_next_char_string(struct input* input) {
    if (!input || !input->string_source || input->index < 0) {
        return EOF;
    }
    char c = input->string_source[input->index++];
    if (c == 0) {
        // end of string
        input->index = -1;
        return EOF;
    }
    return c;
}

/**
 * Get the next character from the input.
 * 
 * @param input The input to read from.
 * @return The next character from the input, or EOF on end of input or error.
*/
char get_next_char(struct input* input) {
    if (!input) {
        return EOF;
    }
    switch (input->type) {
        case INPUT_FILE:
            return get_next_char_file(input);
        case INPUT_STDIN:
            return get_next_char_stdin(input);
        case INPUT_STRING:
            return get_next_char_string(input);
    }
    return EOF;
}
