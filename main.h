#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>

extern char **environ;
#define EXIT "exit"
#define ENTER "\n"
#define SPACE " \n "
#define BUFF_SIZE 1024

/* FUNCTIONS */
void _execve(char *cmd, char **args, char **env, char *name);
char **create_av(char *line);
char *_getenv(const char *name);
int check_cmd(char **av);
void _perror(char *message, char *name, char **av);
void myexit(char *st, char *name, char **av);
void *_get_line(void);
char *_get_input(void);
void _free_last_input(void);
void _puts(char *str);
void prompt(void);
int _check_char(char s, const char *_string)
char *_strtok(char *_string, const char *delim)

/* HELPERS */
int _strlen(const char *str);
void _strcpy(char *dest, const char *src);
void _strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
void _perror(char *message, char *name, char **av);
void pnum(int n);
int _atoi(const char *_string);

/* SIGNAL HANDLERS */
void sigHandler(int sig);

#endif
