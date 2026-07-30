#include <stdio.h>


int bang(int x){

    //x & -1 | (-x) & -1 == (0 if x = 0  ) and (-x if x != 0)
    // >> 31 makes the num -1 if its not equal to 0
    // +1 makes -1 0 and 0 1;

    return ((((x | (~x+1) & (~0)) ) >> 31)) + 1;
}

int main(){
    int x;
    scanf("%d",&x );
    printf("%d", bang(x));
 }