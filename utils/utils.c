#include "utils.h"
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>

long int findSize(char fileName[]) {
  FILE *fd = fopen(fileName, "r");
  fseek(fd, 0L, SEEK_END);
  const long int res = ftell(fd);
  fclose(fd);
  return res;
}
/*
*{
var fileName string
if useRealInput {
fileName = "input"
} else {
fileName = "example"
}
file_data, err := fs.ReadFile(os.DirFS(".."), fmt.Sprintf("%s.txt", fileName))
if err != nil {
panic(err)
}
var lines []string = strings.Split(string(file_data), "\n")
return lines

}*/
char **getLines(bool isRealInput, int day) {
  char *fileType;
  if (isRealInput) {
    fileType = "input.txt";
  } else {
    fileType = "example.txt";
  }
  char fileName[20];
  sprintf(fileName, "day%d\\%s", day, fileType);
  printf("%s\n",fileName);
  FILE *fd = fopen(fileName, "r");
  char cwd[100];
  _getcwd(cwd, sizeof(cwd));
  printf("+%s\n", cwd);
  char buffer[100];
  char *a = fgets(buffer, sizeof(buffer), fd);
  printf("*%s\n", a);
  char **buf = malloc(5 * sizeof(char *));
  if (!buf) {
    return NULL;
  }
  buf[0] = buffer;
  return buf;
}