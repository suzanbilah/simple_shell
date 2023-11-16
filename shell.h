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
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100
#define MAX_ALIASES 50

extern char *alias_name[MAX_ALIASES];
extern char *alias_values[MAX_ALIASES];
extern int alias_count;

void execute_com(char **com, int back);
int token_input(char *input, char **token);
int background_check(char **token, int *token_count);
void free_token(char **token);
int handle_builtin(char **token);
void print_environ(void);
void set_environ_var(const char *variable, const char *value);
void unset_environ_var(const char *variable);
void change_dir(char *directory);
void handle_alias(char **token);
void print_aliases(void);
void print_specified_aliases(char **alias_name);
void define_aliases(char **alias_definitions);
int is_alias(const char *alias_name);
int find_alias_index(const char *alias_name);
int execute_single_com(char **token, int back);
void display_prompt(void);

#endif
