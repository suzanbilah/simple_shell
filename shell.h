#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#define MAX_INPUT_SIZE 1024

void execute_com(char *com, int back);

/**
char *findpath(void);
int handle_builtin(void);
int arraycopy(char *dest[], char *src[]);
int execute_command(void);
int printarr(char *array[]);
char *_getenviron(char *);
void free_arr(char **array);
int _fputint(int fc, int numb);
int _fputchar(int fc, char c);
int _fputstring(int fc, char *str);
int _fprintf(int fc, const char *format, char *str1, int n, char *str2);
*/
#endif
