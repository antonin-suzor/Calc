#ifndef AST_H
#define AST_H

enum ast_node_type {
    IDENTIFIER,
    BINOP_PLUS,
    BINOP_MINUS,
};

struct ast_node {
    enum ast_node_type type;
    struct ast_node* children;
    char* source;
};

void free_ast_node(struct ast_node* node);

#endif /* AST_H */
