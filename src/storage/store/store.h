#ifndef STORE_H
#define STORE_H

#include <stdlib.h>

#include "identifier_chain.h"

struct store {
    struct identifier_chain* identifier_chain;
    size_t length;
    struct store* parent;
};

struct store* new_store(struct store* parent);

/**
 * Put an identifier in the store. If it already exists, it will be replaced.
 * 
 * @param identifier The identifier to add.
 * @param store The store to add the identifier to.
 * @return the length of the store after adding the identifier, or 0 on error.
 */
int store_put_identifier(struct identifier *identifier, struct store* store);

struct identifier* store_get_identifier(char* name, struct store* store);

struct store* store_free_and_get_parent(struct store* store);

void destroy_store(struct store* store);

#endif /* STORE_H */
