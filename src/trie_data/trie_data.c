#include <stddef.h>
#include <stdlib.h>
#include "trie_data.h"

#define MAX_MASK 32

trie_node *createTrieNode() {
    trie_node *node = (trie_node *)malloc(sizeof(trie_node));
    if (node == NULL) {
        return NULL;
    }
    node->mask = -1; // Ustawienie maski na -1 oznacza brak pasującego prefiksu
    node->children[0] = NULL;
    node->children[1] = NULL;
    return node;
}

void addPrefixToTrie(trie_node *root, uint32_t base, char mask) {
    trie_node *current = root;

    for (int i = MAX_MASK; i >= mask; i--) {
        int bit = (base >> i) & 1;
        if (current->children[bit] == NULL)
            current->children[bit] = createTrieNode();
        current = current->children[bit];
    }
    current->mask = mask;
}

char checkInTrie(trie_node *root, uint32_t ip) {
    trie_node *current = root;
    char maxMask = -1;

    for (int i = MAX_MASK; i >= 0; i--) {
        int bit = (ip >> i) & 1;
        if (current->children[bit] != NULL) {
            current = current->children[bit];
            if (current->mask != -1 && current->mask > maxMask)
                maxMask = current->mask;
        } else {
            break;
        }
    }

    return maxMask;
}

void freeTrie(trie_node *root) {
    if (root == NULL)
        return;

    for (int i = 0; i < 2; i++)
        freeTrie(root->children[i]);

    free(root);
}
