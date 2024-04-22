#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hash_table.h"


#define CAPACITY 50000 // Size of the hash_table.

/**
 * @brief Compute has for key passed.
 * 
 * @param str 
 * @return unsigned long 
 */
uint32_t hashFunction(uint32_t* str)
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

hash_table* createTable(int size)
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

/**
 * @brief 
 * 
 * @param item 
 */
void freeItem(hash_table_item* item)
{
    // Frees an item.
    free(item->key);
    free(item->value);
    free(item);
}

/**
 * @brief 
 * 
 * @param table 
 */
void freeTable(hash_table* table)
{
    // Frees the table.
    for (int i = 0; i < table->size; i++)
    {
        hash_table_item* item = table->items[i];

        if (item != NULL)
            freeItem(item);
    }

    free(table->items);
    free(table);
}

void printTable(hash_table* table)
{
    printf("\nHash Table\n-------------------\n");

    for (int i = 0; i < table->size; i++)
    {
        if (table->items[i])
        {
            printf("Index:%d, Key:%u, Value:%s\n", i, *(table->items[i] -> key), table->items[i]->value);
        }
    }

    printf("-------------------\n\n");
}

void insertItem(hash_table* table, uint32_t* key, char* value)
{
    hash_table_item* new_item = createItem(key, value);
    int32_t index = hashFunction(key);

    hash_table_item* current_item = table->items[index];
    if(current_item = NULL)
    {
        // Key does not exist
        if (table->count == table->size)
        {
            // HashTable is full.
            printf("insertItem Error: Hash Table is full\n");
            freeItem(new_item);
            return;
        }

        table->items[index] = new_item;
        table->count++;
    } else
    {
        // Key already exists in the hash table. Update only the value.
    }
    return;
}