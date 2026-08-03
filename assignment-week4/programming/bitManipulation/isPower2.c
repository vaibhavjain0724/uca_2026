#include <stdio.h>

int isPower2(int x) {
    return !!x & !(x >> 31) & !(x & (x + ~0));
}

int main(){
    int x;
    scanf("%d" , &x);

    printf("%d\n", isPower2(x));
}