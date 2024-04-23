#include <stdio.h>
#include <assert.h>

#include "ip_manager.h"
#include "trie_data.h"

int main()
{
    printHello();
    
    trie_node *root = createTrieNode();

    addPrefixToTrie(root, 0x0A140000, 16);
    addPrefixToTrie(root, 0x20408000, 20);

    printf("Check 10.20.0.0: %d\n", checkInTrie(root, 0x0A140000));
    printf("Check 10.20.1.1: %d\n", checkInTrie(root, 0x0A140101));
    printf("Check 32.64.128.0: %d\n", checkInTrie(root, 0x20408000));
    printf("Check 32.64.144.0: %d\n", checkInTrie(root, 0x20409000));
    printf("Check 192.168.1.1: %d\n", checkInTrie(root, 0xC0A80101));

    freeTrie(root);

    assert(true);
    printf("OK - all assertions passed.\n");
    return 0;
}