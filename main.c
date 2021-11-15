#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** parse_args( char * line ) {
  char ** args = calloc(5, sizeof(char *));
  int i = 0;
  for (int i = 0; i < 5; i ++) {
    args[i] = strsep(&line, " ");
  }
  return args;
}


int main() {
  char line[100] = "ls -a -l";
  char ** args = parse_args(line);
  execvp(args[0], args);
  return 0;
}
