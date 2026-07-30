#include <stdio.h>

int getByte(int x, int n){

    x >>= (n << 3);
    x &= 255;

    return x;


}

int main(){
    int x,n;

    scanf("%d%d", &x,&n);

    printf("%d\n", getByte(x,n));
}