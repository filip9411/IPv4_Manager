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

void addPrefixToTrie(trie_node **root, uint32_t base, char mask) {
    trie_node *current = *root;

    for (uint8_t i = MAX_MASK; i >= mask; i--) {
        uint8_t bit = (base >> i) & (uint32_t)1;
        if (current->children[bit] == NULL)
            current->children[bit] = createTrieNode();
        current = current->children[bit];
    }
    current->mask = mask;
}

void deletePrefixFromTrie(trie_node **root, uint32_t base, char mask) {
    trie_node *current = *root;
    trie_node *parent = NULL;
    uint8_t bit;

    // Przechodzenie do węzła zawierającego prefiks do usunięcia
    for (uint8_t i = MAX_MASK; i >= mask; i--) {
        bit = (base >> i) & (uint32_t)1;
        if (current->children[bit] == NULL)
            return; // Prefiks nie istnieje w drzewie
        parent = current;
        current = current->children[bit];
    }

    // Usuwanie prefiksu i naprawa struktury drzewa Trie
    if (current->children[0] == NULL && current->children[1] == NULL) {
        // Usuwanie liścia
        free(current);
        parent->children[bit] = NULL;
    } else {
        // Usuwanie węzła wewnętrznego
        current->mask = -1;
    }
}

char checkInTrie(trie_node **root, uint32_t ip) {
    trie_node *current = *root;
    char maxMask = -1;

    for (uint8_t i = MAX_MASK; i >= 0; i--) {
        uint8_t bit = (ip >> i) & (uint32_t)1;
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

    for (uint8_t i = 0; i < 2; i++)
        freeTrie(root->children[i]);

    free(root);
}
