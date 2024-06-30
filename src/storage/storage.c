#include "storage.h"

#include <stdlib.h>

#include "store/store.h"

static struct store* top_level_store = NULL;
static int storage_depth = 0;

int get_storage_depth() {
    return storage_depth;
}

int add_storage_layer() {
    struct store* store = new_store(top_level_store);
    if (!store) {
        return 1;
    }
    top_level_store = store;
    storage_depth++;
    return 0;
}

int remove_storage_layer() {
    if (!top_level_store) {
        return 1;
    }
    struct store* old_store = top_level_store;
    top_level_store = store_free_and_get_parent(old_store);
    storage_depth--;
    return 0;
}


int put_identifier(struct identifier* identifier) {
    if (!top_level_store) {
        return 1;
    }
    return store_put_identifier(identifier, top_level_store);
}

struct identifier* get_identifier(char* name) {
    if (!top_level_store) {
        return NULL;
    }
    struct store* store = top_level_store;
    while (store) {
        struct identifier* identifier = store_get_identifier(name, store);
        if (identifier) {
            return identifier;
        }
        store = store->parent;
    }
    return NULL;
}
