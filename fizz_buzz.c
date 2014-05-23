#include <stdio.h>

void fb(int first, int second, int range) {
  int i;
  for(i = 1; i <= range; i++) {
    if(i % first == 0 && i % second == 0) {
      printf("FB");
    }
    else if(i % first == 0) {
      printf("F");
    }
    else if(i % second == 0) {
      printf("B");
    }
    else {
      printf("%d", i);
    }

    if(i < range) {
      printf(" ");
    }
    else {
      printf("\n");
    }
  }
}

int main(int argc, char *argv[]) {
  int arg1, arg2, arg3;
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
    fscanf(fp, "%d", &arg1);
    fscanf(fp, "%d", &arg2);
    if(fscanf(fp, "%d", &arg3) != 1) {
      break;
    }
    fb(arg1, arg2, arg3);
  }
  fclose(fp);
}
