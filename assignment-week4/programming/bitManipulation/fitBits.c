#include <stdio.h>

int fitBits(int x, int n){
  				
  int shiftUnshift = (x << (32 - n)) >> (32 + (~n + 1));
  return !(x ^  shiftUnshift);


}

int main(){

  int n,x;
  scanf("%d %d" , &x ,&n);
  int possible =  fitBits(x, n);
  printf("%d" , possible);

}
