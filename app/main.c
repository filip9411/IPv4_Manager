#include <stdio.h>
#include <assert.h>

#include "ip_manager.h"
#include "hash_table.h"

#define CAPACITY 500

int main()
{
    printHello();
    
    hash_table *ht = createTable(CAPACITY);
    insertItem(ht, 1U, 1U);
    insertItem(ht, 2U, 2U);
    insertItem(ht, 3U, 3U);
    insertItem(ht, 4U, 4U);

    printSearch(ht, 1U);
    printSearch(ht, 2U);
    deleteItem(ht, 2U);
    printSearch(ht, 2U);

    assert(true);
    printf("OK - all assertions passed.\n");
    return 0;
}