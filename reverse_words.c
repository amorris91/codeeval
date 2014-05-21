#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void parse_line(char *input) {
  printf("%s", input);
}

int main(int argc, char *argv[]) {
  int fd;
  int file_size;
  int i, j;
  int line_start, line_end;
  char *file_text;
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

  i = 0;
  line_start = i;
  for(i; i < file_size; ++i) {
    if(file_text[i] == '\n') {
      line_end = i;
      individual_line = malloc((line_end - line_start + 1) * sizeof(char));

      j = line_start;
      for(j; j <= line_end; ++j) {
        individual_line[j - line_start] = file_text[j];
      }
      individual_line[j] = '\0';

      if(i != file_size - 2) {
        parse_line(individual_line);
        free(individual_line);
        line_start = i + 1;
      }
    }
  }

  free(file_text);
  close(fd);
}
