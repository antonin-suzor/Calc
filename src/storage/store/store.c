#include "store.h"
#include "identifier_chain.h"

struct store* new_store(struct store* parent) {
    struct store* store = calloc(1, sizeof(struct store));
    if (!store) {
        return NULL;
    }
    store->parent = parent;
    return store;
}

/**
 * Put an identifier in the store. If it already exists, it will be replaced.
 * 
 * @param identifier The identifier to add.
 * @param store The store to add the identifier to.
 * @return the length of the store after adding the identifier, or 0 on error.
 */
int store_put_identifier(struct identifier *identifier, struct store* store) {
    if (!store) {
        return 0;
    }
    struct identifier_chain* old = store->identifier_chain;
    if (chain_put_identifier(identifier, &store->identifier_chain) != 0) {
        return 0;
    }
    if (store->identifier_chain != old) {
        store->length++;
    }
    return store->length;
}

struct identifier* store_get_identifier(char* name, struct store* store) {
    if (!store) {
        return NULL;
    }
    return chain_get_identifier(name, store->identifier_chain);
}

struct store* store_free_and_get_parent(struct store* store) {
    if (!store) {
        return NULL;
    }
    struct store* parent = store->parent;
    free_identifier_chain(store->identifier_chain);
    free(store);
    return parent;
}

void destroy_store(struct store* store) {
    if (!store) {
        return;
    }
    destroy_store(store->parent);
    free_identifier_chain(store->identifier_chain);
    free(store);
}
