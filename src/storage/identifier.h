#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "../parser/ast.h"

enum identifier_type {
    VARIABLE,
    FUNCTION,
};

struct identifier {
    char* name;
    enum identifier_type type;
    struct ast_node* node;
};

/**
 * Create a new identifier.
 * 
 * @param name The name of the identifier, must be heap-allocated.
 * @param type The type of the identifier.
 * @param node The AST node of the identifier, must be heap-allocated.
 * @return The new identifier.
 */
struct identifier* new_identifier(char* name, enum identifier_type type, struct ast_node* node);

/**
 * Free the memory allocated for the identifier.
 * 
 * @param identifier The identifier to free.
 */
void free_identifier(struct identifier* identifier);

#endif /* IDENTIFIER_H */
