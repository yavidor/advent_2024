#include "main.h"
#include "utils.h"
#include <stdio.h>

int main(void) {
  printf("Hello world\n");
  char **buf = getLines(false, 1);
  printf("%s", buf[1]);
  return 0;
}