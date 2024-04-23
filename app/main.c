#include <stdio.h>
#include <assert.h>

#include "ip_manager.h"

int main()
{   
    ip_container *root = initContainer();

    assert(add(root, 1234, 45) == -1); // add() with wrong parameters
    assert(del(root, 1234, 45) == -1); // del() with wrong parameters

    add(root, 0x20408000, 20); // 32.64.128.0/20

    add(root, 0x0A140000, 16); // 10.20.0.0/16
    assert(check(root, 0x0A140000) == 16U);

    add(root, 0x0A142000, 24); // 10.20.0.0/24
    assert(check(root, 0x0A140000) == 24U);

    assert(check(root, 0x0A141000) == 24U); // 10.20.1.0

    del(root, 0x0A140000, 24); // 10.20.0.0/24
    assert(check(root, 0x0A140000) == 16U);

    del(root, 0x0A140000, 16); // 10.20.0.0/16
    assert(check(root, 0x0A140000) == -1);

    printf("OK - all assertions passed.\n");

    // printf("Check 10.20.1.1: %d\n", check(root, 0x0A140101));
    // printf("Check 32.64.128.0: %d\n", check(root, 0x20408000));
    // printf("Check 32.64.144.0: %d\n", check(root, 0x20409000));
    // printf("Check 192.168.1.1: %d\n", check(root, 0xC0A80101));
    // printf("Check 10.20.0.0: %d\n", check(root, 0x0A140000));

    freeTrie(root);
    return 0;
}