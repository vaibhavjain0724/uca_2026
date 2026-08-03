#include <stdio.h>

int conditional(int x, int y, int z) {

    int mask = (!!x << 31) >> 31;

    return (mask & y) | (~mask & z);
}

int main() {
    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);

    printf("%d\n", conditional(x, y, z));

    return 0;
}