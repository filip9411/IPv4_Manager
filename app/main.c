#include <stdio.h>
#include <assert.h>

#include "ip_manager.h"

int main()
{   
    ip_container *root = initContainer();

    add(root, 0x0A140000, 16); // 10.20.0.0/16
    add(root, 0x0A140000, 18); // 10.20.0.0/16
    add(root, 0x20408000, 20); // 32.64.128.0/20

    printf("Check 10.20.0.0: %d\n", check(root, 0x0A140000));
    printf("Check 10.20.1.1: %d\n", check(root, 0x0A140101));
    printf("Check 32.64.128.0: %d\n", check(root, 0x20408000));
    printf("Check 32.64.144.0: %d\n", check(root, 0x20409000));
    printf("Check 192.168.1.1: %d\n", check(root, 0xC0A80101));

    del(root, 0x0A140000, 16);
    del(root, 0x0A140000, 18);

    printf("Check 10.20.0.0: %d\n", check(root, 0x0A140000));


    assert(true);
    printf("OK - all assertions passed.\n");
    freeTrie(root);
    return 0;
}