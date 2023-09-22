#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define BUF_SIZE 1024

/*extern char **environ;*/

void execmd(char **argv);
char *get_path(char *cmd);
/*char *_strdup(char *s);
char *my_getenv(const char *nm);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
const char* _strchr(const char *s, int ch);
void custom_eof(char **buf, ssize_t val);
void builtin_cd(char **arg);
void builtin_env(char **arg);
void unsetenv_builtin(char **arg);
void setenv_builtin(char **arg);*/
int path_form(char *lineptr, char *token, ssize_t nreadch);
/*void builtin_exit(char **arg);
char *cust_strtok(char *string, const char *delimiters);
int _printf(char *str);*/

#endif
