#include <stdio.h>
#include <string.h>
#include <math.h>

int is_prime(int val) {
  int i;
  for(i = 2; i <= sqrt(val); ++i) {
    if(val % i == 0) {
      return 0;
    }
  }
  return 1;
}

int is_palindrome(int val) {
  char buf[4];
  int len;
  int i;
  snprintf(buf, 4, "%d", val);
  len = strlen(buf);
  for(i = 0; i < len; ++i) {
    if(buf[i] != buf[len - 1 - i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int i;
  int max;
  for(i = 2; i < 1000; ++i) {
    if(is_prime(i) && is_palindrome(i)) {
      max = i;
    }
  }
  printf("%d\n", max);
}
