#ifndef F2CE96C7_81D0_4F65_B556_2BB474BC8B66
#define F2CE96C7_81D0_4F65_B556_2BB474BC8B66

#include <stdint.h>
typedef struct trie_node {
    struct trie_node *children[2];
    char mask;
} trie_node;

/**
 * @brief Create a Trie Node object
 * 
 * @return trie_node* 
 */
trie_node* createTrieNode();

/**
 * @brief 
 * 
 * @param root 
 * @param base 
 * @param mask 
 */
void addPrefixToTrie(trie_node *root, uint32_t base, char mask);

/**
 * @brief 
 * 
 * @param root 
 * @param ip 
 * @return char 
 */
char checkInTrie(trie_node *root, uint32_t ip);

/**
 * @brief 
 * 
 * @param root 
 */
void freeTrie(trie_node *root);

#endif /* F2CE96C7_81D0_4F65_B556_2BB474BC8B66 */
