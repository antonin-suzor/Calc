#include "utils.h"

#include <stdlib.h>

int is_entry_end(char c) {
    return c == ';' || c == '\n' || c == '\r';
}
