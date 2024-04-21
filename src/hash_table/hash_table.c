#include <stdint.h>
#include <stdlib.h>
#include "hash_table.h"
#include <string.h>


#define CAPACITY 50000 // Size of the HashTable.

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

typedef struct hash_table
{
    // Contains an array of pointers to items.
    hash_table_item** items;
    int size;
    int count;
} hash_table;

/**
 * @brief Create a item object
 * 
 * @param key 
 * @param value 
 * @return hash_table_item* 
 */
hash_table_item* createItem(uint32_t* key, char* value)
{
    // Creates a pointer to a new HashTable item.
    hash_table_item* item = (hash_table_item*) malloc(sizeof(hash_table_item));
    item->key = (uint32_t*) malloc(sizeof(uint32_t));
    item->value = (char*) malloc(strlen(value) + 1);
    memcpy(item->key, key, sizeof(uint32_t));
    memcpy(item->value, value, sizeof(char));
    return item;
}