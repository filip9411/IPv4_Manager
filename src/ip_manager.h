#ifndef E38D31D7_475B_4425_876D_CBA539831D99
#define E38D31D7_475B_4425_876D_CBA539831D99

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

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
 * @param base 
 * @param mask 
 * @return int32_t 
 */
int32_t add(uint32_t base, char mask);

/**
 * @brief 
 * 
 * @param base 
 * @param mask 
 * @return int32_t 
 */
int32_t del(uint32_t base, char mask);

/**
 * @brief 
 * 
 * @param ip 
 * @return char 
 */
char check(uint32_t ip);


#endif /* E38D31D7_475B_4425_876D_CBA539831D99 */
