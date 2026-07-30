#include <stdio.h>
// #include <limits.h>

int logicalShift(int x, int n){


    int mask =  (~0) << (32 -n);
    mask= ~mask;


    x >>= n;
    x &= mask;

    return x;


}

int main(){
    int x,n;
    scanf("%d%d", &x,&n);
    printf("%d",logicalShift(x,n));
}