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
uint32_t hashFunction(uint32_t key)
{
    return key % CAPACITY;
}

hash_table_item* createItem(uint32_t key, char value)
{
    // Creates a pointer to a new hash_table item.
    hash_table_item* item = (hash_table_item*) malloc(sizeof(hash_table_item));
    item->key = (uint32_t*) malloc(sizeof(uint32_t));
    item->value = (char*) malloc(sizeof(char));
    memcpy(item->key, &key, sizeof(uint32_t));
    memcpy(item->value, &value, sizeof(char));
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

void insertItem(hash_table* table, uint32_t key, char value)
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

char* searchItem(hash_table* table, uint32_t key)
{
    // Searches for the key in the HashTable.
    // Returns NULL if it doesn't exist.
    int index = hashFunction(key);
    hash_table_item* item = table->items[index];

    // Provide only non-NULL values.
    if (item != NULL)
    {
        if (*(item->key) == key)
            return item->value;
    }

    return NULL;
}

void deleteItem(hash_table* table, uint32_t key)
{
    // Deletes an item from the table.
    int index = hashFunction(key);
    hash_table_item* item = table->items[index];

    if (item == NULL)
    {
        // Does not exist.
        return;
    } else
    {
        // Collision chain does not exist.
        // Remove the item.
        // Set table index to NULL.
        table->items[index] = NULL;
        freeItem(item);
        table->count--;
        return;
    }
}

void printSearch(hash_table *table, uint32_t key)
{
    char* val;

    if ((val = searchItem(table, key)) == NULL)
    {
        printf("Key:%u does not exist\n", key);
        return;
    }
    else
    {
        printf("Key:%u, Value:%d\n", key, *(val));
    }
}