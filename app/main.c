#include <stdio.h>
#include <assert.h>

#include "ip_manager.h"

int main()
{   
    ip_container *root = initContainer();

    assert(add(root, 1234, 45) == -1); // add() with wrong parameters
    assert(del(root, 1234, 45) == -1); // del() with wrong parameters

    add(root, 0x0A140000, 16); // 10.20.0.0/16
    assert(check(root, 0x0A140000) == 16U);

    add(root, 0x0A14FFFF, 24); // 10.20.0.0/24
    assert(check(root, 0x0A140000) == 16U);
    assert(check(root, 0x0A14FFFF) == 24U);

    del(root, 0x0A140000, 24); // 10.20.0.0/24
    assert(check(root, 0x0A140000) == 16U);

    del(root, 0x0A140000, 16); // 10.20.0.0/16
    assert(check(root, 0x0A140000) == -1);

    add(root, 0x20408000, 20); // 32.64.128.0/20
    assert(check(root, 0x20408FFA) == 20);

    printf("OK - all assertions passed.\n");
    freeTrie(root);
    return 0;
}