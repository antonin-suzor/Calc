#ifndef IDENTIFIER_CHAIN_H
#define IDENTIFIER_CHAIN_H

#include "../identifier.h"

struct identifier_chain {
    struct identifier* identifier;
    struct identifier_chain* next;
};

/**
 * Add an identifier at the beginning of the chain.
 * 
 * @param identifier The identifier to add.
 * @param chain The chain to add the identifier to.
 * @return 0 if the identifier was added successfully, 1 otherwise.
 */
int chain_add_identifier(struct identifier* identifier, struct identifier_chain** chain);

/**
 * If an identifier with the same name already exists, free its content and update it, otherwise add it at the beginning of the chain.
 * 
 * @param identifier The identifier to add.
 * @param chain The chain to add the identifier to.
 * @return 0 if the identifier was added successfully, 1 otherwise.
 */
int chain_put_identifier(struct identifier* identifier, struct identifier_chain** chain);

/**
 * Get an identifier from the chain.
 * 
 * @param name The name of the identifier to get.
 * @param chain The chain to get the identifier from.
 * @return The identifier if it was found, NULL otherwise.
 */
struct identifier* chain_get_identifier(char* name, struct identifier_chain* chain);

/**
 * Free the memory allocated for the chain.
 *
 * @param chain The chain to free.
 */
void free_identifier_chain(struct identifier_chain* chain);

#endif /* IDENTIFIER_CHAIN_H */
