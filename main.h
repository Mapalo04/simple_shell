#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_SIZE 128
extern char **environ;

/*Function*/
ssize_t custom_getline(char *cmd, size_t max_size);
void _execute(char *argc);
char *cust_strtok(char *command, const char *del);
int _strncmp(const char *str1, const char *str2, size_t n);
const char* _strchr(const char *s, int ch);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
char *get_path(char *cmd);
char *get_full_path(const char *command);
char *my_getenv(const char *nm);
void exec_command(char *cmd);
char *_strcat(char *dest, char *src);


#endif
