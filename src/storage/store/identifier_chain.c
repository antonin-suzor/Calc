#include "identifier_chain.h"

#include <stdlib.h>
#include <string.h>

static struct identifier_chain* chain_get_identifier_chain(char* name, struct identifier_chain* chain) {
    while (chain) {
        if (strcmp(chain->identifier->name, name) == 0) {
            return chain;
        }
        chain = chain->next;
    }
    return NULL;
}

int chain_add_identifier(struct identifier* identifier, struct identifier_chain** chain) {
    struct identifier_chain* new_chain = calloc(1, sizeof(struct identifier_chain));
    if (!new_chain) {
        return 1;
    }
    new_chain->identifier = identifier;
    new_chain->next = *chain;
    *chain = new_chain;
    return 0;
}

int chain_put_identifier(struct identifier* identifier, struct identifier_chain** chain) {
    struct identifier_chain* current = chain_get_identifier_chain(identifier->name, *chain);
    if (current) {
        free_identifier(current->identifier);
        current->identifier = identifier;
        return 0;
    }
    struct identifier_chain* new_chain = calloc(1, sizeof(struct identifier_chain));
    if (!new_chain) {
        return 1;
    }
    new_chain->identifier = identifier;
    new_chain->next = *chain;
    *chain = new_chain;
    return 0;
}

struct identifier* chain_get_identifier(char* name, struct identifier_chain* chain) {
    while (chain) {
        if (strcmp(chain->identifier->name, name) == 0) {
            return chain->identifier;
        }
        chain = chain->next;
    }
    return NULL;
}

void free_identifier_chain(struct identifier_chain* chain) {
    while (chain) {
        struct identifier_chain* next = chain->next;
        free_identifier(chain->identifier);
        free(chain);
        chain = next;
    }
}
