#include <stdio.h>

int bitXor(int num1, int num2){
  //all 1s
  int all1s = num1 & num2;
  //all 0s
  int all0s = ~num1 & ~num2;
  //not all 1s
  int notAll1s = ~all1s;
  //not all 0s
  int notAll0s = ~all0s;
  //not all 0s and not all 1s
  return notAll0s & notAll1s;
}

int main(){
  int num1,num2;
  scanf("%d %d", &num1, &num2);
  int xor = bitXor(num1, num2);
  printf("%d\n", xor);
}
