#include <stdio.h>

int bitAnd(int x , int y){
  int xComplement = ~x;
  int yComplement = ~y;
  return ~(xComplement | yComplement);
}
int main(){
  int num1, num2;
  scanf("%d %d", &num1, &num2); 
  int and = bitAnd(num1, num2);
  printf("%d\n" , and);
}
