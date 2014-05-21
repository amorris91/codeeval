#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

void parse_line(char *input) {
  char *arg_string;
  int arg_start, arg_end;
  int arg1, arg2, arg3;
  int i, j;

  i = 0;
  /* printf("%s", input); */
  while(input[i] == ' ') {
    ++i;
  }
  arg_start = i;
  while(input[i] != ' ') {
    ++i;
  }
  arg_end = i;
  arg_string = malloc((arg_end - arg_start + 1) * sizeof(char));
  for(j = arg_start; j <= arg_end; ++j) {
    arg_string[j - arg_start] = input[j];
  }
  arg_string[j] = '\0';
  arg1 = atoi(arg_string);
  free(arg_string);

  while(input[i] == ' ') {
    ++i;
  }
  arg_start = i;
  while(input[i] != ' ') {
    ++i;
  }
  arg_end = i;
  arg_string = malloc((arg_end - arg_start + 1) * sizeof(char));
  for(j = arg_start; j <= arg_end; ++j) {
    arg_string[j - arg_start] = input[j];
  }
  arg_string[j] = '\0';
  arg2 = atoi(arg_string);
  free(arg_string);

  while(input[i] == ' ') {
    ++i;
  }
  arg_start = i;
  while(input[i] != ' ' && input[i] != '\n' && input[i] != '\0') {
    ++i;
  }
  arg_end = i;
  arg_string = malloc((arg_end - arg_start + 1) * sizeof(char));
  for(j = arg_start; j <= arg_end; ++j) {
    arg_string[j - arg_start] = input[j];
  }
  arg_string[j] = '\0';
  arg3 = atoi(arg_string);
  free(arg_string);

  fb(arg1, arg2, arg3);
}

int main(int argc, char *argv[]) {
  int fd;
  int file_size;
  char *file_text;
  int i, j;
  int line_start, line_end;  
  char *individual_line;

  /* opening input file */
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
      parse_line(individual_line);
      free(individual_line);
      line_start = i + 1;
    }
  }

  free(file_text);
  close(fd);
}
