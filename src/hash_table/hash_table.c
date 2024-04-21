#include <stdint.h>
#include "hash_table.h"

#define CAPACITY 50000 // Size of the HashTable.

/**
 * @brief Compute has for key passed.
 * 
 * @param str 
 * @return unsigned long 
 */
uint32_t hash_function(char* str)
{
    uint32_t i = 0;

    for (int32_t j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}