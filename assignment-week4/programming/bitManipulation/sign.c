#include <stdio.h>


int sign(int num){
    return (num >> 31) | !!num;
}

int main(){


    int num;
    scanf("%d", &num);
    printf("%d\n", sign(num));

}