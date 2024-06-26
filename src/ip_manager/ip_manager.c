#include <stdio.h>
#include <stdbool.h>

#include "ip_manager.h"
#include "trie_data.h"

ip_container *initContainer()
{
    return createTrieNode();
}

int32_t add(ip_container *container, const uint32_t base, const char mask)
{
    if (mask <= 0U || mask > 32U)
        return -1;

    addPrefixToTrie(&container, base, mask);

    return 0;
}

int32_t del(ip_container *container, const uint32_t base, const char mask)
{
    if (mask <= 0U || mask > 32U)
        return -1;

    deletePrefixFromTrie(&container, base, mask);

    return 0;
}

char check(ip_container *container, const uint32_t ip)
{
    return checkInTrie(&container, ip);
}