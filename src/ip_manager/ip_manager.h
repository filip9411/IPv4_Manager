#ifndef E38D31D7_475B_4425_876D_CBA539831D99
#define E38D31D7_475B_4425_876D_CBA539831D99

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "trie_data.h"

typedef trie_node ip_container;

/**
 * @brief Init container to store IP prefixes.
 *
 * @return ip_container*
 */
ip_container *initContainer();

/**
 * @brief Add base and mask pair to container.
 *
 * @param container
 * @param base
 * @param mask
 * @return int32_t
 */
int32_t add(ip_container *container, const uint32_t base, const char mask);

/**
 * @brief Delete base and mask pair from the container.
 *
 * @param container
 * @param base
 * @param mask
 * @return int32_t
 */
int32_t del(ip_container *container, const uint32_t base, const char mask);

/**
 * @brief Check if passed IP number is present in container.
 * Returns maximum mask value found for campatible base/mask pair.
 *
 * @param container
 * @param ip
 * @return char
 */
char check(ip_container *container, const uint32_t ip);

#endif /* E38D31D7_475B_4425_876D_CBA539831D99 */
