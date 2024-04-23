#ifndef E38D31D7_475B_4425_876D_CBA539831D99
#define E38D31D7_475B_4425_876D_CBA539831D99

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "trie_data.h"

typedef trie_node ip_container;

/**
 * @brief
 *
 * @return true
 * @return false
 */
bool printHello();

/**
 * @brief
 *
 * @return trie_node*
 */
ip_container *initContainer();

/**
 * @brief
 *
 * @param base
 * @param mask
 * @return int32_t
 */
int32_t add(ip_container *container, uint32_t base, char mask);

/**
 * @brief
 *
 * @param base
 * @param mask
 * @return int32_t
 */
int32_t del(ip_container *container, uint32_t base, char mask);

/**
 * @brief
 *
 * @param ip
 * @return char
 */
char check(ip_container *container, uint32_t ip);

#endif /* E38D31D7_475B_4425_876D_CBA539831D99 */
