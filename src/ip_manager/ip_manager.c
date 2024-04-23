#include <stdio.h>
#include <stdbool.h>

#include"ip_manager.h"
#include "trie_data.h"

bool printHello()
{
    printf("Hello World!!!\n");
}

int32_t add(uint32_t base, char mask)
{
    if(mask <= 0U || mask > 32U) return -1;

    return 0;
}

int32_t del(uint32_t base, char mask)
{
    if(mask <= 0U || mask > 32U) return -1;

    return 0;
}

char check(uint32_t ip)
{
    return 0;
}