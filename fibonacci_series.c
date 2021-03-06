#include <stdio.h>

int fib(int val) {
  int curr, prev;
  int i;
  curr = 0;
  prev = 1;
  for(i = 0; i < val; ++i) {
    curr = curr + prev;
    prev = curr - prev;
  }
  return curr;
}

int main(int argc, char *argv[]) {
  int val;
  FILE *fp;

  if(argc == 1) {
    printf("No input provided\n");
    return 0;
  }
  fp = fopen(argv[1], "r");
  if(fp == NULL) {
    printf("Unable to open %s\n", argv[1]);
    return 0;
  }
  while(!feof(fp)) {
    if(fscanf(fp, "%d", &val) != 1) {
      break;
    }
    printf("%d\n", fib(val));
  }
  fclose(fp);
  return 0;
}
