#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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
  int fd;
  int file_size;
  char *file_text;
  int i, j;
  int line_start, line_end;
  char *individual_line;

  if(argc == 1) {
    printf("No input provided\n");
    return 0;
  }
  fd = open(argv[1], O_RDONLY);
  if(!fd) {
    printf("Unable to open %s\n", argv[1]);
    return 0;
  }
  file_size = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, SEEK_SET);
  file_text = malloc(file_size * sizeof(char));
  read(fd, file_text, file_size);

  line_start = 0;
  for(i = 0; i < file_size; ++i) {
    if(file_text[i] == '\n') {
      line_end = i;
      individual_line = malloc(line_end - line_start + 2);
      for(j = line_start; j <= line_end; ++j) {
        individual_line[j - line_start] = file_text[j];
      }
      individual_line[j - line_start] = '\0';
      if(line_start != line_end) {
        printf("%d\n", fib(atoi(individual_line)));
      }
      free(individual_line);
      line_start = i + 1;
    }
  }

  free(file_text);
  close(fd);
}
