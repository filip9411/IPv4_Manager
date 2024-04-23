#ifndef F2CE96C7_81D0_4F65_B556_2BB474BC8B66
#define F2CE96C7_81D0_4F65_B556_2BB474BC8B66

#include <stdint.h>
typedef struct trie_node
{
    struct trie_node *children[2];
    char mask;
} trie_node;

/**
 * @brief Create a Trie Node object
 * 
 * @return trie_node* 
 */
trie_node *createTrieNode();

/**
 * @brief Add element to Trie data structure. 
 * 
 * @param root 
 * @param base 
 * @param mask 
 */
void addPrefixToTrie(trie_node **root, const uint32_t base, const char mask);

/**
 * @brief Delete element from Trie data structure.
 *
 * @param root
 * @param base
 * @param mask
 */
void deletePrefixFromTrie(trie_node **root, const uint32_t base, const char mask);

/**
 * @brief Check if element is present in Trie data structure. 
 *
 * @param root
 * @param ip
 * @return char
 */
char checkInTrie(trie_node **root, const uint32_t ip);

/**
 * @brief Destruct Trie data structure. 
 *
 * @param root
 */
void freeTrie(trie_node *root);

#endif /* F2CE96C7_81D0_4F65_B556_2BB474BC8B66 */
