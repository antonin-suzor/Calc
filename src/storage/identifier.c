#include "identifier.h"

#include <stdlib.h>

struct identifier* new_identifier(char* name, enum identifier_type type, struct ast_node* node) {
    struct identifier* identifier = calloc(1, sizeof(struct identifier));
    if (!identifier) {
        return NULL;
    }
    identifier->name = name;
    identifier->type = type;
    identifier->node = node;
    return identifier;
}

void free_identifier(struct identifier* identifier) {
    free(identifier->name);
    free_ast_node(identifier->node);
    free(identifier);
}
