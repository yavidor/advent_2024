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

int getFileSize(const char *fileName) {
  FILE *fd = fopen(fileName, "r");
  int count = 0;
  while ((char)fgetc(fd) != EOF) {
    count++;
  }
  fclose(fd);
  return count;
}

int countChar(const char *source, const char target) {
  int count = 0;
  for (int i = 0; i < strlen(source); i++) {
    if (source[i] == target) {
      count++;
    }
  }
  return count;
}

char **getLines(const bool isRealInput, const int day) {
  char *fileType;
  if (isRealInput) {
    fileType = "input.txt";
  } else {
    fileType = "example.txt";
  }
  char fileName[20];
  sprintf(fileName, "day%d\\%s", day, fileType);
  FILE *fd = fopen(fileName, "r");
  char cwd[100];
  _getcwd(cwd, sizeof(cwd));
  const int fileSize = getFileSize(fileName);
  char **buf = malloc(fileSize * sizeof(char));
  char *tempBuf = malloc(fileSize * sizeof(char));
  fclose(fd);
  return buf;
}