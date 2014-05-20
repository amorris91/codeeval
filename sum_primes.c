#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int is_prime(int val) {
  int i;
  for(i = 2; i < val; ++i) {
    if(val % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int sum = 0;
  int i; /* prime index */
  int j; /* generic index */
  
  i = 0;
  j = 2;
  while(i < 1000) {
    if(is_prime(j)) {
      ++i;
      sum += j;
    }
    ++j;
  }
  printf("%d\n", sum);
}
