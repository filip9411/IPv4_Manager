#include <stdint.h>
#include <stdlib.h>
#include "hash_table.h"
#include <string.h>


#define CAPACITY 50000 // Size of the hash_table.

/**
 * @brief Compute has for key passed.
 * 
 * @param str 
 * @return unsigned long 
 */
uint32_t hashFunction(char* str)
{
    uint32_t i = 0;

    for (int32_t j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}

hash_table_item* createItem(uint32_t* key, char* value)
{
    // Creates a pointer to a new hash_table item.
    hash_table_item* item = (hash_table_item*) malloc(sizeof(hash_table_item));
    item->key = (uint32_t*) malloc(sizeof(uint32_t));
    item->value = (char*) malloc(strlen(value) + 1);
    memcpy(item->key, key, sizeof(uint32_t));
    memcpy(item->value, value, sizeof(char));
    return item;
}

hash_table* create_table(int size)
{
    // Creates a new hash_table.
    hash_table* table = (hash_table*) malloc(sizeof(hash_table));
    table->size = size;
    table->count = 0;
    table->items = (hash_table_item**) calloc(table->size, sizeof(hash_table_item*));

    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;

    return table;
}