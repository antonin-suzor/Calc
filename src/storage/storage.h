#ifndef STORAGE_H
#define STORAGE_H

#include "identifier.h"

int get_storage_depth();
int add_storage_layer();
int remove_storage_layer();

int put_identifier(struct identifier* identifier);
struct identifier* get_identifier(char* name);

#endif /* STORAGE_H */
