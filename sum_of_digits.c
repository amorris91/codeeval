#include <stdio.h>

int sum_digits(int val) {
  int sum = 0;
  while(val != 0) {
    sum += val % 10;
    val /= 10;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  FILE *fp;
  int val;
  if(argc == 1) {
    printf("No input provided\n");
    return 0;
  }
  fp = fopen(argv[1], "r");
  if(fp == NULL) {
    printf("Unable to open %s\n", argv[1]);
    return 0;
  }
  fscanf(fp, "%d", &val);
  while(!feof(fp)) {
    printf("%d\n", sum_digits(val));
    fscanf(fp, "%d", &val);
  }
  fclose(fp);
}
